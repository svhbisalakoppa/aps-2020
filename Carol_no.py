# Python program to find n'th Carol number 
def carol(n): 
	# a**b is a ^ b in python 
	result = (2**n) - 1
	return result * result - 2

# driver program to run the case 
n = 4
print carol(n) 
