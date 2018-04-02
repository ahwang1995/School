# multiAgents.py
# --------------
# Licensing Information:  You are free to use or extend these projects for
# educational purposes provided that (1) you do not distribute or publish
# solutions, (2) you retain this notice, and (3) you provide clear
# attribution to UC Berkeley, including a link to http://ai.berkeley.edu.
# 
# Attribution Information: The Pacman AI projects were developed at UC Berkeley.
# The core projects and autograders were primarily created by John DeNero
# (denero@cs.berkeley.edu) and Dan Klein (klein@cs.berkeley.edu).
# Student side autograding was added by Brad Miller, Nick Hay, and
# Pieter Abbeel (pabbeel@cs.berkeley.edu).


from util import manhattanDistance
from game import Directions
import random, util

from game import Agent

class ReflexAgent(Agent):
    """
      A reflex agent chooses an action at each choice point by examining
      its alternatives via a state evaluation function.

      The code below is provided as a guide.  You are welcome to change
      it in any way you see fit, so long as you don't touch our method
      headers.
    """


    def getAction(self, gameState):
        """
        You do not need to change this method, but you're welcome to.

        getAction chooses among the best options according to the evaluation function.

        Just like in the previous project, getAction takes a GameState and returns
        some Directions.X for some X in the set {North, South, West, East, Stop}
        """
        # Collect legal moves and successor states
        legalMoves = gameState.getLegalActions()

        # Choose one of the best actions
        scores = [self.evaluationFunction(gameState, action) for action in legalMoves]
        bestScore = max(scores)
        bestIndices = [index for index in range(len(scores)) if scores[index] == bestScore]
        chosenIndex = random.choice(bestIndices) # Pick randomly among the best

        "Add more of your code here if you want to"

        return legalMoves[chosenIndex]

    def evaluationFunction(self, currentGameState, action):
        """
        Design a better evaluation function here.

        The evaluation function takes in the current and proposed successor
        GameStates (pacman.py) and returns a number, where higher numbers are better.

        The code below extracts some useful information from the state, like the
        remaining food (newFood) and Pacman position after moving (newPos).
        newScaredTimes holds the number of moves that each ghost will remain
        scared because of Pacman having eaten a power pellet.

        Print out these variables to see what you're getting, then combine them
        to create a masterful evaluation function.
        """
        # Useful information you can extract from a GameState (pacman.py)
        successorGameState = currentGameState.generatePacmanSuccessor(action)
        newPos = successorGameState.getPacmanPosition()
        oldPos = currentGameState.getPacmanPosition()
        newFood = successorGameState.getFood()
        oldFood = currentGameState.getFood()  
        newGhostStates = successorGameState.getGhostStates()
        newScaredTimes = [ghostState.scaredTimer for ghostState in newGhostStates]
        newfoodNum = successorGameState.getNumFood()
        oldfoodNum = currentGameState.getNumFood()
        ghostPos = successorGameState.getGhostPosition(1)

        totalPoints = 0
        mod1 = 100
        mod2 = 3
        foodLocation = mod1

        allFood = []
        allFood = newFood.asList()
        for i in allFood:
            if (foodLocation >= manhattanDistance(i, newPos)):
                foodLocation = manhattanDistance(i, newPos)
        foodLocation = -mod2 * foodLocation

        ghostLocation = manhattanDistance(ghostPos, newPos)
        if (ghostLocation < mod2):
            totalPoints = ghostLocation + successorGameState.getScore()
        else:
            totalPoints = mod2 + successorGameState.getScore()
                
        if (oldfoodNum > newfoodNum):
            totalPoints = totalPoints + mod1                      
            totalPoints = totalPoints + foodLocation
        else:
            totalPoints = totalPoints + foodLocation
            
        return totalPoints

        #return gameNumber #successorGameState.getScore()
        
def scoreEvaluationFunction(currentGameState):
    """
      This default evaluation function just returns the score of the state.
      The score is the same one displayed in the Pacman GUI.

      This evaluation function is meant for use with adversarial search agents
      (not reflex agents).
    """
    return currentGameState.getScore()

