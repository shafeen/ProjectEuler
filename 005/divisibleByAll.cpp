#include <iostream>
#include <string>
#include <thread>

using namespace std;

typedef unsigned long long superlong;

bool isDivisibleByAll(superlong number, uint start=1, uint end=20)
{
	for(uint i = start; i <= end; i++)
	{
		if(number % i != 0)
			return false;
	}
	return true;
}

void problem5() // brute force
{
	superlong number = 20;
	
	while(true)
	{
		if(isDivisibleByAll(number++))
			break;
	}
	cout << number-1 << " is divisible by each of 1 thru 20!\n";
}

void problem5_better() // brute force optimized
{
	superlong number = 20; // largest amongst divisors
	
	while(true)
	{
		if(isDivisibleByAll(number))
			break;
		number+=20;
	}
	cout << number << " is divisible by each of 1 thru 20!\n";
}


int main()
{	

	problem5_better();

	return 0;
}





