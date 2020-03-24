# Program to print Emirp numbers 
# less than n 

# Function to find reverse 
# of any number 
def reverse(x): 

	rev = 0; 
	while (x > 0): 
		rev = (rev * 10) + x % 10; 
		x = int(x / 10); 

	return rev; 

# Sieve method used for generating 
# emirp number(use of sieve of 
# Eratosthenes) 
def printEmirp(n): 

	# Create a boolean array "prime[0..n]" 
	# and initialize all entries it as true. 
	# A value in prime[i] will finally be 
	# false if i is Not a prime, else true. 
	prime = [1] * (n + 1); 
	p = 2; 
	while (p * p <= n): 
		
		# If prime[p] is not changed, 
		# then it is a prime 
		if (prime[p] == 1): 
			
			# Update all multiples of p 
			for i in range(p * 2, n + 1, p): 
				prime[i] = 0; 
		p += 1; 

	# Traverse all prime numbers 
	for p in range(2, n + 1): 
		if (prime[p] == 1): 
			
			# Find reverse a number 
			rev = reverse(p); 

			# A number is emrip if it is not 
			# a palindrome number and its 
			# reverse is also prime. 
			if (p != rev and rev <= n and
					prime[rev] == 1): 
				print(p, rev, end = " "); 
	
				# Mark reverse prime as 
				# false so that it's 
				# not printed again 
				prime[rev] = 0; 

# Driver Code 
n = 100; 
printEmirp(n); 
