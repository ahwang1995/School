#!/usr/bin/env python
""" generated source for module BayesianNetwork """
#from Assignment4 import *
from Assignment4 import Node,Edge,CPT,RandomVariable,Sample
import random
# 
#  * A bayesian network
#  * @author Panqu
#  
class BayesianNetwork(object):
    """ generated source for class BayesianNetwork """
    # 
    #     * Mapping of random variabless to nodes in the network
    #     
    varMap = None

    # 
    #     * Edges in this network
    #     
    edges = None

    # 
    #     * Nodes in the network with no parents
    #     
    rootNodes = None

    # 
    #     * Default constructor initializes empty network
    #     
    def __init__(self):
        """ generated source for method __init__ """
        self.varMap = {}
        self.edges = []
        self.rootNodes = []

    # 
    #     * Add a random variables to this network
    #     * @param variables Variable to add
    #     
    def addVariable(self, variables):
        """ generated source for method addVariable """
        node = Node(variables)
        self.varMap[variables]=node
        self.rootNodes.append(node)

    # 
    #     * Add a new edge between two random variabless already in this network
    #     * @param cause Parent/source node
    #     * @param effect Child/destination node
    #     
    def addEdge(self, cause, effect):
        """ generated source for method addEdge """
        source = self.varMap.get(cause)
        dest = self.varMap.get(effect)
        self.edges.append(Edge(source, dest))
        source.addChild(dest)
        dest.addParent(source)
        if dest in self.rootNodes:
            self.rootNodes.remove(dest)

    # 
    #     * Sets the CPT variables in the bayesian network (actualProbability of
    #     * this variables given its parents)
    #     * @param variables Variable whose CPT we are setting
    #     * @param probabilities List of probabilities P(V=true|P1,P2...), that must be ordered as follows.
    #       Write out the cpt by hand, with each column representing one of the parents (in alphabetical order).
    #       Then assign these parent variabless true/false based on the following order: ...tt, ...tf, ...ft, ...ff.
    #       The assignedVals in the right most column, P(V=true|P1,P2,...), will be the values you should pass in as probabilities here.
    #     
    def setProbabilities(self, variables, probabilities):
        """ generated source for method setProbabilities """
        probList = []
        for actualProbability in probabilities:
            probList.append(actualProbability)
        self.varMap.get(variables).setProbabilities(probList)

    # 
    #     * Returns an estimate of P(queryVal=true|givenVars) using rejection sampling
    #     * @param queryVar Query variables in probability query
    #     * @param givenVars A list of assignments to variables that represent our given evidence variables
    #     * @param numSamples Number of rejection samples to perform
    #     
    def performRejectionSampling(self, queryVar, givenVars, numSamples):
        """ generated source for method performRejectionSampling """
        probability1 = 0
        probability2 = 0
        allVars = self.varMap

        for variables in range(1, numSamples, 1):
            
            varSum = 0
            sortedVars = sorted(allVars)
            assignedVals = {}

            for variables in sortedVars:

                name = variables.getName()
                singleVar = allVars.get(variables,0)
                actualProbability = singleVar.getProbability(assignedVals, True)

                generate = random.random()
                if generate <= 1 and generate >= 0 and generate <= actualProbability:
                    assignedVals[name] = 1
                if generate <= 1 and generate >= 0 and generate > actualProbability:
                    assignedVals[name] = 0

            comparison = True
            for i in givenVars:
                name = i.getName()
                if givenVars[i] != assignedVals[name]:
                    comparison = False

            if comparison == False:
                continue
            if assignedVals[queryVar.getName()] == True:
                probability1 = probability1 + 1
            else:
                probability2 = probability2 + 1

        
        for i in [probability1, probability2]:
            varSum = varSum + i

        if varSum != 0:
            estimate1 = float(probability1)/varSum
            estimate2 = float(probability2)/varSum
            return [estimate1, estimate2]
        else:
            return [0, 0]

    # 
    #     * Returns an estimate of P(queryVal=true|givenVars) using weighted sampling
    #     * @param queryVar Query variables in actualProbability query
    #     * @param givenVars A list of assignedVals to variabless that represent our given comparison variabless
    #     * @param numSamples Number of weighted samples to perform
    #     
    def performWeightedSampling(self, queryVar, givenVars, numSamples):
        """ generated source for method performWeightedSampling """
        #  TODO
        W1 = 0
        W2 = 0
        for i in range(1, numSamples, 1):
            x,w = WeightedSample(self,givenVars)
            if x[queryVar.getName()]:
                W1 += w
            else:
                W2 += w
        estimate = float(W1)/(float(W1) + float(W2))
        return estimate
        
    # 
    #     * Returns an estimate of P(queryVal=true|givenVars) using Gibbs sampling
    #     * @param queryVar Query variables in actualProbability query
    #     * @param givenVars A list of assignedVals to variabless that represent our given comparison variabless
    #     * @param numTrials Number of Gibbs trials to perform, where a single trial consists of assignedVals to ALL
    #       non-comparison variabless (ie. not a single state change, but a state change of all non-comparison variabless)
    #     
    def performGibbsSampling(self, queryVar, givenVars, numTrials):
        """ generated source for method performGibbsSampling """
        #  TODO
        trueCount = 0
        falseCount = 0

        """ initially randomly assign values to variables """
        values = {}
        for var in self.varMap:
            if var in givenVars:
                """ don't change givenVars values """
            else:
                if( random.random() <= 0.5 ):
                    values[var] = True
                else:
                    values[var] = False

        """ sample nodes according to their markov blanket """
        for i in range(0, numTrials):
            """ choose node at random and change its value based on its prob """
            var = random.choice(list(values.keys()))
            prob1 = self.MB(var, True, dict(givenVars.items() + values.items()))
            prob2 = self.MB(var, False, dict(givenVars.items() + values.items()))
            if prob1 + prob2 != 0:
                prob = prob1 / (prob1 + prob2)
            else:
                prob = 0
            if( random.random() <= prob ):
                values[var] = True
            else:
                values[var] = False
            """ count queryVar """
            if( values[queryVar] == True ):
                trueCount += 1
            else:
                falseCount += 1

        """ normalise probability """
        result = float(trueCount) / (trueCount + falseCount)
        return result

    def MB(self, X, x, assignments):
        """ x is a value in variable X """
        """ get the parents and their values as a dictionary, little bit awkward """
        var = self.varMap[X]
        parentVars = [ p.getVariable() for p in var.getParents() ]
        parentVals = { key: assignments[key] for key in parentVars }
        """ get the probability of the parents """
        pParents = var.getProbability(parentVals, x)
        pChildren = 1
        assignments[X] = x
        for C in var.getChildren():
            """ check if C is in evidence
            if C.getVariable() in evidence:
                pChildren *= int(evidence[C.getVariable()] == True)
                continue """
            """ get the parents of EACH child and their values as a dictionary """
            childParentVars = [ p.getVariable() for p in C.getParents() ]
            childParentVals = { key: assignments[key] for key in childParentVars }
            """childParentVals.pop(X, None)"""
            """ get the probability of the parents """
            pChildren *= C.getProbability(childParentVals, assignments[C.getVariable()])
        """ multiply it all together """
        return pParents * pChildren

def WeightedSample(self,givenVars):
    weight = 1.0
    x = {}
    allVars = self.varMap
    sortedVars = sorted(allVars)
    for var in sortedVars:
        name = var.getName()
        singleVar = allVars.get(var,0)
        if var in givenVars:
            weight = weight * singleVar.getProbability(x,givenVars[var])
            x[name] = givenVars[var]
        else:
            actualProbability = singleVar.getProbability(x, True)
            generate = random.random()
            if generate <= 1 and generate >= 0 and generate <= actualProbability:
                x[name] = 1
            if generate <= 1 and generate >= 0 and generate > actualProbability:
                x[name] = 0
    return x,weight