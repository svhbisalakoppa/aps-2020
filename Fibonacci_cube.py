# Python3 code to find vertices in 
# a fibonacci cube graph of order n 

# Function to find fibonacci number 
def fib(n): 

	if n <= 1: 
		return n 
		
	return fib(n - 1) + fib(n - 2) 

# Function for finding number of 
# vertices in fibonacci cube graph 
def findVertices(n): 

	# return fibonacci number 
	# for f(n + 2) 
	return fib(n + 2) 

# Driver Code 
if __name__ == "__main__": 

	# n is the order of the graph 
	n = 3
	print(findVertices(n)) 
