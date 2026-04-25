#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int num;
	cin >> num;
	int f = num;
	int count = 0;

	do
	{
		
		int t = num / 10;
		int o = num % 10;
		int r = t + o;
		if (r >= 10)
		{
			r = r % 10;
		}

		num = o * 10 + r;
		count++;
	}while (f != num);

	cout << count << endl;

	return 0;
}