class MultiAgentSearchAgent(Agent):
    """
      This class provides some common elements to all of your
      multi-agent searchers.  Any methods defined here will be available
      to the MinimaxPacmanAgent, AlphaBetaPacmanAgent & ExpectimaxPacmanAgent.

      You *do not* need to make any changes here, but you can if you want to
      add functionality to all your adversarial search agents.  Please do not
      remove anything, however.

      Note: this is an abstract class: one that should not be instantiated.  It's
      only partially specified, and designed to be extended.  Agent (game.py)
      is another abstract class.
    """

    def __init__(self, evalFn = 'scoreEvaluationFunction', depth = '2'):
        self.index = 0 # Pacman is always agent index 0
        self.evaluationFunction = util.lookup(evalFn, globals())
        self.depth = int(depth)
def isTerminal(gameState):
                return (len(gameState.getLegalActions(0)) == 0)
def miniMax(gameState, depth, evalFunc, playerIndex):
    if playerIndex != 0:
        maximisingPlayer = False
    else:
        maximisingPlayer = True
        depth -= 1
    nextPlayer = (playerIndex+1)%gameState.getNumAgents()

    if (depth == 0 or isTerminal(gameState)):
        return evalFunc(gameState)
    if maximisingPlayer:
        v = -999999
        children = gameState.getLegalActions(playerIndex)
        for i in range(0,len(children)):
            v = max(v, miniMax(gameState.generateSuccessor(playerIndex,children[i]), 
                depth, evalFunc, nextPlayer))
        return v
    else:
        v = 999999
        children = gameState.getLegalActions(playerIndex)
        for i in range(0,len(children)):
            v = min(v, miniMax(gameState.generateSuccessor(playerIndex,children[i]), 
                depth, evalFunc, nextPlayer))
        return v
class MinimaxAgent(MultiAgentSearchAgent):
    """
      Your minimax agent (question 2)
    """
    
    def getAction(self, gameState):
        """
          Returns the minimax action from the current gameState using self.depth
          and self.evaluationFunction.

          Here are some method calls that might be useful when implementing minimax.

          gameState.getLegalActions(agentIndex):
            Returns a list of legal actions for an agent
            agentIndex=0 means Pacman, ghosts are >= 1

          gameState.generateSuccessor(agentIndex, action):
            Returns the successor game state after an agent takes an action

          gameState.getNumAgents():
            Returns the total number of agents in the game
        """
        "*** YOUR CODE HERE ***"
        children = gameState.getLegalActions(0)
        v = -999999
        currAction = 0
        for i in range(0,len(children)):
            value = miniMax(gameState.generateSuccessor(0,children[i]), 
                self.depth, self.evaluationFunction, 1)
            if(value > v):
                currAction = children[i]
                v = value
        return currAction
        
        """util.raiseNotDefined()"""
def alphabeta(gameState, depth,alpha,beta, evalFunc, playerIndex):
    if playerIndex != 0:
        maximisingPlayer = False
    else:
        maximisingPlayer = True
        depth -= 1
    nextPlayer = (playerIndex+1)%gameState.getNumAgents()

    if (depth == 0 or isTerminal(gameState)):
        return evalFunc(gameState)
    if maximisingPlayer:
        v = -999999
        children = gameState.getLegalActions(playerIndex)
        for i in range(0,len(children)):
            v = max(v, alphabeta(gameState.generateSuccessor(playerIndex,children[i]), 
                depth,alpha,beta, evalFunc, nextPlayer))
            if v > beta:
                return v 
            alpha = max(alpha,v)
        return v
    else:
        v = 999999
        children = gameState.getLegalActions(playerIndex)
        for i in range(0,len(children)):
            v = min(v, alphabeta(gameState.generateSuccessor(playerIndex,children[i]), 
                depth,alpha,beta, evalFunc, nextPlayer))
            if v < alpha:
                return v
            beta = min(beta,v)
        return v
