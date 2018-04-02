/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x8ef4fb42 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/Users/Andrew/Desktop/School/Computer Science/CS140L/Lab4/Mux8to1.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {1U, 0U};



static void Always_26_0(char *t0)
{
    char t6[8];
    char t15[8];
    char t31[8];
    char t45[8];
    char t54[8];
    char t70[8];
    char t78[8];
    char t110[8];
    char t124[8];
    char t133[8];
    char t149[8];
    char t157[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    char *t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    char *t38;
    char *t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    char *t43;
    char *t44;
    char *t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    char *t53;
    char *t55;
    char *t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    char *t69;
    char *t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    char *t77;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    char *t82;
    char *t83;
    char *t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    char *t92;
    char *t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    unsigned int t99;
    unsigned int t100;
    unsigned int t101;
    int t102;
    int t103;
    unsigned int t104;
    unsigned int t105;
    unsigned int t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    char *t111;
    unsigned int t112;
    unsigned int t113;
    unsigned int t114;
    unsigned int t115;
    unsigned int t116;
    char *t117;
    char *t118;
    unsigned int t119;
    unsigned int t120;
    unsigned int t121;
    char *t122;
    char *t123;
    char *t125;
    unsigned int t126;
    unsigned int t127;
    unsigned int t128;
    unsigned int t129;
    unsigned int t130;
    unsigned int t131;
    char *t132;
    char *t134;
    char *t135;
    unsigned int t136;
    unsigned int t137;
    unsigned int t138;
    unsigned int t139;
    unsigned int t140;
    unsigned int t141;
    unsigned int t142;
    unsigned int t143;
    unsigned int t144;
    unsigned int t145;
    unsigned int t146;
    unsigned int t147;
    char *t148;
    char *t150;
    unsigned int t151;
    unsigned int t152;
    unsigned int t153;
    unsigned int t154;
    unsigned int t155;
    char *t156;
    unsigned int t158;
    unsigned int t159;
    unsigned int t160;
    char *t161;
    char *t162;
    char *t163;
    unsigned int t164;
    unsigned int t165;
    unsigned int t166;
    unsigned int t167;
    unsigned int t168;
    unsigned int t169;
    unsigned int t170;
    char *t171;
    char *t172;
    unsigned int t173;
    unsigned int t174;
    unsigned int t175;
    unsigned int t176;
    unsigned int t177;
    unsigned int t178;
    unsigned int t179;
    unsigned int t180;
    int t181;
    int t182;
    unsigned int t183;
    unsigned int t184;
    unsigned int t185;
    unsigned int t186;
    unsigned int t187;
    unsigned int t188;
    char *t189;
    unsigned int t190;
    unsigned int t191;
    unsigned int t192;
    unsigned int t193;
    unsigned int t194;
    char *t195;
    char *t196;

LAB0:    t1 = (t0 + 2088U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(26, ng0);
    t2 = (t0 + 2284);
    *((int *)t2) = 1;
    t3 = (t0 + 2116);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(27, ng0);

LAB5:    xsi_set_current_line(28, ng0);
    t4 = (t0 + 1336U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    t4 = (t6 + 4);
    t7 = (t5 + 4);
    t8 = *((unsigned int *)t5);
    t9 = (t8 >> 0);
    t10 = (t9 & 1);
    *((unsigned int *)t6) = t10;
    t11 = *((unsigned int *)t7);
    t12 = (t11 >> 0);
    t13 = (t12 & 1);
    *((unsigned int *)t4) = t13;
    t14 = ((char*)((ng1)));
    memset(t15, 0, 8);
    t16 = (t6 + 4);
    t17 = (t14 + 4);
    t18 = *((unsigned int *)t6);
    t19 = *((unsigned int *)t14);
    t20 = (t18 ^ t19);
    t21 = *((unsigned int *)t16);
    t22 = *((unsigned int *)t17);
    t23 = (t21 ^ t22);
    t24 = (t20 | t23);
    t25 = *((unsigned int *)t16);
    t26 = *((unsigned int *)t17);
    t27 = (t25 | t26);
    t28 = (~(t27));
    t29 = (t24 & t28);
    if (t29 != 0)
        goto LAB9;

LAB6:    if (t27 != 0)
        goto LAB8;

LAB7:    *((unsigned int *)t15) = 1;

LAB9:    memset(t31, 0, 8);
    t32 = (t15 + 4);
    t33 = *((unsigned int *)t32);
    t34 = (~(t33));
    t35 = *((unsigned int *)t15);
    t36 = (t35 & t34);
    t37 = (t36 & 1U);
    if (t37 != 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t32) != 0)
        goto LAB12;

LAB13:    t39 = (t31 + 4);
    t40 = *((unsigned int *)t31);
    t41 = *((unsigned int *)t39);
    t42 = (t40 || t41);
    if (t42 > 0)
        goto LAB14;

LAB15:    memcpy(t78, t31, 8);

LAB16:    memset(t110, 0, 8);
    t111 = (t78 + 4);
    t112 = *((unsigned int *)t111);
    t113 = (~(t112));
    t114 = *((unsigned int *)t78);
    t115 = (t114 & t113);
    t116 = (t115 & 1U);
    if (t116 != 0)
        goto LAB28;

LAB29:    if (*((unsigned int *)t111) != 0)
        goto LAB30;

LAB31:    t118 = (t110 + 4);
    t119 = *((unsigned int *)t110);
    t120 = *((unsigned int *)t118);
    t121 = (t119 || t120);
    if (t121 > 0)
        goto LAB32;

LAB33:    memcpy(t157, t110, 8);

LAB34:    t189 = (t157 + 4);
    t190 = *((unsigned int *)t189);
    t191 = (~(t190));
    t192 = *((unsigned int *)t157);
    t193 = (t192 & t191);
    t194 = (t193 != 0);
    if (t194 > 0)
        goto LAB46;

LAB47:    xsi_set_current_line(30, ng0);
    t2 = (t0 + 1336U);
    t3 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t6 + 4);
    t4 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 0);
    t10 = (t9 & 1);
    *((unsigned int *)t6) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 0);
    t13 = (t12 & 1);
    *((unsigned int *)t2) = t13;
    t5 = ((char*)((ng1)));
    memset(t15, 0, 8);
    t7 = (t6 + 4);
    t14 = (t5 + 4);
    t18 = *((unsigned int *)t6);
    t19 = *((unsigned int *)t5);
    t20 = (t18 ^ t19);
    t21 = *((unsigned int *)t7);
    t22 = *((unsigned int *)t14);
    t23 = (t21 ^ t22);
    t24 = (t20 | t23);
    t25 = *((unsigned int *)t7);
    t26 = *((unsigned int *)t14);
    t27 = (t25 | t26);
    t28 = (~(t27));
    t29 = (t24 & t28);
    if (t29 != 0)
        goto LAB52;

LAB49:    if (t27 != 0)
        goto LAB51;

LAB50:    *((unsigned int *)t15) = 1;

LAB52:    memset(t31, 0, 8);
    t17 = (t15 + 4);
    t33 = *((unsigned int *)t17);
    t34 = (~(t33));
    t35 = *((unsigned int *)t15);
    t36 = (t35 & t34);
    t37 = (t36 & 1U);
    if (t37 != 0)
        goto LAB53;

LAB54:    if (*((unsigned int *)t17) != 0)
        goto LAB55;

LAB56:    t32 = (t31 + 4);
    t40 = *((unsigned int *)t31);
    t41 = *((unsigned int *)t32);
    t42 = (t40 || t41);
    if (t42 > 0)
        goto LAB57;

LAB58:    memcpy(t78, t31, 8);

LAB59:    memset(t110, 0, 8);
    t92 = (t78 + 4);
    t112 = *((unsigned int *)t92);
    t113 = (~(t112));
    t114 = *((unsigned int *)t78);
    t115 = (t114 & t113);
    t116 = (t115 & 1U);
    if (t116 != 0)
        goto LAB71;

LAB72:    if (*((unsigned int *)t92) != 0)
        goto LAB73;

LAB74:    t111 = (t110 + 4);
    t119 = *((unsigned int *)t110);
    t120 = *((unsigned int *)t111);
    t121 = (t119 || t120);
    if (t121 > 0)
        goto LAB75;

LAB76:    memcpy(t157, t110, 8);

LAB77:    t171 = (t157 + 4);
    t190 = *((unsigned int *)t171);
    t191 = (~(t190));
    t192 = *((unsigned int *)t157);
    t193 = (t192 & t191);
    t194 = (t193 != 0);
    if (t194 > 0)
        goto LAB89;

LAB90:    xsi_set_current_line(32, ng0);
    t2 = (t0 + 1336U);
    t3 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t6 + 4);
    t4 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 0);
    t10 = (t9 & 1);
    *((unsigned int *)t6) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 0);
    t13 = (t12 & 1);
    *((unsigned int *)t2) = t13;
    t5 = ((char*)((ng1)));
    memset(t15, 0, 8);
    t7 = (t6 + 4);
    t14 = (t5 + 4);
    t18 = *((unsigned int *)t6);
    t19 = *((unsigned int *)t5);
    t20 = (t18 ^ t19);
    t21 = *((unsigned int *)t7);
    t22 = *((unsigned int *)t14);
    t23 = (t21 ^ t22);
    t24 = (t20 | t23);
    t25 = *((unsigned int *)t7);
    t26 = *((unsigned int *)t14);
    t27 = (t25 | t26);
    t28 = (~(t27));
    t29 = (t24 & t28);
    if (t29 != 0)
        goto LAB95;

LAB92:    if (t27 != 0)
        goto LAB94;

LAB93:    *((unsigned int *)t15) = 1;

LAB95:    memset(t31, 0, 8);
    t17 = (t15 + 4);
    t33 = *((unsigned int *)t17);
    t34 = (~(t33));
    t35 = *((unsigned int *)t15);
    t36 = (t35 & t34);
    t37 = (t36 & 1U);
    if (t37 != 0)
        goto LAB96;

LAB97:    if (*((unsigned int *)t17) != 0)
        goto LAB98;

LAB99:    t32 = (t31 + 4);
    t40 = *((unsigned int *)t31);
    t41 = *((unsigned int *)t32);
    t42 = (t40 || t41);
    if (t42 > 0)
        goto LAB100;

LAB101:    memcpy(t78, t31, 8);

LAB102:    memset(t110, 0, 8);
    t92 = (t78 + 4);
    t112 = *((unsigned int *)t92);
    t113 = (~(t112));
    t114 = *((unsigned int *)t78);
    t115 = (t114 & t113);
    t116 = (t115 & 1U);
    if (t116 != 0)
        goto LAB114;

LAB115:    if (*((unsigned int *)t92) != 0)
        goto LAB116;

LAB117:    t111 = (t110 + 4);
    t119 = *((unsigned int *)t110);
    t120 = *((unsigned int *)t111);
    t121 = (t119 || t120);
    if (t121 > 0)
        goto LAB118;

LAB119:    memcpy(t157, t110, 8);

LAB120:    t171 = (t157 + 4);
    t190 = *((unsigned int *)t171);
    t191 = (~(t190));
    t192 = *((unsigned int *)t157);
    t193 = (t192 & t191);
    t194 = (t193 != 0);
    if (t194 > 0)
        goto LAB132;

