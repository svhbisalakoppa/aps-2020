# An Optimized Solution to check Abundant Number 
# in PYTHON 
import math 

# Function to calculate sum of divisors 
def getSum(n) : 
	sum = 0
	
	# Note that this loop runs till square root 
	# of n 
	i = 1
	while i <= (math.sqrt(n)) : 
		if n%i == 0 : 
			
		# If divisors are equal,take only one 
		# of them 
			if n/i == i : 
				sum = sum + i 
			else : # Otherwise take both 
				sum = sum + i 
				sum = sum + (n / i ) 
		i = i + 1
	
	# calculate sum of all proper divisors only 
	sum = sum - n 
	return sum

# Function to check Abundant Number 
def checkAbundant(n) : 
	
	# Return true if sum of divisors is greater 
	# than n. 
	if (getSum(n) > n) : 
		return 1
	else : 
		return 0
		
# Driver program to test above function */ 
if(checkAbundant(12) == 1) : 
	print "YES"
else : 
	print "NO"
	
if(checkAbundant(15) == 1) : 
	print "YES"
else : 
	print "NO"
	
# This code is contributed by Nikita Tiwari. 
