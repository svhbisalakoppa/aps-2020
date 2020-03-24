# Python3 program to find vertices in a hypercube 
# graph of order n 

# function to find power of 2 
def power(n): 
	if n==1: 
		return 2
	return 2*power(n-1) 


# Dricer code 
n =4
print(power(n)) 