LAB133:    xsi_set_current_line(34, ng0);
    t2 = (t0 + 1336U);
    t3 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t6 + 4);
    t4 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 0);
    t10 = (t9 & 1);
    *((unsigned int *)t6) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 0);
    t13 = (t12 & 1);
    *((unsigned int *)t2) = t13;
    t5 = ((char*)((ng1)));
    memset(t15, 0, 8);
    t7 = (t6 + 4);
    t14 = (t5 + 4);
    t18 = *((unsigned int *)t6);
    t19 = *((unsigned int *)t5);
    t20 = (t18 ^ t19);
    t21 = *((unsigned int *)t7);
    t22 = *((unsigned int *)t14);
    t23 = (t21 ^ t22);
    t24 = (t20 | t23);
    t25 = *((unsigned int *)t7);
    t26 = *((unsigned int *)t14);
    t27 = (t25 | t26);
    t28 = (~(t27));
    t29 = (t24 & t28);
    if (t29 != 0)
        goto LAB138;

LAB135:    if (t27 != 0)
        goto LAB137;

LAB136:    *((unsigned int *)t15) = 1;

LAB138:    memset(t31, 0, 8);
    t17 = (t15 + 4);
    t33 = *((unsigned int *)t17);
    t34 = (~(t33));
    t35 = *((unsigned int *)t15);
    t36 = (t35 & t34);
    t37 = (t36 & 1U);
    if (t37 != 0)
        goto LAB139;

LAB140:    if (*((unsigned int *)t17) != 0)
        goto LAB141;

LAB142:    t32 = (t31 + 4);
    t40 = *((unsigned int *)t31);
    t41 = *((unsigned int *)t32);
    t42 = (t40 || t41);
    if (t42 > 0)
        goto LAB143;

LAB144:    memcpy(t78, t31, 8);

LAB145:    memset(t110, 0, 8);
    t92 = (t78 + 4);
    t112 = *((unsigned int *)t92);
    t113 = (~(t112));
    t114 = *((unsigned int *)t78);
    t115 = (t114 & t113);
    t116 = (t115 & 1U);
    if (t116 != 0)
        goto LAB157;

LAB158:    if (*((unsigned int *)t92) != 0)
        goto LAB159;

LAB160:    t111 = (t110 + 4);
    t119 = *((unsigned int *)t110);
    t120 = *((unsigned int *)t111);
    t121 = (t119 || t120);
    if (t121 > 0)
        goto LAB161;

LAB162:    memcpy(t157, t110, 8);

LAB163:    t171 = (t157 + 4);
    t190 = *((unsigned int *)t171);
    t191 = (~(t190));
    t192 = *((unsigned int *)t157);
    t193 = (t192 & t191);
    t194 = (t193 != 0);
    if (t194 > 0)
        goto LAB175;

LAB176:    xsi_set_current_line(36, ng0);
    t2 = (t0 + 1336U);
    t3 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t6 + 4);
    t4 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 0);
    t10 = (t9 & 1);
    *((unsigned int *)t6) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 0);
    t13 = (t12 & 1);
    *((unsigned int *)t2) = t13;
    t5 = ((char*)((ng2)));
    memset(t15, 0, 8);
    t7 = (t6 + 4);
    t14 = (t5 + 4);
    t18 = *((unsigned int *)t6);
    t19 = *((unsigned int *)t5);
    t20 = (t18 ^ t19);
    t21 = *((unsigned int *)t7);
    t22 = *((unsigned int *)t14);
    t23 = (t21 ^ t22);
    t24 = (t20 | t23);
    t25 = *((unsigned int *)t7);
    t26 = *((unsigned int *)t14);
    t27 = (t25 | t26);
    t28 = (~(t27));
    t29 = (t24 & t28);
    if (t29 != 0)
        goto LAB181;

LAB178:    if (t27 != 0)
        goto LAB180;

LAB179:    *((unsigned int *)t15) = 1;

LAB181:    memset(t31, 0, 8);
    t17 = (t15 + 4);
    t33 = *((unsigned int *)t17);
    t34 = (~(t33));
    t35 = *((unsigned int *)t15);
    t36 = (t35 & t34);
    t37 = (t36 & 1U);
    if (t37 != 0)
        goto LAB182;

LAB183:    if (*((unsigned int *)t17) != 0)
        goto LAB184;

LAB185:    t32 = (t31 + 4);
    t40 = *((unsigned int *)t31);
    t41 = *((unsigned int *)t32);
    t42 = (t40 || t41);
    if (t42 > 0)
        goto LAB186;

LAB187:    memcpy(t78, t31, 8);

LAB188:    memset(t110, 0, 8);
    t92 = (t78 + 4);
    t112 = *((unsigned int *)t92);
    t113 = (~(t112));
    t114 = *((unsigned int *)t78);
    t115 = (t114 & t113);
    t116 = (t115 & 1U);
    if (t116 != 0)
        goto LAB200;

LAB201:    if (*((unsigned int *)t92) != 0)
        goto LAB202;

LAB203:    t111 = (t110 + 4);
    t119 = *((unsigned int *)t110);
    t120 = *((unsigned int *)t111);
    t121 = (t119 || t120);
    if (t121 > 0)
        goto LAB204;

LAB205:    memcpy(t157, t110, 8);

LAB206:    t171 = (t157 + 4);
    t190 = *((unsigned int *)t171);
    t191 = (~(t190));
    t192 = *((unsigned int *)t157);
    t193 = (t192 & t191);
    t194 = (t193 != 0);
    if (t194 > 0)
        goto LAB218;

LAB219:    xsi_set_current_line(38, ng0);
    t2 = (t0 + 1336U);
    t3 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t6 + 4);
    t4 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 0);
    t10 = (t9 & 1);
    *((unsigned int *)t6) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 0);
    t13 = (t12 & 1);
    *((unsigned int *)t2) = t13;
    t5 = ((char*)((ng2)));
    memset(t15, 0, 8);
    t7 = (t6 + 4);
    t14 = (t5 + 4);
    t18 = *((unsigned int *)t6);
    t19 = *((unsigned int *)t5);
    t20 = (t18 ^ t19);
    t21 = *((unsigned int *)t7);
    t22 = *((unsigned int *)t14);
    t23 = (t21 ^ t22);
    t24 = (t20 | t23);
    t25 = *((unsigned int *)t7);
    t26 = *((unsigned int *)t14);
    t27 = (t25 | t26);
    t28 = (~(t27));
    t29 = (t24 & t28);
    if (t29 != 0)
        goto LAB224;

LAB221:    if (t27 != 0)
        goto LAB223;

LAB222:    *((unsigned int *)t15) = 1;

LAB224:    memset(t31, 0, 8);
    t17 = (t15 + 4);
    t33 = *((unsigned int *)t17);
    t34 = (~(t33));
    t35 = *((unsigned int *)t15);
    t36 = (t35 & t34);
    t37 = (t36 & 1U);
    if (t37 != 0)
        goto LAB225;

LAB226:    if (*((unsigned int *)t17) != 0)
        goto LAB227;

LAB228:    t32 = (t31 + 4);
    t40 = *((unsigned int *)t31);
    t41 = *((unsigned int *)t32);
    t42 = (t40 || t41);
    if (t42 > 0)
        goto LAB229;

LAB230:    memcpy(t78, t31, 8);

LAB231:    memset(t110, 0, 8);
    t92 = (t78 + 4);
    t112 = *((unsigned int *)t92);
    t113 = (~(t112));
    t114 = *((unsigned int *)t78);
    t115 = (t114 & t113);
    t116 = (t115 & 1U);
    if (t116 != 0)
        goto LAB243;

LAB244:    if (*((unsigned int *)t92) != 0)
        goto LAB245;

LAB246:    t111 = (t110 + 4);
    t119 = *((unsigned int *)t110);
    t120 = *((unsigned int *)t111);
    t121 = (t119 || t120);
    if (t121 > 0)
        goto LAB247;

LAB248:    memcpy(t157, t110, 8);

LAB249:    t171 = (t157 + 4);
    t190 = *((unsigned int *)t171);
    t191 = (~(t190));
    t192 = *((unsigned int *)t157);
    t193 = (t192 & t191);
    t194 = (t193 != 0);
    if (t194 > 0)
        goto LAB261;

LAB262:    xsi_set_current_line(40, ng0);
    t2 = (t0 + 1336U);
    t3 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t6 + 4);
    t4 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 0);
    t10 = (t9 & 1);
    *((unsigned int *)t6) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 0);
    t13 = (t12 & 1);
    *((unsigned int *)t2) = t13;
    t5 = ((char*)((ng2)));
    memset(t15, 0, 8);
    t7 = (t6 + 4);
    t14 = (t5 + 4);
    t18 = *((unsigned int *)t6);
    t19 = *((unsigned int *)t5);
    t20 = (t18 ^ t19);
    t21 = *((unsigned int *)t7);
    t22 = *((unsigned int *)t14);
    t23 = (t21 ^ t22);
    t24 = (t20 | t23);
    t25 = *((unsigned int *)t7);
    t26 = *((unsigned int *)t14);
    t27 = (t25 | t26);
    t28 = (~(t27));
    t29 = (t24 & t28);
    if (t29 != 0)
        goto LAB267;

LAB264:    if (t27 != 0)
        goto LAB266;

LAB265:    *((unsigned int *)t15) = 1;

LAB267:    memset(t31, 0, 8);
    t17 = (t15 + 4);
    t33 = *((unsigned int *)t17);
    t34 = (~(t33));
    t35 = *((unsigned int *)t15);
    t36 = (t35 & t34);
    t37 = (t36 & 1U);
    if (t37 != 0)
        goto LAB268;

LAB269:    if (*((unsigned int *)t17) != 0)
        goto LAB270;

LAB271:    t32 = (t31 + 4);
    t40 = *((unsigned int *)t31);
    t41 = *((unsigned int *)t32);
    t42 = (t40 || t41);
    if (t42 > 0)
        goto LAB272;

LAB273:    memcpy(t78, t31, 8);

LAB274:    memset(t110, 0, 8);
    t92 = (t78 + 4);
    t112 = *((unsigned int *)t92);
    t113 = (~(t112));
    t114 = *((unsigned int *)t78);
    t115 = (t114 & t113);
    t116 = (t115 & 1U);
    if (t116 != 0)
        goto LAB286;

LAB287:    if (*((unsigned int *)t92) != 0)
        goto LAB288;

LAB289:    t111 = (t110 + 4);
    t119 = *((unsigned int *)t110);
    t120 = *((unsigned int *)t111);
    t121 = (t119 || t120);
    if (t121 > 0)
        goto LAB290;

LAB291:    memcpy(t157, t110, 8);

LAB292:    t171 = (t157 + 4);
    t190 = *((unsigned int *)t171);
    t191 = (~(t190));
    t192 = *((unsigned int *)t157);
    t193 = (t192 & t191);
    t194 = (t193 != 0);
    if (t194 > 0)
        goto LAB304;

LAB305:    xsi_set_current_line(42, ng0);
    t2 = (t0 + 1336U);
    t3 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t6 + 4);
    t4 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 0);
    t10 = (t9 & 1);
    *((unsigned int *)t6) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 0);
    t13 = (t12 & 1);
    *((unsigned int *)t2) = t13;
    t5 = ((char*)((ng2)));
    memset(t15, 0, 8);
    t7 = (t6 + 4);
    t14 = (t5 + 4);
    t18 = *((unsigned int *)t6);
    t19 = *((unsigned int *)t5);
    t20 = (t18 ^ t19);
    t21 = *((unsigned int *)t7);
    t22 = *((unsigned int *)t14);
    t23 = (t21 ^ t22);
    t24 = (t20 | t23);
    t25 = *((unsigned int *)t7);
    t26 = *((unsigned int *)t14);
    t27 = (t25 | t26);
    t28 = (~(t27));
    t29 = (t24 & t28);
    if (t29 != 0)
        goto LAB310;

LAB307:    if (t27 != 0)
        goto LAB309;

LAB308:    *((unsigned int *)t15) = 1;

