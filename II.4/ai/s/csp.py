#csp
#set of variables, domain of each variable, constraints
#can have only inequality constraints (sufficient for map coloring problems)
class CSP():
	def __init__(self,domains,constraints):
		self.domains=domains
		self.constraints=constraints
		self.assignments={}
		for k in domains.keys():
			self.assignments[k]=None
		self.unassigned=domains.keys()

	def getNVar(self):
		return len(self.domains.keys())

	def isConsistent(self):
		consistent = True
		for k in self.constraints.keys():
			co = self.constraints[k]
			for c in co:
				if (self.assignments[k] is not None) and (self.assignments[c] is not None):
					consistent = consistent and (self.assignments[k] != self.assignments[c])
		return consistent

	def getDomain(self,var):
		return self.domains[var]

	def assign(self,var,value):
		self.assignments[var]=value

	def unassign(self,var):
		self.assignments[var]=None

	def getAssignments(self):
		return self.assignments

	def getNextAssignableVar(self):
		#get the next var that is unassigned AND has non-empty domain
		for u in self.assignments.keys():
			if (self.assignments[u] is None) and self.domains[u] != []:
				return u

	def isSolved(self):
		solved=True
		for a in self.assignments.values():
			solved = solved and (a is not None)
		return (solved and self.isConsistent())


#backtracking search algorithm
def backtrackcsp(csp, depth=0):
    if csp.isSolved():
        return csp

    var = csp.getNextAssignableVar()
    if var is None:
        return None

    for value in csp.getDomain(var):
        csp.assign(var, value)
        if csp.isConsistent():
            result = backtrackcsp(csp, depth + 1)
            if result is not None:
                return result
        csp.unassign(var)
    return None

#very simple example: A={1,2,3}, B={1,2,3}, C={1,2,3}. A!=B, B!=C
examplecsp = CSP(
    {'A': [1, 2, 3], 'B': [1, 2, 3], 'C': [1, 2, 3]},
    {'A': ['B'], 'B': ['C']}
)

solution = backtrackcsp(examplecsp, 0)
if solution:
    print(solution.getAssignments())
else:
    print("No solution found.")

domains = {
    'Nordwestmecklenburg': ['R', 'G', 'B'],
    'Rostock': ['R', 'G', 'B'],
    'Vorpommern-Rügen': ['R', 'G', 'B'],
    'Landkreis Rostock': ['R', 'G', 'B'],
    'Schwerin': ['R', 'G', 'B'],
    'Ludwigslust-Parchim': ['R', 'G', 'B'],
    'Mecklenburgische Seenplatte': ['R', 'G', 'B'],
    'Vorpommern-Greifswald': ['R', 'G', 'B']
}

constraints = {
    'Nordwestmecklenburg': ['Rostock', 'Schwerin'],
    'Rostock': ['Nordwestmecklenburg', 'Landkreis Rostock', 'Vorpommern-Rügen'],
    'Vorpommern-Rügen': ['Rostock', 'Vorpommern-Greifswald'],
    'Landkreis Rostock': ['Rostock', 'Mecklenburgische Seenplatte'],
    'Schwerin': ['Nordwestmecklenburg', 'Ludwigslust-Parchim'],
    'Ludwigslust-Parchim': ['Schwerin', 'Mecklenburgische Seenplatte'],
    'Mecklenburgische Seenplatte': ['Landkreis Rostock', 'Ludwigslust-Parchim', 'Vorpommern-Greifswald'],
    'Vorpommern-Greifswald': ['Mecklenburgische Seenplatte', 'Vorpommern-Rügen']
}

map_csp = CSP(domains, constraints)
solution_map = backtrackcsp(map_csp)

if solution_map:
    print(solution_map.getAssignments())
else:
    print("Keine Lösung.")