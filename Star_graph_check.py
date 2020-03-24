# Python to find whether 
# given graph is star 
# or not 

# define the size 
# of incidence matrix 
size = 4

# def to 
# find star graph 
def checkStar(mat) : 

	global size 
	
	# initialize number of 
	# vertex with deg 1 and n-1 
	vertexD1 = 0
	vertexDn_1 = 0

	# check for S1 
	if (size == 1) : 
		return (mat[0][0] == 0) 
	
	# check for S2 
	if (size == 2) : 
		return (mat[0][0] == 0 and
				mat[0][1] == 1 and
				mat[1][0] == 1 and
				mat[1][1] == 0) 

	# check for Sn (n>2) 
	for i in range(0, size) : 

		degreeI = 0
		for j in range(0, size) : 
			if (mat[i][j]) : 
				degreeI = degreeI + 1

		if (degreeI == 1) : 
			vertexD1 = vertexD1 + 1

		elif (degreeI == size - 1): 
			vertexDn_1 = vertexDn_1 + 1
	
	return (vertexD1 == (size - 1) and
			vertexDn_1 == 1) 

# Driver code 
mat = [[0, 1, 1, 1], 
	[1, 0, 0, 0], 
	[1, 0, 0, 0], 
	[1, 0, 0, 0]] 

if(checkStar(mat)) : 
	print ("Star Graph") 
else : 
	print ("Not a Star Graph") 
	