LAB310:    memset(t31, 0, 8);
    t17 = (t15 + 4);
    t33 = *((unsigned int *)t17);
    t34 = (~(t33));
    t35 = *((unsigned int *)t15);
    t36 = (t35 & t34);
    t37 = (t36 & 1U);
    if (t37 != 0)
        goto LAB311;

LAB312:    if (*((unsigned int *)t17) != 0)
        goto LAB313;

LAB314:    t32 = (t31 + 4);
    t40 = *((unsigned int *)t31);
    t41 = *((unsigned int *)t32);
    t42 = (t40 || t41);
    if (t42 > 0)
        goto LAB315;

LAB316:    memcpy(t78, t31, 8);

LAB317:    memset(t110, 0, 8);
    t92 = (t78 + 4);
    t112 = *((unsigned int *)t92);
    t113 = (~(t112));
    t114 = *((unsigned int *)t78);
    t115 = (t114 & t113);
    t116 = (t115 & 1U);
    if (t116 != 0)
        goto LAB329;

LAB330:    if (*((unsigned int *)t92) != 0)
        goto LAB331;

LAB332:    t111 = (t110 + 4);
    t119 = *((unsigned int *)t110);
    t120 = *((unsigned int *)t111);
    t121 = (t119 || t120);
    if (t121 > 0)
        goto LAB333;

LAB334:    memcpy(t157, t110, 8);

LAB335:    t171 = (t157 + 4);
    t190 = *((unsigned int *)t171);
    t191 = (~(t190));
    t192 = *((unsigned int *)t157);
    t193 = (t192 & t191);
    t194 = (t193 != 0);
    if (t194 > 0)
        goto LAB347;

LAB348:
LAB349:
LAB306:
LAB263:
LAB220:
LAB177:
LAB134:
LAB91:
LAB48:    goto LAB2;

LAB8:    t30 = (t15 + 4);
    *((unsigned int *)t15) = 1;
    *((unsigned int *)t30) = 1;
    goto LAB9;

LAB10:    *((unsigned int *)t31) = 1;
    goto LAB13;

LAB12:    t38 = (t31 + 4);
    *((unsigned int *)t31) = 1;
    *((unsigned int *)t38) = 1;
    goto LAB13;

LAB14:    t43 = (t0 + 1336U);
    t44 = *((char **)t43);
    memset(t45, 0, 8);
    t43 = (t45 + 4);
    t46 = (t44 + 4);
    t47 = *((unsigned int *)t44);
    t48 = (t47 >> 1);
    t49 = (t48 & 1);
    *((unsigned int *)t45) = t49;
    t50 = *((unsigned int *)t46);
    t51 = (t50 >> 1);
    t52 = (t51 & 1);
    *((unsigned int *)t43) = t52;
    t53 = ((char*)((ng1)));
    memset(t54, 0, 8);
    t55 = (t45 + 4);
    t56 = (t53 + 4);
    t57 = *((unsigned int *)t45);
    t58 = *((unsigned int *)t53);
    t59 = (t57 ^ t58);
    t60 = *((unsigned int *)t55);
    t61 = *((unsigned int *)t56);
    t62 = (t60 ^ t61);
    t63 = (t59 | t62);
    t64 = *((unsigned int *)t55);
    t65 = *((unsigned int *)t56);
    t66 = (t64 | t65);
    t67 = (~(t66));
    t68 = (t63 & t67);
    if (t68 != 0)
        goto LAB20;

LAB17:    if (t66 != 0)
        goto LAB19;

LAB18:    *((unsigned int *)t54) = 1;

LAB20:    memset(t70, 0, 8);
    t71 = (t54 + 4);
    t72 = *((unsigned int *)t71);
    t73 = (~(t72));
    t74 = *((unsigned int *)t54);
    t75 = (t74 & t73);
    t76 = (t75 & 1U);
    if (t76 != 0)
        goto LAB21;

LAB22:    if (*((unsigned int *)t71) != 0)
        goto LAB23;

LAB24:    t79 = *((unsigned int *)t31);
    t80 = *((unsigned int *)t70);
    t81 = (t79 & t80);
    *((unsigned int *)t78) = t81;
    t82 = (t31 + 4);
    t83 = (t70 + 4);
    t84 = (t78 + 4);
    t85 = *((unsigned int *)t82);
    t86 = *((unsigned int *)t83);
    t87 = (t85 | t86);
    *((unsigned int *)t84) = t87;
    t88 = *((unsigned int *)t84);
    t89 = (t88 != 0);
    if (t89 == 1)
        goto LAB25;

LAB26:
LAB27:    goto LAB16;

LAB19:    t69 = (t54 + 4);
    *((unsigned int *)t54) = 1;
    *((unsigned int *)t69) = 1;
    goto LAB20;

LAB21:    *((unsigned int *)t70) = 1;
    goto LAB24;

LAB23:    t77 = (t70 + 4);
    *((unsigned int *)t70) = 1;
    *((unsigned int *)t77) = 1;
    goto LAB24;

LAB25:    t90 = *((unsigned int *)t78);
    t91 = *((unsigned int *)t84);
    *((unsigned int *)t78) = (t90 | t91);
    t92 = (t31 + 4);
    t93 = (t70 + 4);
    t94 = *((unsigned int *)t31);
    t95 = (~(t94));
    t96 = *((unsigned int *)t92);
    t97 = (~(t96));
    t98 = *((unsigned int *)t70);
    t99 = (~(t98));
    t100 = *((unsigned int *)t93);
    t101 = (~(t100));
    t102 = (t95 & t97);
    t103 = (t99 & t101);
    t104 = (~(t102));
    t105 = (~(t103));
    t106 = *((unsigned int *)t84);
    *((unsigned int *)t84) = (t106 & t104);
    t107 = *((unsigned int *)t84);
    *((unsigned int *)t84) = (t107 & t105);
    t108 = *((unsigned int *)t78);
    *((unsigned int *)t78) = (t108 & t104);
    t109 = *((unsigned int *)t78);
    *((unsigned int *)t78) = (t109 & t105);
    goto LAB27;

LAB28:    *((unsigned int *)t110) = 1;
    goto LAB31;

LAB30:    t117 = (t110 + 4);
    *((unsigned int *)t110) = 1;
    *((unsigned int *)t117) = 1;
    goto LAB31;

LAB32:    t122 = (t0 + 1336U);
    t123 = *((char **)t122);
    memset(t124, 0, 8);
    t122 = (t124 + 4);
    t125 = (t123 + 4);
    t126 = *((unsigned int *)t123);
    t127 = (t126 >> 2);
    t128 = (t127 & 1);
    *((unsigned int *)t124) = t128;
    t129 = *((unsigned int *)t125);
    t130 = (t129 >> 2);
    t131 = (t130 & 1);
    *((unsigned int *)t122) = t131;
    t132 = ((char*)((ng1)));
    memset(t133, 0, 8);
    t134 = (t124 + 4);
    t135 = (t132 + 4);
    t136 = *((unsigned int *)t124);
    t137 = *((unsigned int *)t132);
    t138 = (t136 ^ t137);
    t139 = *((unsigned int *)t134);
    t140 = *((unsigned int *)t135);
    t141 = (t139 ^ t140);
    t142 = (t138 | t141);
    t143 = *((unsigned int *)t134);
    t144 = *((unsigned int *)t135);
    t145 = (t143 | t144);
    t146 = (~(t145));
    t147 = (t142 & t146);
    if (t147 != 0)
        goto LAB38;

LAB35:    if (t145 != 0)
        goto LAB37;

LAB36:    *((unsigned int *)t133) = 1;

LAB38:    memset(t149, 0, 8);
    t150 = (t133 + 4);
    t151 = *((unsigned int *)t150);
    t152 = (~(t151));
    t153 = *((unsigned int *)t133);
    t154 = (t153 & t152);
    t155 = (t154 & 1U);
    if (t155 != 0)
        goto LAB39;

LAB40:    if (*((unsigned int *)t150) != 0)
        goto LAB41;

LAB42:    t158 = *((unsigned int *)t110);
    t159 = *((unsigned int *)t149);
    t160 = (t158 & t159);
    *((unsigned int *)t157) = t160;
    t161 = (t110 + 4);
    t162 = (t149 + 4);
    t163 = (t157 + 4);
    t164 = *((unsigned int *)t161);
    t165 = *((unsigned int *)t162);
    t166 = (t164 | t165);
    *((unsigned int *)t163) = t166;
    t167 = *((unsigned int *)t163);
    t168 = (t167 != 0);
    if (t168 == 1)
        goto LAB43;

LAB44:
LAB45:    goto LAB34;

LAB37:    t148 = (t133 + 4);
    *((unsigned int *)t133) = 1;
    *((unsigned int *)t148) = 1;
    goto LAB38;

LAB39:    *((unsigned int *)t149) = 1;
    goto LAB42;

LAB41:    t156 = (t149 + 4);
    *((unsigned int *)t149) = 1;
    *((unsigned int *)t156) = 1;
    goto LAB42;

LAB43:    t169 = *((unsigned int *)t157);
    t170 = *((unsigned int *)t163);
    *((unsigned int *)t157) = (t169 | t170);
    t171 = (t110 + 4);
    t172 = (t149 + 4);
    t173 = *((unsigned int *)t110);
    t174 = (~(t173));
    t175 = *((unsigned int *)t171);
    t176 = (~(t175));
    t177 = *((unsigned int *)t149);
    t178 = (~(t177));
    t179 = *((unsigned int *)t172);
    t180 = (~(t179));
    t181 = (t174 & t176);
    t182 = (t178 & t180);
    t183 = (~(t181));
    t184 = (~(t182));
    t185 = *((unsigned int *)t163);
    *((unsigned int *)t163) = (t185 & t183);
    t186 = *((unsigned int *)t163);
    *((unsigned int *)t163) = (t186 & t184);
    t187 = *((unsigned int *)t157);
    *((unsigned int *)t157) = (t187 & t183);
    t188 = *((unsigned int *)t157);
    *((unsigned int *)t157) = (t188 & t184);
    goto LAB45;

LAB46:    xsi_set_current_line(29, ng0);
    t195 = (t0 + 600U);
    t196 = *((char **)t195);
    t195 = (t0 + 1564);
    xsi_vlogvar_wait_assign_value(t195, t196, 0, 0, 8, 0LL);
    goto LAB48;

LAB51:    t16 = (t15 + 4);
    *((unsigned int *)t15) = 1;
    *((unsigned int *)t16) = 1;
    goto LAB52;

LAB53:    *((unsigned int *)t31) = 1;
    goto LAB56;

LAB55:    t30 = (t31 + 4);
    *((unsigned int *)t31) = 1;
    *((unsigned int *)t30) = 1;
    goto LAB56;

LAB57:    t38 = (t0 + 1336U);
    t39 = *((char **)t38);
    memset(t45, 0, 8);
    t38 = (t45 + 4);
    t43 = (t39 + 4);
    t47 = *((unsigned int *)t39);
    t48 = (t47 >> 1);
    t49 = (t48 & 1);
    *((unsigned int *)t45) = t49;
    t50 = *((unsigned int *)t43);
    t51 = (t50 >> 1);
    t52 = (t51 & 1);
    *((unsigned int *)t38) = t52;
    t44 = ((char*)((ng1)));
    memset(t54, 0, 8);
    t46 = (t45 + 4);
    t53 = (t44 + 4);
    t57 = *((unsigned int *)t45);
    t58 = *((unsigned int *)t44);
    t59 = (t57 ^ t58);
    t60 = *((unsigned int *)t46);
    t61 = *((unsigned int *)t53);
    t62 = (t60 ^ t61);
    t63 = (t59 | t62);
    t64 = *((unsigned int *)t46);
    t65 = *((unsigned int *)t53);
    t66 = (t64 | t65);
    t67 = (~(t66));
    t68 = (t63 & t67);
    if (t68 != 0)
        goto LAB63;

