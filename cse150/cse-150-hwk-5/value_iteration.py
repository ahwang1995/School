class ValueIterator(object):
    matrices = None
    rewards = None
    gamma = None

    def __init__(self):
        """Set up MDP"""

        """
        0 - North 
        1 - South 
        2 - East 
        3 - West 
        """

        """Read in the probabilities into matrices (one for each direction)"""
        self.matrices = []
        self.matrices.append([[0.0 for x in xrange(81)] for y in xrange(81)])
        self.matrices.append([[0.0 for x in xrange(81)] for y in xrange(81)])
        self.matrices.append([[0.0 for x in xrange(81)] for y in xrange(81)])
        self.matrices.append([[0.0 for x in xrange(81)] for y in xrange(81)])

        f = []
        f.append(open('assignment5_data/prob_north.txt', 'r'))
        f.append(open('assignment5_data/prob_south.txt', 'r'))
        f.append(open('assignment5_data/prob_east.txt', 'r'))
        f.append(open('assignment5_data/prob_west.txt', 'r'))

        for a in range(0,3):
            for line in f[a].readlines():
                s, s_, prob = map(float,line.strip().split())
                self.matrices[a][int(s) - 1][int(s_) - 1] = prob

        """Read in rewards"""
        self.rewards = []
        f = open('assignment5_data/rewards.txt', 'r')
        for line in f.readlines():
                r = float(line.strip())
                self.rewards.append(r)

        self.gamma = 0.99

    def value_iteration(self):
        U = [0.0 for x in xrange(81)]
        U_ = [0.0 for x in xrange(81)]
        pi = [0.0 for x in xrange(81)]
        while True:
            U = U_[:]
            for s in xrange(81):
                maxa = -9999;
                """Find a that maximises the expression"""
                for a in xrange(4):
                    suma = 0;
                    for s_ in xrange(81):
                        suma += self.matrices[a][s][s_] * U[s_]
                    if suma > maxa:
                        maxa = suma
                        pi[s] = a
                """Update U_[s]"""
                U_[s] = self.rewards[s] + (self.gamma * maxa)
            """Stop iterating when U'[S] = U[S] for all S"""
            if (U_ == U):
                break
        return (U , pi)

class Main(object):
    @classmethod
    def main(cls, args):
        VI = ValueIterator()
        (U, pi) = VI.value_iteration()
        
        for s in xrange(81):
            if U[s] > 0.0:
                print "(" + str(s+1) + ", " + str(U[s]) + ", " + getDirection(pi[s]) + ")"

def getDirection(d):
    if d == 0:
        return "NORTH"
    if d == 1:
        return "SOUTH"
    if d == 2:
        return "EAST"
    if d == 3:
        return "WEST"

import sys
Main.main(sys.argv)