# -*- coding: utf-8 -*-

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