LAB60:    if (t66 != 0)
        goto LAB62;

LAB61:    *((unsigned int *)t54) = 1;

LAB63:    memset(t70, 0, 8);
    t56 = (t54 + 4);
    t72 = *((unsigned int *)t56);
    t73 = (~(t72));
    t74 = *((unsigned int *)t54);
    t75 = (t74 & t73);
    t76 = (t75 & 1U);
    if (t76 != 0)
        goto LAB64;

LAB65:    if (*((unsigned int *)t56) != 0)
        goto LAB66;

LAB67:    t79 = *((unsigned int *)t31);
    t80 = *((unsigned int *)t70);
    t81 = (t79 & t80);
    *((unsigned int *)t78) = t81;
    t71 = (t31 + 4);
    t77 = (t70 + 4);
    t82 = (t78 + 4);
    t85 = *((unsigned int *)t71);
    t86 = *((unsigned int *)t77);
    t87 = (t85 | t86);
    *((unsigned int *)t82) = t87;
    t88 = *((unsigned int *)t82);
    t89 = (t88 != 0);
    if (t89 == 1)
        goto LAB68;

LAB69:
LAB70:    goto LAB59;

LAB62:    t55 = (t54 + 4);
    *((unsigned int *)t54) = 1;
    *((unsigned int *)t55) = 1;
    goto LAB63;

LAB64:    *((unsigned int *)t70) = 1;
    goto LAB67;

LAB66:    t69 = (t70 + 4);
    *((unsigned int *)t70) = 1;
    *((unsigned int *)t69) = 1;
    goto LAB67;

LAB68:    t90 = *((unsigned int *)t78);
    t91 = *((unsigned int *)t82);
    *((unsigned int *)t78) = (t90 | t91);
    t83 = (t31 + 4);
    t84 = (t70 + 4);
    t94 = *((unsigned int *)t31);
    t95 = (~(t94));
    t96 = *((unsigned int *)t83);
    t97 = (~(t96));
    t98 = *((unsigned int *)t70);
    t99 = (~(t98));
    t100 = *((unsigned int *)t84);
    t101 = (~(t100));
    t102 = (t95 & t97);
    t103 = (t99 & t101);
    t104 = (~(t102));
    t105 = (~(t103));
    t106 = *((unsigned int *)t82);
    *((unsigned int *)t82) = (t106 & t104);
    t107 = *((unsigned int *)t82);
    *((unsigned int *)t82) = (t107 & t105);
    t108 = *((unsigned int *)t78);
    *((unsigned int *)t78) = (t108 & t104);
    t109 = *((unsigned int *)t78);
    *((unsigned int *)t78) = (t109 & t105);
    goto LAB70;

LAB71:    *((unsigned int *)t110) = 1;
    goto LAB74;

LAB73:    t93 = (t110 + 4);
    *((unsigned int *)t110) = 1;
    *((unsigned int *)t93) = 1;
    goto LAB74;

LAB75:    t117 = (t0 + 1336U);
    t118 = *((char **)t117);
    memset(t124, 0, 8);
    t117 = (t124 + 4);
    t122 = (t118 + 4);
    t126 = *((unsigned int *)t118);
    t127 = (t126 >> 2);
    t128 = (t127 & 1);
    *((unsigned int *)t124) = t128;
    t129 = *((unsigned int *)t122);
    t130 = (t129 >> 2);
    t131 = (t130 & 1);
    *((unsigned int *)t117) = t131;
    t123 = ((char*)((ng2)));
    memset(t133, 0, 8);
    t125 = (t124 + 4);
    t132 = (t123 + 4);
    t136 = *((unsigned int *)t124);
    t137 = *((unsigned int *)t123);
    t138 = (t136 ^ t137);
    t139 = *((unsigned int *)t125);
    t140 = *((unsigned int *)t132);
    t141 = (t139 ^ t140);
    t142 = (t138 | t141);
    t143 = *((unsigned int *)t125);
    t144 = *((unsigned int *)t132);
    t145 = (t143 | t144);
    t146 = (~(t145));
    t147 = (t142 & t146);
    if (t147 != 0)
        goto LAB81;

LAB78:    if (t145 != 0)
        goto LAB80;

LAB79:    *((unsigned int *)t133) = 1;

LAB81:    memset(t149, 0, 8);
    t135 = (t133 + 4);
    t151 = *((unsigned int *)t135);
    t152 = (~(t151));
    t153 = *((unsigned int *)t133);
    t154 = (t153 & t152);
    t155 = (t154 & 1U);
    if (t155 != 0)
        goto LAB82;

LAB83:    if (*((unsigned int *)t135) != 0)
        goto LAB84;

LAB85:    t158 = *((unsigned int *)t110);
    t159 = *((unsigned int *)t149);
    t160 = (t158 & t159);
    *((unsigned int *)t157) = t160;
    t150 = (t110 + 4);
    t156 = (t149 + 4);
    t161 = (t157 + 4);
    t164 = *((unsigned int *)t150);
    t165 = *((unsigned int *)t156);
    t166 = (t164 | t165);
    *((unsigned int *)t161) = t166;
    t167 = *((unsigned int *)t161);
    t168 = (t167 != 0);
    if (t168 == 1)
        goto LAB86;

LAB87:
LAB88:    goto LAB77;

LAB80:    t134 = (t133 + 4);
    *((unsigned int *)t133) = 1;
    *((unsigned int *)t134) = 1;
    goto LAB81;

LAB82:    *((unsigned int *)t149) = 1;
    goto LAB85;

LAB84:    t148 = (t149 + 4);
    *((unsigned int *)t149) = 1;
    *((unsigned int *)t148) = 1;
    goto LAB85;

LAB86:    t169 = *((unsigned int *)t157);
    t170 = *((unsigned int *)t161);
    *((unsigned int *)t157) = (t169 | t170);
    t162 = (t110 + 4);
    t163 = (t149 + 4);
    t173 = *((unsigned int *)t110);
    t174 = (~(t173));
    t175 = *((unsigned int *)t162);
    t176 = (~(t175));
    t177 = *((unsigned int *)t149);
    t178 = (~(t177));
    t179 = *((unsigned int *)t163);
    t180 = (~(t179));
    t181 = (t174 & t176);
    t182 = (t178 & t180);
    t183 = (~(t181));
    t184 = (~(t182));
    t185 = *((unsigned int *)t161);
    *((unsigned int *)t161) = (t185 & t183);
    t186 = *((unsigned int *)t161);
    *((unsigned int *)t161) = (t186 & t184);
    t187 = *((unsigned int *)t157);
    *((unsigned int *)t157) = (t187 & t183);
    t188 = *((unsigned int *)t157);
    *((unsigned int *)t157) = (t188 & t184);
    goto LAB88;

LAB89:    xsi_set_current_line(31, ng0);
    t172 = (t0 + 692U);
    t189 = *((char **)t172);
    t172 = (t0 + 1564);
    xsi_vlogvar_wait_assign_value(t172, t189, 0, 0, 8, 0LL);
    goto LAB91;

LAB94:    t16 = (t15 + 4);
    *((unsigned int *)t15) = 1;
    *((unsigned int *)t16) = 1;
    goto LAB95;

LAB96:    *((unsigned int *)t31) = 1;
    goto LAB99;

LAB98:    t30 = (t31 + 4);
    *((unsigned int *)t31) = 1;
    *((unsigned int *)t30) = 1;
    goto LAB99;

LAB100:    t38 = (t0 + 1336U);
    t39 = *((char **)t38);
    memset(t45, 0, 8);
    t38 = (t45 + 4);
    t43 = (t39 + 4);
    t47 = *((unsigned int *)t39);
    t48 = (t47 >> 1);
    t49 = (t48 & 1);
    *((unsigned int *)t45) = t49;
    t50 = *((unsigned int *)t43);
    t51 = (t50 >> 1);
    t52 = (t51 & 1);
    *((unsigned int *)t38) = t52;
    t44 = ((char*)((ng2)));
    memset(t54, 0, 8);
    t46 = (t45 + 4);
    t53 = (t44 + 4);
    t57 = *((unsigned int *)t45);
    t58 = *((unsigned int *)t44);
    t59 = (t57 ^ t58);
    t60 = *((unsigned int *)t46);
    t61 = *((unsigned int *)t53);
    t62 = (t60 ^ t61);
    t63 = (t59 | t62);
    t64 = *((unsigned int *)t46);
    t65 = *((unsigned int *)t53);
    t66 = (t64 | t65);
    t67 = (~(t66));
    t68 = (t63 & t67);
    if (t68 != 0)
        goto LAB106;

LAB103:    if (t66 != 0)
        goto LAB105;

LAB104:    *((unsigned int *)t54) = 1;

LAB106:    memset(t70, 0, 8);
    t56 = (t54 + 4);
    t72 = *((unsigned int *)t56);
    t73 = (~(t72));
    t74 = *((unsigned int *)t54);
    t75 = (t74 & t73);
    t76 = (t75 & 1U);
    if (t76 != 0)
        goto LAB107;

LAB108:    if (*((unsigned int *)t56) != 0)
        goto LAB109;

LAB110:    t79 = *((unsigned int *)t31);
    t80 = *((unsigned int *)t70);
    t81 = (t79 & t80);
    *((unsigned int *)t78) = t81;
    t71 = (t31 + 4);
    t77 = (t70 + 4);
    t82 = (t78 + 4);
    t85 = *((unsigned int *)t71);
    t86 = *((unsigned int *)t77);
    t87 = (t85 | t86);
    *((unsigned int *)t82) = t87;
    t88 = *((unsigned int *)t82);
    t89 = (t88 != 0);
    if (t89 == 1)
        goto LAB111;

LAB112:
LAB113:    goto LAB102;

LAB105:    t55 = (t54 + 4);
    *((unsigned int *)t54) = 1;
    *((unsigned int *)t55) = 1;
    goto LAB106;

LAB107:    *((unsigned int *)t70) = 1;
    goto LAB110;

LAB109:    t69 = (t70 + 4);
    *((unsigned int *)t70) = 1;
    *((unsigned int *)t69) = 1;
    goto LAB110;

LAB111:    t90 = *((unsigned int *)t78);
    t91 = *((unsigned int *)t82);
    *((unsigned int *)t78) = (t90 | t91);
    t83 = (t31 + 4);
    t84 = (t70 + 4);
    t94 = *((unsigned int *)t31);
    t95 = (~(t94));
    t96 = *((unsigned int *)t83);
    t97 = (~(t96));
    t98 = *((unsigned int *)t70);
    t99 = (~(t98));
    t100 = *((unsigned int *)t84);
    t101 = (~(t100));
    t102 = (t95 & t97);
    t103 = (t99 & t101);
    t104 = (~(t102));
    t105 = (~(t103));
    t106 = *((unsigned int *)t82);
    *((unsigned int *)t82) = (t106 & t104);
    t107 = *((unsigned int *)t82);
    *((unsigned int *)t82) = (t107 & t105);
    t108 = *((unsigned int *)t78);
    *((unsigned int *)t78) = (t108 & t104);
    t109 = *((unsigned int *)t78);
    *((unsigned int *)t78) = (t109 & t105);
    goto LAB113;

LAB114:    *((unsigned int *)t110) = 1;
    goto LAB117;

LAB116:    t93 = (t110 + 4);
    *((unsigned int *)t110) = 1;
    *((unsigned int *)t93) = 1;
    goto LAB117;

