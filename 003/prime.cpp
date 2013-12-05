#include <iostream>
#include <thread>
using namespace std;

typedef unsigned long long superlong;

std::mutex cout_lock;


bool isDivisible(superlong numberInQuestion, superlong mainNumber)
{
	return ((mainNumber % numberInQuestion ) == 0);
}

bool isPrimeNum(superlong number)
{
	for(superlong i = 2; i <= number/2; i+=1)
	{
		if(isDivisible(i, number))
			return false;
	}

	return true;
}

superlong printDivisibleNumber(superlong numberInQuestion, superlong mainNumber)
{	

	// NOTE: when you find 1 factor you find 2 factors

	if(isDivisible(numberInQuestion, mainNumber))
	{
		cout_lock.lock();
		cout << "Divisible by " << numberInQuestion; //<< endl;
		
		if(isPrimeNum(numberInQuestion))
			cout << "---> prime" << endl;
		else
			cout << "---> not prime" << endl;


		cout_lock.unlock();

		// returns the other factor
		return mainNumber/numberInQuestion;
	}

	// default is to return 0
	// indicating that it isn't divisible
	return 0;
}


bool isPrime(superlong number)
{
	if(number == 1 || number == 2)
		return true;

	// initial upper limit is half of the number
	superlong upperLimit = number/2;

	for(superlong i = 2; i <= upperLimit; i+=1)
	// for(superlong i = number/2; i >= 2; i-=1)
	{	

		superlong returnVal = printDivisibleNumber(i+1, number);
		
		if(returnVal)
		{
			cout << "Also Divisible by " << returnVal;// << endl;
			if(isPrimeNum(returnVal))
				cout << "---> prime" << endl;
			else
				cout << "---> not prime" << endl;

			upperLimit = returnVal;
		}

		// spawn a thread for the cout
		// spawn a thread to check primality

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
	isPrime(test);

	// cout << std::boolalpha << true << endl;

	return 1;
}