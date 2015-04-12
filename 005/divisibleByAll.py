#!/usr/bin/env python

def isDivisibleByAll(number):
	for i in xrange(1,21):
		if number % i != 0:
			return False
	return True

def problem5():
	number = 19 # largest prime amongst divisors

	while True:
		if isDivisibleByAll(number):
			break
		number += 19
	print "%d is divisible by each of 1 thru 20" % (number)



problem5()