LAB118:    t117 = (t0 + 1336U);
    t118 = *((char **)t117);
    memset(t124, 0, 8);
    t117 = (t124 + 4);
    t122 = (t118 + 4);
    t126 = *((unsigned int *)t118);
    t127 = (t126 >> 2);
    t128 = (t127 & 1);
    *((unsigned int *)t124) = t128;
    t129 = *((unsigned int *)t122);
    t130 = (t129 >> 2);
    t131 = (t130 & 1);
    *((unsigned int *)t117) = t131;
    t123 = ((char*)((ng1)));
    memset(t133, 0, 8);
    t125 = (t124 + 4);
    t132 = (t123 + 4);
    t136 = *((unsigned int *)t124);
    t137 = *((unsigned int *)t123);
    t138 = (t136 ^ t137);
    t139 = *((unsigned int *)t125);
    t140 = *((unsigned int *)t132);
    t141 = (t139 ^ t140);
    t142 = (t138 | t141);
    t143 = *((unsigned int *)t125);
    t144 = *((unsigned int *)t132);
    t145 = (t143 | t144);
    t146 = (~(t145));
    t147 = (t142 & t146);
    if (t147 != 0)
        goto LAB124;

LAB121:    if (t145 != 0)
        goto LAB123;

LAB122:    *((unsigned int *)t133) = 1;

LAB124:    memset(t149, 0, 8);
    t135 = (t133 + 4);
    t151 = *((unsigned int *)t135);
    t152 = (~(t151));
    t153 = *((unsigned int *)t133);
    t154 = (t153 & t152);
    t155 = (t154 & 1U);
    if (t155 != 0)
        goto LAB125;

LAB126:    if (*((unsigned int *)t135) != 0)
        goto LAB127;

LAB128:    t158 = *((unsigned int *)t110);
    t159 = *((unsigned int *)t149);
    t160 = (t158 & t159);
    *((unsigned int *)t157) = t160;
    t150 = (t110 + 4);
    t156 = (t149 + 4);
    t161 = (t157 + 4);
    t164 = *((unsigned int *)t150);
    t165 = *((unsigned int *)t156);
    t166 = (t164 | t165);
    *((unsigned int *)t161) = t166;
    t167 = *((unsigned int *)t161);
    t168 = (t167 != 0);
    if (t168 == 1)
        goto LAB129;

LAB130:
LAB131:    goto LAB120;

LAB123:    t134 = (t133 + 4);
    *((unsigned int *)t133) = 1;
    *((unsigned int *)t134) = 1;
    goto LAB124;

LAB125:    *((unsigned int *)t149) = 1;
    goto LAB128;

LAB127:    t148 = (t149 + 4);
    *((unsigned int *)t149) = 1;
    *((unsigned int *)t148) = 1;
    goto LAB128;

LAB129:    t169 = *((unsigned int *)t157);
    t170 = *((unsigned int *)t161);
    *((unsigned int *)t157) = (t169 | t170);
    t162 = (t110 + 4);
    t163 = (t149 + 4);
    t173 = *((unsigned int *)t110);
    t174 = (~(t173));
    t175 = *((unsigned int *)t162);
    t176 = (~(t175));
    t177 = *((unsigned int *)t149);
    t178 = (~(t177));
    t179 = *((unsigned int *)t163);
    t180 = (~(t179));
    t181 = (t174 & t176);
    t182 = (t178 & t180);
    t183 = (~(t181));
    t184 = (~(t182));
    t185 = *((unsigned int *)t161);
    *((unsigned int *)t161) = (t185 & t183);
    t186 = *((unsigned int *)t161);
    *((unsigned int *)t161) = (t186 & t184);
    t187 = *((unsigned int *)t157);
    *((unsigned int *)t157) = (t187 & t183);
    t188 = *((unsigned int *)t157);
    *((unsigned int *)t157) = (t188 & t184);
    goto LAB131;

LAB132:    xsi_set_current_line(33, ng0);
    t172 = (t0 + 784U);
    t189 = *((char **)t172);
    t172 = (t0 + 1564);
    xsi_vlogvar_wait_assign_value(t172, t189, 0, 0, 8, 0LL);
    goto LAB134;

LAB137:    t16 = (t15 + 4);
    *((unsigned int *)t15) = 1;
    *((unsigned int *)t16) = 1;
    goto LAB138;

LAB139:    *((unsigned int *)t31) = 1;
    goto LAB142;

LAB141:    t30 = (t31 + 4);
    *((unsigned int *)t31) = 1;
    *((unsigned int *)t30) = 1;
    goto LAB142;

LAB143:    t38 = (t0 + 1336U);
    t39 = *((char **)t38);
    memset(t45, 0, 8);
    t38 = (t45 + 4);
    t43 = (t39 + 4);
    t47 = *((unsigned int *)t39);
    t48 = (t47 >> 1);
    t49 = (t48 & 1);
    *((unsigned int *)t45) = t49;
    t50 = *((unsigned int *)t43);
    t51 = (t50 >> 1);
    t52 = (t51 & 1);
    *((unsigned int *)t38) = t52;
    t44 = ((char*)((ng2)));
    memset(t54, 0, 8);
    t46 = (t45 + 4);
    t53 = (t44 + 4);
    t57 = *((unsigned int *)t45);
    t58 = *((unsigned int *)t44);
    t59 = (t57 ^ t58);
    t60 = *((unsigned int *)t46);
    t61 = *((unsigned int *)t53);
    t62 = (t60 ^ t61);
    t63 = (t59 | t62);
    t64 = *((unsigned int *)t46);
    t65 = *((unsigned int *)t53);
    t66 = (t64 | t65);
    t67 = (~(t66));
    t68 = (t63 & t67);
    if (t68 != 0)
        goto LAB149;

LAB146:    if (t66 != 0)
        goto LAB148;

LAB147:    *((unsigned int *)t54) = 1;

LAB149:    memset(t70, 0, 8);
    t56 = (t54 + 4);
    t72 = *((unsigned int *)t56);
    t73 = (~(t72));
    t74 = *((unsigned int *)t54);
    t75 = (t74 & t73);
    t76 = (t75 & 1U);
    if (t76 != 0)
        goto LAB150;

LAB151:    if (*((unsigned int *)t56) != 0)
        goto LAB152;

LAB153:    t79 = *((unsigned int *)t31);
    t80 = *((unsigned int *)t70);
    t81 = (t79 & t80);
    *((unsigned int *)t78) = t81;
    t71 = (t31 + 4);
    t77 = (t70 + 4);
    t82 = (t78 + 4);
    t85 = *((unsigned int *)t71);
    t86 = *((unsigned int *)t77);
    t87 = (t85 | t86);
    *((unsigned int *)t82) = t87;
    t88 = *((unsigned int *)t82);
    t89 = (t88 != 0);
    if (t89 == 1)
        goto LAB154;

LAB155:
LAB156:    goto LAB145;

LAB148:    t55 = (t54 + 4);
    *((unsigned int *)t54) = 1;
    *((unsigned int *)t55) = 1;
    goto LAB149;

LAB150:    *((unsigned int *)t70) = 1;
    goto LAB153;

LAB152:    t69 = (t70 + 4);
    *((unsigned int *)t70) = 1;
    *((unsigned int *)t69) = 1;
    goto LAB153;

LAB154:    t90 = *((unsigned int *)t78);
    t91 = *((unsigned int *)t82);
    *((unsigned int *)t78) = (t90 | t91);
    t83 = (t31 + 4);
    t84 = (t70 + 4);
    t94 = *((unsigned int *)t31);
    t95 = (~(t94));
    t96 = *((unsigned int *)t83);
    t97 = (~(t96));
    t98 = *((unsigned int *)t70);
    t99 = (~(t98));
    t100 = *((unsigned int *)t84);
    t101 = (~(t100));
    t102 = (t95 & t97);
    t103 = (t99 & t101);
    t104 = (~(t102));
    t105 = (~(t103));
    t106 = *((unsigned int *)t82);
    *((unsigned int *)t82) = (t106 & t104);
    t107 = *((unsigned int *)t82);
    *((unsigned int *)t82) = (t107 & t105);
    t108 = *((unsigned int *)t78);
    *((unsigned int *)t78) = (t108 & t104);
    t109 = *((unsigned int *)t78);
    *((unsigned int *)t78) = (t109 & t105);
    goto LAB156;

LAB157:    *((unsigned int *)t110) = 1;
    goto LAB160;

LAB159:    t93 = (t110 + 4);
    *((unsigned int *)t110) = 1;
    *((unsigned int *)t93) = 1;
    goto LAB160;

LAB161:    t117 = (t0 + 1336U);
    t118 = *((char **)t117);
    memset(t124, 0, 8);
    t117 = (t124 + 4);
    t122 = (t118 + 4);
    t126 = *((unsigned int *)t118);
    t127 = (t126 >> 2);
    t128 = (t127 & 1);
    *((unsigned int *)t124) = t128;
    t129 = *((unsigned int *)t122);
    t130 = (t129 >> 2);
    t131 = (t130 & 1);
    *((unsigned int *)t117) = t131;
    t123 = ((char*)((ng2)));
    memset(t133, 0, 8);
    t125 = (t124 + 4);
    t132 = (t123 + 4);
    t136 = *((unsigned int *)t124);
    t137 = *((unsigned int *)t123);
    t138 = (t136 ^ t137);
    t139 = *((unsigned int *)t125);
    t140 = *((unsigned int *)t132);
    t141 = (t139 ^ t140);
    t142 = (t138 | t141);
    t143 = *((unsigned int *)t125);
    t144 = *((unsigned int *)t132);
    t145 = (t143 | t144);
    t146 = (~(t145));
    t147 = (t142 & t146);
    if (t147 != 0)
        goto LAB167;

LAB164:    if (t145 != 0)
        goto LAB166;

LAB165:    *((unsigned int *)t133) = 1;

LAB167:    memset(t149, 0, 8);
    t135 = (t133 + 4);
    t151 = *((unsigned int *)t135);
    t152 = (~(t151));
    t153 = *((unsigned int *)t133);
    t154 = (t153 & t152);
    t155 = (t154 & 1U);
    if (t155 != 0)
        goto LAB168;

LAB169:    if (*((unsigned int *)t135) != 0)
        goto LAB170;

LAB171:    t158 = *((unsigned int *)t110);
    t159 = *((unsigned int *)t149);
    t160 = (t158 & t159);
    *((unsigned int *)t157) = t160;
    t150 = (t110 + 4);
    t156 = (t149 + 4);
    t161 = (t157 + 4);
    t164 = *((unsigned int *)t150);
    t165 = *((unsigned int *)t156);
    t166 = (t164 | t165);
    *((unsigned int *)t161) = t166;
    t167 = *((unsigned int *)t161);
    t168 = (t167 != 0);
    if (t168 == 1)
        goto LAB172;

LAB173:
LAB174:    goto LAB163;

LAB166:    t134 = (t133 + 4);
    *((unsigned int *)t133) = 1;
    *((unsigned int *)t134) = 1;
    goto LAB167;

LAB168:    *((unsigned int *)t149) = 1;
    goto LAB171;

LAB170:    t148 = (t149 + 4);
    *((unsigned int *)t149) = 1;
    *((unsigned int *)t148) = 1;
    goto LAB171;

LAB172:    t169 = *((unsigned int *)t157);
    t170 = *((unsigned int *)t161);
    *((unsigned int *)t157) = (t169 | t170);
    t162 = (t110 + 4);
    t163 = (t149 + 4);
    t173 = *((unsigned int *)t110);
    t174 = (~(t173));
    t175 = *((unsigned int *)t162);
    t176 = (~(t175));
    t177 = *((unsigned int *)t149);
    t178 = (~(t177));
    t179 = *((unsigned int *)t163);
    t180 = (~(t179));
    t181 = (t174 & t176);
    t182 = (t178 & t180);
    t183 = (~(t181));
    t184 = (~(t182));
    t185 = *((unsigned int *)t161);
    *((unsigned int *)t161) = (t185 & t183);
    t186 = *((unsigned int *)t161);
    *((unsigned int *)t161) = (t186 & t184);
    t187 = *((unsigned int *)t157);
    *((unsigned int *)t157) = (t187 & t183);
    t188 = *((unsigned int *)t157);
    *((unsigned int *)t157) = (t188 & t184);
    goto LAB174;

