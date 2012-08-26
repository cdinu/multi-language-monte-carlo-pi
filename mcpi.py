import random

MAXITERS = 10 * 1000000

def mcpi(iterations):
	pi = 0
	for i in range(iterations):
		x = random.random()
		y = random.random()
		d = x*x + y*y
		
		if d < 1:
			pi = pi + 1
	
		if 1 > i % (MAXITERS/10):
			print "The value of PI with " + repr(i) + " is " + repr(4.0*pi/(1+i))

	return 1.0 * pi / iterations * 4


print "The value of PI with " + repr(MAXITERS) + " is " + repr(mcpi(MAXITERS))
