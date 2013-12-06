#include <thread>
#include <iostream>

using namespace std;

typedef unsigned long long superlong;


superlong integerPower(superlong num, superlong power)
{
	if(num == 0)
		return 0;
	if(power == 0 || num == 1) 
		return 1;


	superlong returnVal = num;

	for (superlong i = 1; i < power; i++)
	{
		returnVal *= num;
	}


	return returnVal;
}


superlong getSumUpto(superlong num)
{
	superlong sum = 0;

	for (superlong i = 1; i <= num; i++)
	{
		sum += i;
	}
	return sum;
}



int main(int argc, const char *argv[])
{
	superlong getSumTo = 0;

	if(argc == 2)
		getSumTo = atoi(argv[1]);


	// sum of squares
	superlong sumSquares = 0;
	for(superlong i = 1; i <= getSumTo; i++)
	{
		sumSquares += integerPower(i, 2);
	}

	// square of sum
	superlong squareSum = 0;
	squareSum += integerPower(getSumUpto(getSumTo), 2);


	// difference
	superlong difference;
	if(squareSum > sumSquares)
		difference = squareSum - sumSquares;
	else
		difference = sumSquares - squareSum;

	cout << sumSquares << endl << squareSum << endl;
	
	cout << "The difference is = " << difference << endl;


	return 0;
}