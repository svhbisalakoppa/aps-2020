# A Depth First Search based recursive 
# function that returns true if a matching 
# for vertex u is possible 
def bpm(table, u, seen, matchR): 
	global M, N 
	
	# Try every receiver one by one 
	for v in range(N): 
		
		# If sender u has packets to send to 
		# receiver v and receiver v is not 
		# already mapped to any other sender 
		# just check if the number of packets 
		# is greater than '0' because only one 
		# packet can be sent in a time frame anyways 
		if (table[u][v] > 0 and not seen[v]): 
			seen[v] = True # Mark v as visited 

			# If receiver 'v' is not assigned to any 
			# sender OR previously assigned sender 
			# for receiver v (which is matchR[v]) has 
			# an alternate receiver available. Since 
			# v is marked as visited in the above line, 
			# matchR[v] in the following recursive call 
			# will not get receiver 'v' again 
			if (matchR[v] < 0 or bpm(table, matchR[v], 
									seen, matchR)): 
				matchR[v] = u 
				return True
	return False

# Returns maximum number of packets 
# that can be sent parallely in 1 
# time slot from sender to receiver 
def maxBPM(table): 
	global M, N 
	
	# An array to keep track of the receivers 
	# assigned to the senders. The value of 
	# matchR[i] is the sender ID assigned to 
	# receiver i. The value -1 indicates nobody 
	# is assigned. 

	# Initially all receivers are not mapped 
	# to any senders 
	matchR = [-1] * N 

	result = 0 # Count of receivers assigned to senders 
	for u in range(M): 
		
		# Mark all receivers as not seen 
		# for next sender 
		seen = [0] * N 

		# Find if the sender 'u' can be assigned 
		# to the receiver 
		if (bpm(table, u, seen, matchR)): 
			result += 1

	print("The number of maximum packets sent", 
		"in the time slot is", result) 

	for x in range(N): 
		if (matchR[x] + 1 != 0): 
			print("T", matchR[x] + 1, "-> R", x + 1) 
	return result 

# Driver Code 
M = 3
N = 4

table = [[0, 2, 0], [3, 0, 1], [2, 4, 0]] 
max_flow = maxBPM(table) 
