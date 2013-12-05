#include <iostream>
#include <thread>
using namespace std;

typedef unsigned long long superlong;

std::mutex cout_lock;


bool isDivisible(superlong numberInQuestion, superlong mainNumber)
{
	// cout << "called\n";
	return ((mainNumber % numberInQuestion ) == 0);
}


void printDivisibleNumber(superlong numberInQuestion, superlong mainNumber)
{
	if(isDivisible(numberInQuestion, mainNumber))
	{
		cout_lock.lock();
		cout << "Divisible by " << numberInQuestion << endl;
		cout_lock.unlock();
	}
}


bool isPrime(superlong number)
{
	if(number == 1 || number == 2)
		return true;

	for(superlong i = number/2; i >= 2; i--)
	{	
		// cout << "Checking " << i << endl;
		if(number % i == 0) // --> not prime
		{
			printDivisibleNumber(i, number);
			//return false;
		}
		// spawn a thread for the cout
		// spawn a thread to check primality
		//cout << ".";

	}

	return true;
}


int main()
{	
	superlong test =  600851475143;
	cout << test << endl;

	/*
		Given a number ---> find all its factors
		For each factor --> find out if its prime 
		If it's prime ----> count it as a prime facto
	*/

	cout << std::boolalpha << isPrime(test) << endl;

	return 1;
}