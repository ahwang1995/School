# -*- coding: utf-8 -*-

from collections import deque


def inference(csp, variable):
    """Performs an inference procedure for the variable assignment.

    For P6, *you do not need to modify this method.*
    """
    return ac3(csp, csp.constraints[variable].arcs())


def backtracking_search(csp):
    """Entry method for the CSP solver.  This method calls the backtrack method to solve the given CSP.

    If there is a solution, this method returns the successful assignment (a dictionary of variable to value);
    otherwise, it returns None.

    For P6, *you do not need to modify this method.*
    """
    if backtrack(csp):
        return csp.assignment
    else:
        return None


def backtrack(csp):
    """Performs the backtracking search for the given csp.

    If there is a solution, this method returns True; otherwise, it returns False.
    """
    if (is_complete(csp)): return True
    vari = select_unassigned_variable(csp)
    for val in order_domain_values(csp,vari):
# Do whatever you need with the variables (assignment , domain reductions)
        if (is_consistent(csp,vari,val)):
            csp.variables.begin_transaction()
            vari.assign(val)
            inference(csp,vari)
            result = backtrack(csp)
            if (result != False):
                return result
            csp.variables.rollback() # This undoes everything from the start of the transaction
    return False
    # TODO implement this
    pass


def ac3(csp, arcs=None):
    """Executes the AC3 or the MAC (p.218 of the textbook) algorithms.

    If the parameter 'arcs' is None, then this method executes AC3 - that is, it will check the arc consistency
    for all arcs in the CSP.  Otherwise, this method starts with only the arcs present in the 'arcs' parameter
    in the queue.

    Note that the current domain of each variable can be retrieved by 'variable.domains'.

    This method returns True if the arc consistency check succeeds, and False otherwise.  Note that this method does not
    return any additional variable assignments (for simplicity)."""

    queue_arcs = deque(arcs if arcs is not None else csp.constraints.arcs())

    while queue_arcs:
        arcval = queue_arcs.popleft()
        if revise(csp,arcval[0],arcval[1]):
            if(len(arcval[0].domain) == 0):
                return False
            for x in csp.constraints[arcval[0]].arcs():
                if x[0] != arcval[1] and x[1] != arcval[1]:
                    queue_arcs.append(x)

    return True

    # TODO implement this
    pass

def Yconst(csp, x, xi, xj):
    for y in xj.domain:
        for constraint in csp.constraints[xi,xj]:
            if (constraint.is_satisfied(x, y)):
                return True
    return False
    
def revise(csp, xi, xj):
    #return true if a value is revised
    # You may additionally want to implement the 'revise' method.
    revise = False;
    for x in xi.domain:
        flag = Yconst(csp, x, xi, xj)
        if(flag == False):
            xi.domain.remove(x)
            revise = True;
    return revise
    pass

def is_complete(csp):
    """Returns True when the CSP assignment is complete, i.e. all of the variables in the CSP have values assigned."""

    # Hint: The list of all variables for the CSP can be obtained by csp.variables.
    # Also, if the variable is assigned, variable.is assigned() will be True.
    # (Note that this can happen either by explicit assignment using variable.assign(value),
    # or when the domain of the variable has been reduced to a single value.)

    # TODO implement this
    for var in csp.variables:
        if var.is_assigned() == False:
            return False
    for var in csp.variables:
        if var.is_assigned() != False:
            return True

    pass
def select_unassigned_variable(csp):
    """Selects the next unassigned variable, or None if there is no more unassigned variables
    (i.e. the assignment is complete).

    This method implements the minimum-remaining-values (MRV) and degree heuristic. That is,
    the variable with the smallest number of values left in its available domain.  If MRV ties,
    then it picks the variable that is involved in the largest number of constraints on other
    unassigned variables.
    """
    # TODO implement this
    unassigned_vars = [variable for variable in csp.variables if not variable.is_assigned()];
    next = None
    least = 9999
    ties = []

    #Check each var's domain
    for var in unassigned_vars:
        domain = len([value for value in var.domain])
        if domain < least:
            ties = []
            least = domain
            next = var
        if domain == least:
            ties.append(var)

    #If no ties return the one with the smallest domain
    if len(ties) == 0:
        return next

    most = -9999
    ties.append(next)

    #Find the one with the most constraints with unassigned vars
    for varX in ties:
        count = 0
        for varY in unassigned_vars:
            count += len(csp.constraints[varX, varY])
        if( count > most ):
            most = count
            next = varX

    return next
    
    pass

def order_domain_values(csp, variable):
    """Returns a list of (ordered) domain values for the given variable.

    This method implements the least-constraining-value (LCV) heuristic; that is, the value
    that rules out the fewest choices for the neighboring variables in the constraint graph
    are placed before others.
    """
    # TODO implement this
    consts = []
    for value in variable.domain:
        count = 0
        for var2 in csp.variables:
            if (len(csp.constraints[variable, var2]) > 0 and value in var2.domain):
                count += 1
        consts.append(count)

    return [x for (y,x) in sorted(zip(consts,variable.domain))]

    pass

def is_consistent(csp, variable, value):
    """Returns True when the variable assignment to value is consistent, i.e. it does not violate any of the constraints
    associated with the given variable for the variables that have values assigned.

    For example, if the current variable is X and its neighbors are Y and Z (there are constraints (X,Y) and (X,Z)
    in csp.constraints), and the current assignment as Y=y, we want to check if the value x we want to assign to X
    violates the constraint c(x,y).  This method does not check c(x,Z), because Z is not yet assigned."""

    # TODO implement this

    varX = variable

    for varY in csp.variables:
            for check in csp.constraints[varX, varY]:
                if varY.is_assigned() == True and check.is_satisfied(value, varY.value) == False:
                        return False
                elif varY.is_assigned() == False:
                    return True
    return True

    pass