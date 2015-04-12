#!/usr/bin/env python

def isDivisibleByAll(number):
	for i in xrange(1,21):
		if number % i != 0:
			return False
	return True

def problem5():
	# note you can also set this number below to the lcm of 
	# any of the prior in sequence, for example 1..10 = 2520
	number = 20 # largest number amongst divisors

	while True:
		if isDivisibleByAll(number):
			break
		number += 20
	print "%d is divisible by each of 1 thru 20" % (number)



problem5()