LAB175:    xsi_set_current_line(35, ng0);
    t172 = (t0 + 876U);
    t189 = *((char **)t172);
    t172 = (t0 + 1564);
    xsi_vlogvar_wait_assign_value(t172, t189, 0, 0, 8, 0LL);
    goto LAB177;

LAB180:    t16 = (t15 + 4);
    *((unsigned int *)t15) = 1;
    *((unsigned int *)t16) = 1;
    goto LAB181;

LAB182:    *((unsigned int *)t31) = 1;
    goto LAB185;

LAB184:    t30 = (t31 + 4);
    *((unsigned int *)t31) = 1;
    *((unsigned int *)t30) = 1;
    goto LAB185;

LAB186:    t38 = (t0 + 1336U);
    t39 = *((char **)t38);
    memset(t45, 0, 8);
    t38 = (t45 + 4);
    t43 = (t39 + 4);
    t47 = *((unsigned int *)t39);
    t48 = (t47 >> 1);
    t49 = (t48 & 1);
    *((unsigned int *)t45) = t49;
    t50 = *((unsigned int *)t43);
    t51 = (t50 >> 1);
    t52 = (t51 & 1);
    *((unsigned int *)t38) = t52;
    t44 = ((char*)((ng1)));
    memset(t54, 0, 8);
    t46 = (t45 + 4);
    t53 = (t44 + 4);
    t57 = *((unsigned int *)t45);
    t58 = *((unsigned int *)t44);
    t59 = (t57 ^ t58);
    t60 = *((unsigned int *)t46);
    t61 = *((unsigned int *)t53);
    t62 = (t60 ^ t61);
    t63 = (t59 | t62);
    t64 = *((unsigned int *)t46);
    t65 = *((unsigned int *)t53);
    t66 = (t64 | t65);
    t67 = (~(t66));
    t68 = (t63 & t67);
    if (t68 != 0)
        goto LAB192;

LAB189:    if (t66 != 0)
        goto LAB191;

LAB190:    *((unsigned int *)t54) = 1;

LAB192:    memset(t70, 0, 8);
    t56 = (t54 + 4);
    t72 = *((unsigned int *)t56);
    t73 = (~(t72));
    t74 = *((unsigned int *)t54);
    t75 = (t74 & t73);
    t76 = (t75 & 1U);
    if (t76 != 0)
        goto LAB193;

LAB194:    if (*((unsigned int *)t56) != 0)
        goto LAB195;

LAB196:    t79 = *((unsigned int *)t31);
    t80 = *((unsigned int *)t70);
    t81 = (t79 & t80);
    *((unsigned int *)t78) = t81;
    t71 = (t31 + 4);
    t77 = (t70 + 4);
    t82 = (t78 + 4);
    t85 = *((unsigned int *)t71);
    t86 = *((unsigned int *)t77);
    t87 = (t85 | t86);
    *((unsigned int *)t82) = t87;
    t88 = *((unsigned int *)t82);
    t89 = (t88 != 0);
    if (t89 == 1)
        goto LAB197;

LAB198:
LAB199:    goto LAB188;

LAB191:    t55 = (t54 + 4);
    *((unsigned int *)t54) = 1;
    *((unsigned int *)t55) = 1;
    goto LAB192;

LAB193:    *((unsigned int *)t70) = 1;
    goto LAB196;

LAB195:    t69 = (t70 + 4);
    *((unsigned int *)t70) = 1;
    *((unsigned int *)t69) = 1;
    goto LAB196;

LAB197:    t90 = *((unsigned int *)t78);
    t91 = *((unsigned int *)t82);
    *((unsigned int *)t78) = (t90 | t91);
    t83 = (t31 + 4);
    t84 = (t70 + 4);
    t94 = *((unsigned int *)t31);
    t95 = (~(t94));
    t96 = *((unsigned int *)t83);
    t97 = (~(t96));
    t98 = *((unsigned int *)t70);
    t99 = (~(t98));
    t100 = *((unsigned int *)t84);
    t101 = (~(t100));
    t102 = (t95 & t97);
    t103 = (t99 & t101);
    t104 = (~(t102));
    t105 = (~(t103));
    t106 = *((unsigned int *)t82);
    *((unsigned int *)t82) = (t106 & t104);
    t107 = *((unsigned int *)t82);
    *((unsigned int *)t82) = (t107 & t105);
    t108 = *((unsigned int *)t78);
    *((unsigned int *)t78) = (t108 & t104);
    t109 = *((unsigned int *)t78);
    *((unsigned int *)t78) = (t109 & t105);
    goto LAB199;

LAB200:    *((unsigned int *)t110) = 1;
    goto LAB203;

LAB202:    t93 = (t110 + 4);
    *((unsigned int *)t110) = 1;
    *((unsigned int *)t93) = 1;
    goto LAB203;

LAB204:    t117 = (t0 + 1336U);
    t118 = *((char **)t117);
    memset(t124, 0, 8);
    t117 = (t124 + 4);
    t122 = (t118 + 4);
    t126 = *((unsigned int *)t118);
    t127 = (t126 >> 2);
    t128 = (t127 & 1);
    *((unsigned int *)t124) = t128;
    t129 = *((unsigned int *)t122);
    t130 = (t129 >> 2);
    t131 = (t130 & 1);
    *((unsigned int *)t117) = t131;
    t123 = ((char*)((ng1)));
    memset(t133, 0, 8);
    t125 = (t124 + 4);
    t132 = (t123 + 4);
    t136 = *((unsigned int *)t124);
    t137 = *((unsigned int *)t123);
    t138 = (t136 ^ t137);
    t139 = *((unsigned int *)t125);
    t140 = *((unsigned int *)t132);
    t141 = (t139 ^ t140);
    t142 = (t138 | t141);
    t143 = *((unsigned int *)t125);
    t144 = *((unsigned int *)t132);
    t145 = (t143 | t144);
    t146 = (~(t145));
    t147 = (t142 & t146);
    if (t147 != 0)
        goto LAB210;

LAB207:    if (t145 != 0)
        goto LAB209;

LAB208:    *((unsigned int *)t133) = 1;

LAB210:    memset(t149, 0, 8);
    t135 = (t133 + 4);
    t151 = *((unsigned int *)t135);
    t152 = (~(t151));
    t153 = *((unsigned int *)t133);
    t154 = (t153 & t152);
    t155 = (t154 & 1U);
    if (t155 != 0)
        goto LAB211;

LAB212:    if (*((unsigned int *)t135) != 0)
        goto LAB213;

LAB214:    t158 = *((unsigned int *)t110);
    t159 = *((unsigned int *)t149);
    t160 = (t158 & t159);
    *((unsigned int *)t157) = t160;
    t150 = (t110 + 4);
    t156 = (t149 + 4);
    t161 = (t157 + 4);
    t164 = *((unsigned int *)t150);
    t165 = *((unsigned int *)t156);
    t166 = (t164 | t165);
    *((unsigned int *)t161) = t166;
    t167 = *((unsigned int *)t161);
    t168 = (t167 != 0);
    if (t168 == 1)
        goto LAB215;

LAB216:
LAB217:    goto LAB206;

LAB209:    t134 = (t133 + 4);
    *((unsigned int *)t133) = 1;
    *((unsigned int *)t134) = 1;
    goto LAB210;

LAB211:    *((unsigned int *)t149) = 1;
    goto LAB214;

LAB213:    t148 = (t149 + 4);
    *((unsigned int *)t149) = 1;
    *((unsigned int *)t148) = 1;
    goto LAB214;

LAB215:    t169 = *((unsigned int *)t157);
    t170 = *((unsigned int *)t161);
    *((unsigned int *)t157) = (t169 | t170);
    t162 = (t110 + 4);
    t163 = (t149 + 4);
    t173 = *((unsigned int *)t110);
    t174 = (~(t173));
    t175 = *((unsigned int *)t162);
    t176 = (~(t175));
    t177 = *((unsigned int *)t149);
    t178 = (~(t177));
    t179 = *((unsigned int *)t163);
    t180 = (~(t179));
    t181 = (t174 & t176);
    t182 = (t178 & t180);
    t183 = (~(t181));
    t184 = (~(t182));
    t185 = *((unsigned int *)t161);
    *((unsigned int *)t161) = (t185 & t183);
    t186 = *((unsigned int *)t161);
    *((unsigned int *)t161) = (t186 & t184);
    t187 = *((unsigned int *)t157);
    *((unsigned int *)t157) = (t187 & t183);
    t188 = *((unsigned int *)t157);
    *((unsigned int *)t157) = (t188 & t184);
    goto LAB217;

LAB218:    xsi_set_current_line(37, ng0);
    t172 = (t0 + 968U);
    t189 = *((char **)t172);
    t172 = (t0 + 1564);
    xsi_vlogvar_wait_assign_value(t172, t189, 0, 0, 8, 0LL);
    goto LAB220;

LAB223:    t16 = (t15 + 4);
    *((unsigned int *)t15) = 1;
    *((unsigned int *)t16) = 1;
    goto LAB224;

LAB225:    *((unsigned int *)t31) = 1;
    goto LAB228;

LAB227:    t30 = (t31 + 4);
    *((unsigned int *)t31) = 1;
    *((unsigned int *)t30) = 1;
    goto LAB228;

LAB229:    t38 = (t0 + 1336U);
    t39 = *((char **)t38);
    memset(t45, 0, 8);
    t38 = (t45 + 4);
    t43 = (t39 + 4);
    t47 = *((unsigned int *)t39);
    t48 = (t47 >> 1);
    t49 = (t48 & 1);
    *((unsigned int *)t45) = t49;
    t50 = *((unsigned int *)t43);
    t51 = (t50 >> 1);
    t52 = (t51 & 1);
    *((unsigned int *)t38) = t52;
    t44 = ((char*)((ng1)));
    memset(t54, 0, 8);
    t46 = (t45 + 4);
    t53 = (t44 + 4);
    t57 = *((unsigned int *)t45);
    t58 = *((unsigned int *)t44);
    t59 = (t57 ^ t58);
    t60 = *((unsigned int *)t46);
    t61 = *((unsigned int *)t53);
    t62 = (t60 ^ t61);
    t63 = (t59 | t62);
    t64 = *((unsigned int *)t46);
    t65 = *((unsigned int *)t53);
    t66 = (t64 | t65);
    t67 = (~(t66));
    t68 = (t63 & t67);
    if (t68 != 0)
        goto LAB235;

LAB232:    if (t66 != 0)
        goto LAB234;

LAB233:    *((unsigned int *)t54) = 1;

LAB235:    memset(t70, 0, 8);
    t56 = (t54 + 4);
    t72 = *((unsigned int *)t56);
    t73 = (~(t72));
    t74 = *((unsigned int *)t54);
    t75 = (t74 & t73);
    t76 = (t75 & 1U);
    if (t76 != 0)
        goto LAB236;

LAB237:    if (*((unsigned int *)t56) != 0)
        goto LAB238;

LAB239:    t79 = *((unsigned int *)t31);
    t80 = *((unsigned int *)t70);
    t81 = (t79 & t80);
    *((unsigned int *)t78) = t81;
    t71 = (t31 + 4);
    t77 = (t70 + 4);
    t82 = (t78 + 4);
    t85 = *((unsigned int *)t71);
    t86 = *((unsigned int *)t77);
    t87 = (t85 | t86);
    *((unsigned int *)t82) = t87;
    t88 = *((unsigned int *)t82);
    t89 = (t88 != 0);
    if (t89 == 1)
        goto LAB240;

