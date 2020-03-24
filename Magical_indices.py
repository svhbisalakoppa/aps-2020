# Python3 program to find number of magical 
# indices in the given array. 

# Function to count number of magical 
# indices. 
def solve(A, n) : 

	cnt = 0
	
	# Array to store parent node of 
	# traversal. 
	parent = [None] * (n + 1) 
	
	# Array to determine whether current node 
	# is already counted in the cycle. 
	vis = [None] * (n + 1) 
	
	# Initialize the arrays. 
	for i in range(0, n+1): 
		parent[i] = -1
		vis[i] = 0		
	
	for i in range(0, n): 
		j = i 
	
		# Check if current node is already 
		# traversed or not. If node is not 
		# traversed yet then parent value 
		# will be -1. 
		if (parent[j] == -1) : 
	
			# Traverse the graph until an 
			# already visited node is not 
			# found. 
			while (parent[j] == -1) : 
				parent[j] = i 
				j = (j + A[j] + 1) % n 
	
			# Check parent value to ensure 
			# a cycle is present. 
			if (parent[j] == i) : 
	
				# Count number of nodes in 
				# the cycle. 
				while (vis[j]==0) : 
					vis[j] = 1
					cnt = cnt + 1
					j = (j + A[j] + 1) % n 
	return cnt 

# Driver code	 
A = [ 0, 0, 0, 2 ] 
n = len(A) 
print (solve(A, n)) 
