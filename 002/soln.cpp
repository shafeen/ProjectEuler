#include <iostream>
using namespace std;

int main()
{	
	cout << "Number of Fib terms: ";
	
	long num;
	cin >> num;
	long fib1 = 0; // previous fibonacci term
	long fib2 = 1; // current fibonacci term

	long sum = 0;

	long TERMLIMIT = 4000000;

	while(1)
	{
		long fibLast = fib2;
		fib2 += fib1;
		fib1 = fibLast;

		if(fib2 <= TERMLIMIT)
		{

			cout << "here\n";
			if(fib2%2 == 0) // if even --> add to sum
				sum += fib2;

			
		}
		else
			break;

		//cout << "Term " << i+1 << ": " << fib2 << endl;
	}

	cout << "Sum of even Fib terms under 4 mil = " << sum << endl;


	return 1;
}