LAB241:
LAB242:    goto LAB231;

LAB234:    t55 = (t54 + 4);
    *((unsigned int *)t54) = 1;
    *((unsigned int *)t55) = 1;
    goto LAB235;

LAB236:    *((unsigned int *)t70) = 1;
    goto LAB239;

LAB238:    t69 = (t70 + 4);
    *((unsigned int *)t70) = 1;
    *((unsigned int *)t69) = 1;
    goto LAB239;

LAB240:    t90 = *((unsigned int *)t78);
    t91 = *((unsigned int *)t82);
    *((unsigned int *)t78) = (t90 | t91);
    t83 = (t31 + 4);
    t84 = (t70 + 4);
    t94 = *((unsigned int *)t31);
    t95 = (~(t94));
    t96 = *((unsigned int *)t83);
    t97 = (~(t96));
    t98 = *((unsigned int *)t70);
    t99 = (~(t98));
    t100 = *((unsigned int *)t84);
    t101 = (~(t100));
    t102 = (t95 & t97);
    t103 = (t99 & t101);
    t104 = (~(t102));
    t105 = (~(t103));
    t106 = *((unsigned int *)t82);
    *((unsigned int *)t82) = (t106 & t104);
    t107 = *((unsigned int *)t82);
    *((unsigned int *)t82) = (t107 & t105);
    t108 = *((unsigned int *)t78);
    *((unsigned int *)t78) = (t108 & t104);
    t109 = *((unsigned int *)t78);
    *((unsigned int *)t78) = (t109 & t105);
    goto LAB242;

LAB243:    *((unsigned int *)t110) = 1;
    goto LAB246;

LAB245:    t93 = (t110 + 4);
    *((unsigned int *)t110) = 1;
    *((unsigned int *)t93) = 1;
    goto LAB246;

LAB247:    t117 = (t0 + 1336U);
    t118 = *((char **)t117);
    memset(t124, 0, 8);
    t117 = (t124 + 4);
    t122 = (t118 + 4);
    t126 = *((unsigned int *)t118);
    t127 = (t126 >> 2);
    t128 = (t127 & 1);
    *((unsigned int *)t124) = t128;
    t129 = *((unsigned int *)t122);
    t130 = (t129 >> 2);
    t131 = (t130 & 1);
    *((unsigned int *)t117) = t131;
    t123 = ((char*)((ng2)));
    memset(t133, 0, 8);
    t125 = (t124 + 4);
    t132 = (t123 + 4);
    t136 = *((unsigned int *)t124);
    t137 = *((unsigned int *)t123);
    t138 = (t136 ^ t137);
    t139 = *((unsigned int *)t125);
    t140 = *((unsigned int *)t132);
    t141 = (t139 ^ t140);
    t142 = (t138 | t141);
    t143 = *((unsigned int *)t125);
    t144 = *((unsigned int *)t132);
    t145 = (t143 | t144);
    t146 = (~(t145));
    t147 = (t142 & t146);
    if (t147 != 0)
        goto LAB253;

LAB250:    if (t145 != 0)
        goto LAB252;

LAB251:    *((unsigned int *)t133) = 1;

LAB253:    memset(t149, 0, 8);
    t135 = (t133 + 4);
    t151 = *((unsigned int *)t135);
    t152 = (~(t151));
    t153 = *((unsigned int *)t133);
    t154 = (t153 & t152);
    t155 = (t154 & 1U);
    if (t155 != 0)
        goto LAB254;

LAB255:    if (*((unsigned int *)t135) != 0)
        goto LAB256;

LAB257:    t158 = *((unsigned int *)t110);
    t159 = *((unsigned int *)t149);
    t160 = (t158 & t159);
    *((unsigned int *)t157) = t160;
    t150 = (t110 + 4);
    t156 = (t149 + 4);
    t161 = (t157 + 4);
    t164 = *((unsigned int *)t150);
    t165 = *((unsigned int *)t156);
    t166 = (t164 | t165);
    *((unsigned int *)t161) = t166;
    t167 = *((unsigned int *)t161);
    t168 = (t167 != 0);
    if (t168 == 1)
        goto LAB258;

LAB259:
LAB260:    goto LAB249;

LAB252:    t134 = (t133 + 4);
    *((unsigned int *)t133) = 1;
    *((unsigned int *)t134) = 1;
    goto LAB253;

LAB254:    *((unsigned int *)t149) = 1;
    goto LAB257;

LAB256:    t148 = (t149 + 4);
    *((unsigned int *)t149) = 1;
    *((unsigned int *)t148) = 1;
    goto LAB257;

LAB258:    t169 = *((unsigned int *)t157);
    t170 = *((unsigned int *)t161);
    *((unsigned int *)t157) = (t169 | t170);
    t162 = (t110 + 4);
    t163 = (t149 + 4);
    t173 = *((unsigned int *)t110);
    t174 = (~(t173));
    t175 = *((unsigned int *)t162);
    t176 = (~(t175));
    t177 = *((unsigned int *)t149);
    t178 = (~(t177));
    t179 = *((unsigned int *)t163);
    t180 = (~(t179));
    t181 = (t174 & t176);
    t182 = (t178 & t180);
    t183 = (~(t181));
    t184 = (~(t182));
    t185 = *((unsigned int *)t161);
    *((unsigned int *)t161) = (t185 & t183);
    t186 = *((unsigned int *)t161);
    *((unsigned int *)t161) = (t186 & t184);
    t187 = *((unsigned int *)t157);
    *((unsigned int *)t157) = (t187 & t183);
    t188 = *((unsigned int *)t157);
    *((unsigned int *)t157) = (t188 & t184);
    goto LAB260;

LAB261:    xsi_set_current_line(39, ng0);
    t172 = (t0 + 1060U);
    t189 = *((char **)t172);
    t172 = (t0 + 1564);
    xsi_vlogvar_wait_assign_value(t172, t189, 0, 0, 8, 0LL);
    goto LAB263;

LAB266:    t16 = (t15 + 4);
    *((unsigned int *)t15) = 1;
    *((unsigned int *)t16) = 1;
    goto LAB267;

LAB268:    *((unsigned int *)t31) = 1;
    goto LAB271;

LAB270:    t30 = (t31 + 4);
    *((unsigned int *)t31) = 1;
    *((unsigned int *)t30) = 1;
    goto LAB271;

LAB272:    t38 = (t0 + 1336U);
    t39 = *((char **)t38);
    memset(t45, 0, 8);
    t38 = (t45 + 4);
    t43 = (t39 + 4);
    t47 = *((unsigned int *)t39);
    t48 = (t47 >> 1);
    t49 = (t48 & 1);
    *((unsigned int *)t45) = t49;
    t50 = *((unsigned int *)t43);
    t51 = (t50 >> 1);
    t52 = (t51 & 1);
    *((unsigned int *)t38) = t52;
    t44 = ((char*)((ng2)));
    memset(t54, 0, 8);
    t46 = (t45 + 4);
    t53 = (t44 + 4);
    t57 = *((unsigned int *)t45);
    t58 = *((unsigned int *)t44);
    t59 = (t57 ^ t58);
    t60 = *((unsigned int *)t46);
    t61 = *((unsigned int *)t53);
    t62 = (t60 ^ t61);
    t63 = (t59 | t62);
    t64 = *((unsigned int *)t46);
    t65 = *((unsigned int *)t53);
    t66 = (t64 | t65);
    t67 = (~(t66));
    t68 = (t63 & t67);
    if (t68 != 0)
        goto LAB278;

LAB275:    if (t66 != 0)
        goto LAB277;

LAB276:    *((unsigned int *)t54) = 1;

LAB278:    memset(t70, 0, 8);
    t56 = (t54 + 4);
    t72 = *((unsigned int *)t56);
    t73 = (~(t72));
    t74 = *((unsigned int *)t54);
    t75 = (t74 & t73);
    t76 = (t75 & 1U);
    if (t76 != 0)
        goto LAB279;

LAB280:    if (*((unsigned int *)t56) != 0)
        goto LAB281;

LAB282:    t79 = *((unsigned int *)t31);
    t80 = *((unsigned int *)t70);
    t81 = (t79 & t80);
    *((unsigned int *)t78) = t81;
    t71 = (t31 + 4);
    t77 = (t70 + 4);
    t82 = (t78 + 4);
    t85 = *((unsigned int *)t71);
    t86 = *((unsigned int *)t77);
    t87 = (t85 | t86);
    *((unsigned int *)t82) = t87;
    t88 = *((unsigned int *)t82);
    t89 = (t88 != 0);
    if (t89 == 1)
        goto LAB283;

LAB284:
LAB285:    goto LAB274;

LAB277:    t55 = (t54 + 4);
    *((unsigned int *)t54) = 1;
    *((unsigned int *)t55) = 1;
    goto LAB278;

LAB279:    *((unsigned int *)t70) = 1;
    goto LAB282;

LAB281:    t69 = (t70 + 4);
    *((unsigned int *)t70) = 1;
    *((unsigned int *)t69) = 1;
    goto LAB282;

LAB283:    t90 = *((unsigned int *)t78);
    t91 = *((unsigned int *)t82);
    *((unsigned int *)t78) = (t90 | t91);
    t83 = (t31 + 4);
    t84 = (t70 + 4);
    t94 = *((unsigned int *)t31);
    t95 = (~(t94));
    t96 = *((unsigned int *)t83);
    t97 = (~(t96));
    t98 = *((unsigned int *)t70);
    t99 = (~(t98));
    t100 = *((unsigned int *)t84);
    t101 = (~(t100));
    t102 = (t95 & t97);
    t103 = (t99 & t101);
    t104 = (~(t102));
    t105 = (~(t103));
    t106 = *((unsigned int *)t82);
    *((unsigned int *)t82) = (t106 & t104);
    t107 = *((unsigned int *)t82);
    *((unsigned int *)t82) = (t107 & t105);
    t108 = *((unsigned int *)t78);
    *((unsigned int *)t78) = (t108 & t104);
    t109 = *((unsigned int *)t78);
    *((unsigned int *)t78) = (t109 & t105);
    goto LAB285;

LAB286:    *((unsigned int *)t110) = 1;
    goto LAB289;

LAB288:    t93 = (t110 + 4);
    *((unsigned int *)t110) = 1;
    *((unsigned int *)t93) = 1;
    goto LAB289;

LAB290:    t117 = (t0 + 1336U);
    t118 = *((char **)t117);
    memset(t124, 0, 8);
    t117 = (t124 + 4);
    t122 = (t118 + 4);
    t126 = *((unsigned int *)t118);
    t127 = (t126 >> 2);
    t128 = (t127 & 1);
    *((unsigned int *)t124) = t128;
    t129 = *((unsigned int *)t122);
    t130 = (t129 >> 2);
    t131 = (t130 & 1);
    *((unsigned int *)t117) = t131;
    t123 = ((char*)((ng1)));
    memset(t133, 0, 8);
    t125 = (t124 + 4);
    t132 = (t123 + 4);
    t136 = *((unsigned int *)t124);
    t137 = *((unsigned int *)t123);
    t138 = (t136 ^ t137);
    t139 = *((unsigned int *)t125);
    t140 = *((unsigned int *)t132);
    t141 = (t139 ^ t140);
    t142 = (t138 | t141);
    t143 = *((unsigned int *)t125);
    t144 = *((unsigned int *)t132);
    t145 = (t143 | t144);
    t146 = (~(t145));
    t147 = (t142 & t146);
    if (t147 != 0)
        goto LAB296;

LAB293:    if (t145 != 0)
        goto LAB295;

