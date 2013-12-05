#include <iostream>
#include <string>
#include <thread>

using namespace std;

typedef unsigned long long superlong;

std::mutex cout_lock;


bool isPalindrome(string numberStr)
{
	// cout << "Checking if " << numberStr << " is a Palindrome\n";

	if(numberStr.size() <= 1)
		return true;

	unsigned int len = numberStr.size();
	unsigned int midpoint = len/2;
	
	for(unsigned int i = 0; i <= midpoint; i++)
	{
		// cout << "comparing " << numberStr[i] << " and " 
        // << numberStr[numberStr.size()-1-i] << endl;

		if(numberStr[i] != numberStr[numberStr.size()-1-i])
			return false;
		
	}

	return true;
}

bool isPalindrome(superlong number)
{
	return isPalindrome(std::to_string(number));
}

void problem3()
{
    superlong currentLargest = 0;;


	for (uint i = 999; i > 99; i--)
	{
		for (uint j = 999; j > 99; j--)
		{
			// cout << "Checking " << i << " * " << j << endl;
			if(isPalindrome(i*j))
			{	
                if(i*j > currentLargest)
                    currentLargest = i*j;
				cout << i*j << " is a palindrome number\n";
			}
		}
	}


    cout << currentLargest 
         << " is the largest palindrome number from 3 digit products\n";



}


int main()
{	

	problem3();

	return 0;
}





