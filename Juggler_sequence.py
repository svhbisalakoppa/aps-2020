import math 
def printJuggler(n) : 
	a = n 
	print a,
	while (a != 1) : 
		b = 0
		if (a%2 == 0) : 
			# calculate next term 
			b = (int)(math.floor(math.sqrt(a))) 
		else : 
			# for odd previous term calculate 
			# next term 
			b = (int) (math.floor(math.sqrt(a)*math.sqrt(a)*math.sqrt(a))) 
		print b,
		a = b 
printJuggler(3) 
print
printJuggler(9) 