LAB294:    *((unsigned int *)t133) = 1;

LAB296:    memset(t149, 0, 8);
    t135 = (t133 + 4);
    t151 = *((unsigned int *)t135);
    t152 = (~(t151));
    t153 = *((unsigned int *)t133);
    t154 = (t153 & t152);
    t155 = (t154 & 1U);
    if (t155 != 0)
        goto LAB297;

LAB298:    if (*((unsigned int *)t135) != 0)
        goto LAB299;

LAB300:    t158 = *((unsigned int *)t110);
    t159 = *((unsigned int *)t149);
    t160 = (t158 & t159);
    *((unsigned int *)t157) = t160;
    t150 = (t110 + 4);
    t156 = (t149 + 4);
    t161 = (t157 + 4);
    t164 = *((unsigned int *)t150);
    t165 = *((unsigned int *)t156);
    t166 = (t164 | t165);
    *((unsigned int *)t161) = t166;
    t167 = *((unsigned int *)t161);
    t168 = (t167 != 0);
    if (t168 == 1)
        goto LAB301;

LAB302:
LAB303:    goto LAB292;

LAB295:    t134 = (t133 + 4);
    *((unsigned int *)t133) = 1;
    *((unsigned int *)t134) = 1;
    goto LAB296;

LAB297:    *((unsigned int *)t149) = 1;
    goto LAB300;

LAB299:    t148 = (t149 + 4);
    *((unsigned int *)t149) = 1;
    *((unsigned int *)t148) = 1;
    goto LAB300;

LAB301:    t169 = *((unsigned int *)t157);
    t170 = *((unsigned int *)t161);
    *((unsigned int *)t157) = (t169 | t170);
    t162 = (t110 + 4);
    t163 = (t149 + 4);
    t173 = *((unsigned int *)t110);
    t174 = (~(t173));
    t175 = *((unsigned int *)t162);
    t176 = (~(t175));
    t177 = *((unsigned int *)t149);
    t178 = (~(t177));
    t179 = *((unsigned int *)t163);
    t180 = (~(t179));
    t181 = (t174 & t176);
    t182 = (t178 & t180);
    t183 = (~(t181));
    t184 = (~(t182));
    t185 = *((unsigned int *)t161);
    *((unsigned int *)t161) = (t185 & t183);
    t186 = *((unsigned int *)t161);
    *((unsigned int *)t161) = (t186 & t184);
    t187 = *((unsigned int *)t157);
    *((unsigned int *)t157) = (t187 & t183);
    t188 = *((unsigned int *)t157);
    *((unsigned int *)t157) = (t188 & t184);
    goto LAB303;

LAB304:    xsi_set_current_line(41, ng0);
    t172 = (t0 + 1152U);
    t189 = *((char **)t172);
    t172 = (t0 + 1564);
    xsi_vlogvar_wait_assign_value(t172, t189, 0, 0, 8, 0LL);
    goto LAB306;

LAB309:    t16 = (t15 + 4);
    *((unsigned int *)t15) = 1;
    *((unsigned int *)t16) = 1;
    goto LAB310;

LAB311:    *((unsigned int *)t31) = 1;
    goto LAB314;

LAB313:    t30 = (t31 + 4);
    *((unsigned int *)t31) = 1;
    *((unsigned int *)t30) = 1;
    goto LAB314;

LAB315:    t38 = (t0 + 1336U);
    t39 = *((char **)t38);
    memset(t45, 0, 8);
    t38 = (t45 + 4);
    t43 = (t39 + 4);
    t47 = *((unsigned int *)t39);
    t48 = (t47 >> 1);
    t49 = (t48 & 1);
    *((unsigned int *)t45) = t49;
    t50 = *((unsigned int *)t43);
    t51 = (t50 >> 1);
    t52 = (t51 & 1);
    *((unsigned int *)t38) = t52;
    t44 = ((char*)((ng2)));
    memset(t54, 0, 8);
    t46 = (t45 + 4);
    t53 = (t44 + 4);
    t57 = *((unsigned int *)t45);
    t58 = *((unsigned int *)t44);
    t59 = (t57 ^ t58);
    t60 = *((unsigned int *)t46);
    t61 = *((unsigned int *)t53);
    t62 = (t60 ^ t61);
    t63 = (t59 | t62);
    t64 = *((unsigned int *)t46);
    t65 = *((unsigned int *)t53);
    t66 = (t64 | t65);
    t67 = (~(t66));
    t68 = (t63 & t67);
    if (t68 != 0)
        goto LAB321;

LAB318:    if (t66 != 0)
        goto LAB320;

LAB319:    *((unsigned int *)t54) = 1;

LAB321:    memset(t70, 0, 8);
    t56 = (t54 + 4);
    t72 = *((unsigned int *)t56);
    t73 = (~(t72));
    t74 = *((unsigned int *)t54);
    t75 = (t74 & t73);
    t76 = (t75 & 1U);
    if (t76 != 0)
        goto LAB322;

LAB323:    if (*((unsigned int *)t56) != 0)
        goto LAB324;

LAB325:    t79 = *((unsigned int *)t31);
    t80 = *((unsigned int *)t70);
    t81 = (t79 & t80);
    *((unsigned int *)t78) = t81;
    t71 = (t31 + 4);
    t77 = (t70 + 4);
    t82 = (t78 + 4);
    t85 = *((unsigned int *)t71);
    t86 = *((unsigned int *)t77);
    t87 = (t85 | t86);
    *((unsigned int *)t82) = t87;
    t88 = *((unsigned int *)t82);
    t89 = (t88 != 0);
    if (t89 == 1)
        goto LAB326;

LAB327:
LAB328:    goto LAB317;

LAB320:    t55 = (t54 + 4);
    *((unsigned int *)t54) = 1;
    *((unsigned int *)t55) = 1;
    goto LAB321;

LAB322:    *((unsigned int *)t70) = 1;
    goto LAB325;

LAB324:    t69 = (t70 + 4);
    *((unsigned int *)t70) = 1;
    *((unsigned int *)t69) = 1;
    goto LAB325;

LAB326:    t90 = *((unsigned int *)t78);
    t91 = *((unsigned int *)t82);
    *((unsigned int *)t78) = (t90 | t91);
    t83 = (t31 + 4);
    t84 = (t70 + 4);
    t94 = *((unsigned int *)t31);
    t95 = (~(t94));
    t96 = *((unsigned int *)t83);
    t97 = (~(t96));
    t98 = *((unsigned int *)t70);
    t99 = (~(t98));
    t100 = *((unsigned int *)t84);
    t101 = (~(t100));
    t102 = (t95 & t97);
    t103 = (t99 & t101);
    t104 = (~(t102));
    t105 = (~(t103));
    t106 = *((unsigned int *)t82);
    *((unsigned int *)t82) = (t106 & t104);
    t107 = *((unsigned int *)t82);
    *((unsigned int *)t82) = (t107 & t105);
    t108 = *((unsigned int *)t78);
    *((unsigned int *)t78) = (t108 & t104);
    t109 = *((unsigned int *)t78);
    *((unsigned int *)t78) = (t109 & t105);
    goto LAB328;

LAB329:    *((unsigned int *)t110) = 1;
    goto LAB332;

LAB331:    t93 = (t110 + 4);
    *((unsigned int *)t110) = 1;
    *((unsigned int *)t93) = 1;
    goto LAB332;

LAB333:    t117 = (t0 + 1336U);
    t118 = *((char **)t117);
    memset(t124, 0, 8);
    t117 = (t124 + 4);
    t122 = (t118 + 4);
    t126 = *((unsigned int *)t118);
    t127 = (t126 >> 2);
    t128 = (t127 & 1);
    *((unsigned int *)t124) = t128;
    t129 = *((unsigned int *)t122);
    t130 = (t129 >> 2);
    t131 = (t130 & 1);
    *((unsigned int *)t117) = t131;
    t123 = ((char*)((ng2)));
    memset(t133, 0, 8);
    t125 = (t124 + 4);
    t132 = (t123 + 4);
    t136 = *((unsigned int *)t124);
    t137 = *((unsigned int *)t123);
    t138 = (t136 ^ t137);
    t139 = *((unsigned int *)t125);
    t140 = *((unsigned int *)t132);
    t141 = (t139 ^ t140);
    t142 = (t138 | t141);
    t143 = *((unsigned int *)t125);
    t144 = *((unsigned int *)t132);
    t145 = (t143 | t144);
    t146 = (~(t145));
    t147 = (t142 & t146);
    if (t147 != 0)
        goto LAB339;

LAB336:    if (t145 != 0)
        goto LAB338;

LAB337:    *((unsigned int *)t133) = 1;

LAB339:    memset(t149, 0, 8);
    t135 = (t133 + 4);
    t151 = *((unsigned int *)t135);
    t152 = (~(t151));
    t153 = *((unsigned int *)t133);
    t154 = (t153 & t152);
    t155 = (t154 & 1U);
    if (t155 != 0)
        goto LAB340;

LAB341:    if (*((unsigned int *)t135) != 0)
        goto LAB342;

LAB343:    t158 = *((unsigned int *)t110);
    t159 = *((unsigned int *)t149);
    t160 = (t158 & t159);
    *((unsigned int *)t157) = t160;
    t150 = (t110 + 4);
    t156 = (t149 + 4);
    t161 = (t157 + 4);
    t164 = *((unsigned int *)t150);
    t165 = *((unsigned int *)t156);
    t166 = (t164 | t165);
    *((unsigned int *)t161) = t166;
    t167 = *((unsigned int *)t161);
    t168 = (t167 != 0);
    if (t168 == 1)
        goto LAB344;

LAB345:
LAB346:    goto LAB335;

LAB338:    t134 = (t133 + 4);
    *((unsigned int *)t133) = 1;
    *((unsigned int *)t134) = 1;
    goto LAB339;

LAB340:    *((unsigned int *)t149) = 1;
    goto LAB343;

LAB342:    t148 = (t149 + 4);
    *((unsigned int *)t149) = 1;
    *((unsigned int *)t148) = 1;
    goto LAB343;

LAB344:    t169 = *((unsigned int *)t157);
    t170 = *((unsigned int *)t161);
    *((unsigned int *)t157) = (t169 | t170);
    t162 = (t110 + 4);
    t163 = (t149 + 4);
    t173 = *((unsigned int *)t110);
    t174 = (~(t173));
    t175 = *((unsigned int *)t162);
    t176 = (~(t175));
    t177 = *((unsigned int *)t149);
    t178 = (~(t177));
    t179 = *((unsigned int *)t163);
    t180 = (~(t179));
    t181 = (t174 & t176);
    t182 = (t178 & t180);
    t183 = (~(t181));
    t184 = (~(t182));
    t185 = *((unsigned int *)t161);
    *((unsigned int *)t161) = (t185 & t183);
    t186 = *((unsigned int *)t161);
    *((unsigned int *)t161) = (t186 & t184);
    t187 = *((unsigned int *)t157);
    *((unsigned int *)t157) = (t187 & t183);
    t188 = *((unsigned int *)t157);
    *((unsigned int *)t157) = (t188 & t184);
    goto LAB346;

LAB347:    xsi_set_current_line(43, ng0);
    t172 = (t0 + 1244U);
    t189 = *((char **)t172);
    t172 = (t0 + 1564);
    xsi_vlogvar_wait_assign_value(t172, t189, 0, 0, 8, 0LL);
    goto LAB349;

}


extern void work_m_00000000001078796743_2817161947_init()
{
	static char *pe[] = {(void *)Always_26_0};
	xsi_register_didat("work_m_00000000001078796743_2817161947", "isim/TinyCpuTester_isim_beh.exe.sim/work/m_00000000001078796743_2817161947.didat");
	xsi_register_executes(pe);
}
