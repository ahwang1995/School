#include "RiftManagerApp.h"
#include <iostream>
#include <math.h>
#include "shader.h"
#include "screen.h"
#include "lines.h"
using namespace std;
const char* window_title = "Carbon Dioxide Removal Trainer";
namespace glfw {
	inline GLFWwindow * createWindow(const uvec2 & size, const ivec2 & position = ivec2(INT_MIN)) {
		GLFWwindow * window = glfwCreateWindow(size.x, size.y, window_title, nullptr, nullptr);
		if (!window) {
			FAIL("Unable to create rendering window");
		}
		if ((position.x > INT_MIN) && (position.y > INT_MIN)) {
			glfwSetWindowPos(window, position.x, position.y);
		}
		return window;
	}
}

class RiftApp : public GlfwApp, public RiftManagerApp {

public:
	enum render_states {
		STEREO,
		MONO,
		LEFT_ONLY,
		RIGHT_ONLY
	};
	enum view_state {
		HEAD,
		RIGHT,
		LEFT
	};
	enum freeze_state {
		TRACK,
		FREEZE
	};
	enum wire_frame {
		ON,
		OFF
	};
	int render_state = STEREO;
	int view_state = HEAD;
	int freeze_state = TRACK;
	int wire_frame = OFF;
	float eye_offset_default[2], eye_offset[2];

	RiftApp() {
		using namespace ovr;
		_viewScaleDesc.HmdSpaceToWorldScaleInMeters = 1.0f;

		memset(&_sceneLayer, 0, sizeof(ovrLayerEyeFov));
		_sceneLayer.Header.Type = ovrLayerType_EyeFov;
		_sceneLayer.Header.Flags = ovrLayerFlag_TextureOriginAtBottomLeft;

		ovr::for_each_eye([&](ovrEyeType eye) {
			ovrEyeRenderDesc& erd = _eyeRenderDescs[eye] = ovr_GetRenderDesc(_session, eye, _hmdDesc.DefaultEyeFov[eye]);
			ovrMatrix4f ovrPerspectiveProjection =
				ovrMatrix4f_Projection(erd.Fov, 0.01f, 1000.0f, ovrProjection_ClipRangeOpenGL);
			_eyeProjections[eye] = ovr::toGlm(ovrPerspectiveProjection);
			_viewScaleDesc.HmdToEyeOffset[eye] = erd.HmdToEyeOffset; // cse190: adjust the eye separation here - need to use 3D vector from central point on Rift for each eye

			eye_offset_default[eye] = erd.HmdToEyeOffset.x; //TEST DIS
			eye_offset[eye] = eye_offset_default[eye];

			ovrFovPort & fov = _sceneLayer.Fov[eye] = _eyeRenderDescs[eye].Fov;
			auto eyeSize = ovr_GetFovTextureSize(_session, eye, fov, 1.0f);
			_sceneLayer.Viewport[eye].Size = eyeSize;
			_sceneLayer.Viewport[eye].Pos = { (int)_renderTargetSize.x, 0 };

			_renderTargetSize.y = std::max(_renderTargetSize.y, (uint32_t)eyeSize.h);
			_renderTargetSize.x += eyeSize.w;
		});
		// Make the on screen window 1/4 the resolution of the render target
		_mirrorSize = _renderTargetSize;
		_mirrorSize /= 2;
	}

protected:
	GLuint _fbo{ 0 };
	GLuint _depthBuffer{ 0 };
	ovrTextureSwapChain _eyeTexture;

	GLuint _mirrorFbo{ 0 };
	ovrMirrorTexture _mirrorTexture;

	ovrEyeRenderDesc _eyeRenderDescs[2];

	mat4 _eyeProjections[2];

	ovrLayerEyeFov _sceneLayer;
	ovrViewScaleDesc _viewScaleDesc;

	uvec2 _renderTargetSize;
	uvec2 _mirrorSize;
	ovrTrackingState trackState;
	ovrPosef         handPoses[2];
	ovrInputState    inputState;
	glm::mat4 P[2][3];
	glm::mat4 currPose[2][3];
	GLFWwindow * createRenderingTarget(uvec2 & outSize, ivec2 & outPosition) override {
		return glfw::createWindow(_mirrorSize);
	}

