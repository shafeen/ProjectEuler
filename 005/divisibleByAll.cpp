#include <iostream>
#include <string>
#include <thread>

using namespace std;

typedef unsigned long long superlong;

bool isDivisibleByAll(superlong number)
{
	for(uint i = 1; i <= 20; i++)
		if(number % i != 0)
			return false;

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


int main()
{	

	problem5();

	return 0;
}