class AlphaBetaAgent(MultiAgentSearchAgent):
    """
      Your minimax agent with alpha-beta pruning (question 3)
    """

    def getAction(self, gameState):
        """
          Returns the minimax action using self.depth and self.evaluationFunction
        """
        "*** YOUR CODE HERE ***"
        alpha = -99999
        beta = 99999
        children = gameState.getLegalActions(0)
        v = -999999
        currAction = 0
        for i in range(0,len(children)):
            value = alphabeta(gameState.generateSuccessor(0,children[i]), 
                self.depth,alpha,beta, self.evaluationFunction, 1)
            if(value > v):
                currAction = children[i]
                v = value
            if value > beta:
                return v
            alpha = max(alpha,value)
        return currAction
def expectimax(gameState, depth, evalFunc, playerIndex):
    if playerIndex != 0:
        maximisingPlayer = False
    else:
        maximisingPlayer = True
        depth -= 1
    nextPlayer = (playerIndex+1)%gameState.getNumAgents()

    if (depth == 0 or isTerminal(gameState)):
        return evalFunc(gameState)
    if maximisingPlayer:
        v = -999999.0
        children = gameState.getLegalActions(playerIndex)
        for i in range(0,len(children)):
            v = max(v, expectimax(gameState.generateSuccessor(playerIndex,children[i]), 
                depth, evalFunc, nextPlayer))
        return v
    else:
        v = 999999.0
        expectival = 0.0
        children = gameState.getLegalActions(playerIndex)
        for i in range(0,len(children)):
            v = expectimax(gameState.generateSuccessor(playerIndex,children[i]), 
                depth, evalFunc, nextPlayer)
            expectival = expectival + v
        expectival = 1.0*(expectival)/len(children)
            
        return expectival
class ExpectimaxAgent(MultiAgentSearchAgent):
    """
      Your expectimax agent (question 4)
    """

    def getAction(self, gameState):
        """
          Returns the expectimax action using self.depth and self.evaluationFunction

          All ghosts should be modeled as choosing uniformly at random from their
          legal moves.
        """
        "*** YOUR CODE HERE ***"
        children = gameState.getLegalActions(0)
        v = -999999.0
        currAction = 0.0
        for i in range(0,len(children)):
            value = expectimax(gameState.generateSuccessor(0,children[i]), 
                self.depth, self.evaluationFunction, 1)
            if(value > v):
                currAction = children[i]
                v = value
        return currAction

def betterEvaluationFunction(currentGameState):
    """
      Your extreme ghost-hunting, pellet-nabbing, food-gobbling, unstoppable
      evaluation function (question 5).
      DESCRIPTION: <write something here so we know what you did>
    """
    "*** YOUR CODE HERE ***"
    
    #from util import PriorityQueue 

    totalPoints= 0
    maxNeg = -99999
    maxPos = 99999
    pointMod = 10;

    allGhosts = []
    position = currentGameState.getPacmanPosition()
    currGhostPos =  currentGameState.getGhostPositions()
    currGhostStates = currentGameState.getGhostStates()
    gameScore = currentGameState.getScore()

    scareTimer = [ghostState.scaredTimer for ghostState in currGhostStates]
    maxScareTimer = max(scareTimer)

    for eachGhost in currGhostPos:
        allGhosts.append(manhattanDistance(position, eachGhost))

    nearbyGhost = min(allGhosts)

    """if scareTimer > 0:
        isScared = True 
    else: 
        isScared = False"""

    if nearbyGhost < 1: 
        totalPoints = maxNeg
    else:
        totalPoints = pointMod*1/nearbyGhost

    """if isScared == True:
        if nearbyGhost < maxScareTimer:
            mod1 = maxPos"""

    totalPoints = pointMod*totalPoints + gameScore

    return totalPoints

    #util.raiseNotDefined()

# Abbreviation"""
better = betterEvaluationFunction