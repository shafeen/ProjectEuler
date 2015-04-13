#!/usr/bin/env python

# triangle numbers can be generated using their pattern
# they have a clear pattern: T_n = T_n-1 + n, T_0 = 0
def getTriangleNumber(nth=0):
	num = 0
	for n in range(1, nth+1):
		num += n
	return num

# print map(getTriangleNumber, range(1,7+1))



def printPrettyFactorList(factors):
	prettyFactorList = list(factors)
	prettyFactorList.sort()
	print prettyFactorList




# TODO: doesnt work with 28 (can't find 4 as a factor)
def findFactorSet(num = int(raw_input("Enter a number to find factors: "))):
	# start off the set with the number itself and 1
	factorSet = set([num, 1])

	# try to decompose into 2
	curnum = num
	keepDecomposing = True
	while keepDecomposing:
		for testdivisor in xrange(2, curnum+1):
			if testdivisor == curnum: # cannot decompose any further
				keepDecomposing = False
				break
			if curnum % testdivisor == 0: # if a factor
				factorSet.add(testdivisor)
				curnum = curnum/testdivisor
				factorSet.add(curnum)
				break

	return factorSet

factorSet = findFactorSet()
printPrettyFactorList(factorSet)