	// Properties
	GLuint screenWidth = 1000, screenHeight = 1000, framebuffer[3], textureColorbuffer[3], rbo[3];

	Screen *screen_left, *screen_right, *screen_floor;
	lines *wires_left, *wires_right, *wires_floor;
	vector<Screen*> screens;

	void initGl() override {
		GlfwApp::initGl();

		// Disable the v-sync for buffer swap
		glfwSwapInterval(0);

		ovrTextureSwapChainDesc desc = {};
		desc.Type = ovrTexture_2D;
		desc.ArraySize = 1;
		desc.Width = _renderTargetSize.x;
		desc.Height = _renderTargetSize.y;
		desc.MipLevels = 1;
		desc.Format = OVR_FORMAT_R8G8B8A8_UNORM_SRGB;
		desc.SampleCount = 1;
		desc.StaticImage = ovrFalse;
		ovrResult result = ovr_CreateTextureSwapChainGL(_session, &desc, &_eyeTexture);
		_sceneLayer.ColorTexture[0] = _eyeTexture;
		if (!OVR_SUCCESS(result)) {
			FAIL("Failed to create swap textures");
		}

		int length = 0;
		result = ovr_GetTextureSwapChainLength(_session, _eyeTexture, &length);
		if (!OVR_SUCCESS(result) || !length) {
			FAIL("Unable to count swap chain textures");
		}
		for (int i = 0; i < length; ++i) {
			GLuint chainTexId;
			ovr_GetTextureSwapChainBufferGL(_session, _eyeTexture, i, &chainTexId);
			glBindTexture(GL_TEXTURE_2D, chainTexId);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		}
		glBindTexture(GL_TEXTURE_2D, 0);

		// Set up the framebuffer object
		glGenFramebuffers(1, &_fbo);
		glGenRenderbuffers(1, &_depthBuffer);
		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, _fbo);
		glBindRenderbuffer(GL_RENDERBUFFER, _depthBuffer);
		glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, _renderTargetSize.x, _renderTargetSize.y);
		glBindRenderbuffer(GL_RENDERBUFFER, 0);
		glFramebufferRenderbuffer(GL_DRAW_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, _depthBuffer);
		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);

		ovrMirrorTextureDesc mirrorDesc;
		memset(&mirrorDesc, 0, sizeof(mirrorDesc));
		mirrorDesc.Format = OVR_FORMAT_R8G8B8A8_UNORM_SRGB;
		mirrorDesc.Width = _mirrorSize.x;
		mirrorDesc.Height = _mirrorSize.y;
		if (!OVR_SUCCESS(ovr_CreateMirrorTextureGL(_session, &mirrorDesc, &_mirrorTexture))) {
			FAIL("Could not create mirror texture");
		}
		glGenFramebuffers(1, &_mirrorFbo);

		for (int i = 0; i < 3; i++) {
			// Framebuffers
			glGenFramebuffers(1, &framebuffer[i]);
			glBindFramebuffer(GL_FRAMEBUFFER, framebuffer[i]);
			// Create a color attachment texture
			textureColorbuffer[i] = generateAttachmentTexture(false, false);
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, textureColorbuffer[i], 0);

			// Create a renderbuffer object for depth and stencil attachment (we won't be sampling these)
			glGenRenderbuffers(1, &rbo[i]);
			glBindRenderbuffer(GL_RENDERBUFFER, rbo[i]);
			glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, screenWidth, screenHeight); // Use a single renderbuffer object for both a depth AND stencil buffer.
			glBindRenderbuffer(GL_RENDERBUFFER, 0);
			glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo[i]); // Now actually attach it
																										  // Now that we actually created the framebuffer and added all attachments we want to check if it is actually complete now																						  // Now that we actually created the framebuffer and added all attachments we want to check if it is actually complete now
		}

		// MADE The SCREENS
		/*screen_left = new Screen(glm::vec3(-sqrt(pow(1.2, 2) / 2), 0.0f, 0.0f), glm::vec3(0, deg2rad(45.0f), 0), glm::vec3(2.4f, 2.4f, 1.0f));
		screen_right = new Screen(glm::vec3(sqrt(pow(1.2, 2) / 2), 0.0f, 0.0f), glm::vec3(0, -deg2rad(45.0f), 0), glm::vec3(2.4f, 2.4f, 1.0f));
		screen_floor = new Screen(glm::vec3(0.0f, -1.2f, sqrt(pow(1.2, 2) / 2)), glm::vec3(deg2rad(-90.0f), deg2rad(45.0f), 0), glm::vec3(2.4f, 2.4f, 1.0f));*/

		screen_left = new Screen(glm::vec3(-sqrt(pow(1.2, 2) / 2), 0.0f, -4.0f + 0.0f), glm::vec3(0, deg2rad(45.0f), 0), glm::vec3(2.4f, 2.4f, 1.0f));
		screen_right = new Screen(glm::vec3(sqrt(pow(1.2, 2) / 2), 0.0f, -4.0f + 0.0f), glm::vec3(0, -deg2rad(45.0f), 0), glm::vec3(2.4f, 2.4f, 1.0f));
		screen_floor = new Screen(glm::vec3(0.0f, -1.2f, -4.0f + sqrt(pow(1.2, 2) / 2)), glm::vec3(deg2rad(-90.0f), deg2rad(45.0f), 0), glm::vec3(2.4f, 2.4f, 1.0f));

		wires_left = new lines();
		wires_right = new lines();
		wires_floor = new lines();

		screens.push_back(screen_left);
		screens.push_back(screen_right);
		screens.push_back(screen_floor);
	}

	void onKey(int key, int scancode, int action, int mods) override {
		if (GLFW_PRESS == action) switch (key) {
		case GLFW_KEY_R:
			ovr_RecenterTrackingOrigin(_session);
			return;
		}

		GlfwApp::onKey(key, scancode, action, mods);
	}

	void draw() final override {
		// Left controller
		glm::mat4 LHview = ovr::toGlm(trackState.HandPoses[ovrHand_Left].ThePose);
		// Right controller
		glm::mat4 RHview = ovr::toGlm(trackState.HandPoses[ovrHand_Right].ThePose);

		// Draw as wireframe
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		ovrPosef eyePoses[2];
		ovr_GetEyePoses(_session, frame, true, _viewScaleDesc.HmdToEyeOffset, eyePoses, &_sceneLayer.SensorSampleTime);

		int curIndex;
		ovr_GetTextureSwapChainCurrentIndex(_session, _eyeTexture, &curIndex);
		GLuint curTexId;
		ovr_GetTextureSwapChainBufferGL(_session, _eyeTexture, curIndex, &curTexId);

		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, _fbo);
		glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, curTexId, 0);
		glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		ovr::for_each_eye([&](ovrEyeType eye) {
			for (int i = 0; i < 3; i++) {
				glBindFramebuffer(GL_FRAMEBUFFER, framebuffer[i]);

				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				glViewport(0, 0, screenWidth, screenHeight);
				glm::vec4 eyeoffset = glm::vec4(0.00325f, 0.0f, 0.0f,0.0f);
				switch (view_state) {
				case HEAD:
					if (freeze_state == TRACK) {
						P[eye][i] = screens[i]->getP(ovr::toGlm(eyePoses[eye])[3]);
						currPose[eye][i] = ovr::toGlm(eyePoses[eye]);
					}
					renderScene(P[eye][i], currPose[eye][i], eye);
					//Misc::printMat(currPose[eye][i]);
					break;
				case RIGHT:
					if (freeze_state == TRACK) {
						if (eye == ovrEye_Left) {
							P[eye][i] = screens[i]->getP(RHview[3] - eyeoffset);
							currPose[eye][i] = RHview;
						}
						else if (eye == ovrEye_Right) {
							P[eye][i] = screens[i]->getP(RHview[3] + eyeoffset);
							currPose[eye][i] = RHview;
						}
					}
					//Misc::printMat(currPose[eye][i]);
					renderScene(P[eye][i], currPose[eye][i], eye);
					break;
				case LEFT:
					if (freeze_state == TRACK) {
						if (eye == ovrEye_Left) P[eye][i] = screens[i]->getP((LHview[3] - eyeoffset));
						else P[eye][i] = screens[i]->getP((LHview[3] + eyeoffset));
						currPose[eye][i] = LHview;
					}
					renderScene(P[eye][i], currPose[eye][i], eye);
					break;
				}
			}

			glBindFramebuffer(GL_DRAW_FRAMEBUFFER, _fbo);
			glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, curTexId, 0);

			const auto& vp = _sceneLayer.Viewport[eye];
			glViewport(vp.Pos.x, vp.Pos.y, vp.Size.w, vp.Size.h);
			_sceneLayer.RenderPose[eye] = eyePoses[eye];

			// Draw Screen
			screens[0]->draw(_eyeProjections[eye], glm::inverse(ovr::toGlm(eyePoses[eye])), textureColorbuffer[0]);
			screens[1]->draw(_eyeProjections[eye], glm::inverse(ovr::toGlm(eyePoses[eye])), textureColorbuffer[1]);
			screens[2]->draw(_eyeProjections[eye], glm::inverse(ovr::toGlm(eyePoses[eye])), textureColorbuffer[2]);


			if (wire_frame == ON) {
				wires_left->draw(_eyeProjections[eye], glm::inverse(ovr::toGlm(eyePoses[eye])), eye,screen_left->lineVerts);
				wires_right->draw(_eyeProjections[eye], glm::inverse(ovr::toGlm(eyePoses[eye])), eye, screen_right->lineVerts);
				wires_floor->draw(_eyeProjections[eye], glm::inverse(ovr::toGlm(eyePoses[eye])), eye, screen_floor->lineVerts);

			}
		});

		glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, 0, 0);
		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
		ovr_CommitTextureSwapChain(_session, _eyeTexture);
		ovrLayerHeader* headerList = &_sceneLayer.Header;
		ovr_SubmitFrame(_session, frame, &_viewScaleDesc, &headerList, 1);

		GLuint mirrorTextureId;
		ovr_GetMirrorTextureBufferGL(_session, _mirrorTexture, &mirrorTextureId);
		glBindFramebuffer(GL_READ_FRAMEBUFFER, _mirrorFbo);
		glFramebufferTexture2D(GL_READ_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, mirrorTextureId, 0);
		glBlitFramebuffer(0, 0, _mirrorSize.x, _mirrorSize.y, 0, _mirrorSize.y, _mirrorSize.x, 0, GL_COLOR_BUFFER_BIT, GL_NEAREST);
		glBindFramebuffer(GL_READ_FRAMEBUFFER, 0);

	}

	float deg2rad(float deg) {
		return deg * 3.141592653589793 / 180.0;
	}

	virtual void renderScene(const glm::mat4 & projection, const glm::mat4 & headPose, ovrEyeType eye) = 0;

	// Generates a texture that is suited for attachments to a framebuffer
	GLuint generateAttachmentTexture(GLboolean depth, GLboolean stencil)
	{
		// What enum to use?
		GLenum attachment_type;
		if (!depth && !stencil)
			attachment_type = GL_RGB;
		else if (depth && !stencil)
			attachment_type = GL_DEPTH_COMPONENT;
		else if (!depth && stencil)
			attachment_type = GL_STENCIL_INDEX;

		//Generate texture ID and load texture data 
		GLuint textureID;
		glGenTextures(1, &textureID);
		glBindTexture(GL_TEXTURE_2D, textureID);
		if (!depth && !stencil)
			glTexImage2D(GL_TEXTURE_2D, 0, attachment_type, screenWidth, screenHeight, 0, attachment_type, GL_UNSIGNED_BYTE, NULL);
		else // Using both a stencil and depth test, needs special format arguments
			glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH24_STENCIL8, screenWidth, screenHeight, 0, GL_DEPTH_STENCIL, GL_UNSIGNED_INT_24_8, NULL);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glBindTexture(GL_TEXTURE_2D, 0);

		return textureID;
	}
};