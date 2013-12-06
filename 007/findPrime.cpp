
#include <thread>
#include <iostream>

using namespace std;

typedef unsigned long long superlong;

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


superlong findNthPrime(superlong n)
{
    if(n == 0)
        return 0;

    uint primesFound = 0;

    for (superlong i = 2; ; i++)
    {
        if(isPrimeNum(i))
        {
            primesFound++;
            if(primesFound == n)
                return i;

        }

    }

    // should never get here
    return 0;
}


int main(int argc, char **argv)
{
    if(argc == 2)
        cout << findNthPrime(atoi(argv[1])) << endl;
    else
        cout << findNthPrime(6) << endl;



}