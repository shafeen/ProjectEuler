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
    if(number == 2) // technically this isn't necessary
        return true;
    
    if(number & 0x1) // if odd
    {
        // will only be divisible by odd numbers
        for(superlong i = 3; i <= number/2; i+=2)
        {
            if(isDivisible(i, number))
                return false;
        }
    }     
    else // if even
        return false;

    return true;
}

superlong sumPrimesBelow(superlong limit)
{	
	if(limit <= 2)
		return 0;

	superlong sum = 2;
	
	// NOTE: Only odd numbers can be prime (except 2)
	for(superlong i = 3; i < limit; i+=2)
	{	
		superlong oldSum = sum;

		sum += isPrimeNum(i)? i : 0;
		
		// if(sum != oldSum) // only prints if sum changes
		// 	cout << "Sum is currently = " << sum << endl;
		// cout << "@"<< i << endl;
	}

	return sum;
}



int main(int argc, char **argv)
{
	if(argc == 2)
		cout << "Sum of primes below " 
			 << atoi(argv[1])
			 << " is = "
			 << sumPrimesBelow(atoi(argv[1]))
			 << endl;

			 


	return 0;
}