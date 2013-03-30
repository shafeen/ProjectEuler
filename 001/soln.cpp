#include <iostream>
using namespace std;

int main()
{
	cout << "List all natural numbers below: ";
	int below;
	cin >> below;

	int sum = 0;

	for(int i = 1; i < below; i++)
	{
		bool relevant = false;
		if (i%3 == 0 && i%5 == 0) // div by both 3 & 5
			relevant = 1;
		else if (i%3 == 0)
			relevant = 1;
		else if (i%5 == 0)
			relevant = 1;

		if (relevant)
		{
			sum += i;
			cout << i << endl;	
		}
	} 


	cout << "Sum = " << sum << endl;

	return 1;
}
