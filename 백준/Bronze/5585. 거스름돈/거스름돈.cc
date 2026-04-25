#include <iostream>
using namespace std;

int main(void)
{
	int temp, n, cnt = 0;
	scanf("%d", &temp);
	n = 1000 - temp;
	while (n > 0)
	{
		if (n >= 500) 
		{
			cnt++; n -= 500;
		}
		else if (n >= 100)
		{
			cnt++; n -= 100;
		}
		else if (n >= 50)
		{
			cnt++; n -= 50;
		}
		else if (n >= 10)
		{
			cnt++; n -= 10;
		}
		else if (n >= 5)
		{
			cnt++; n -= 5;
		}
		else if (n >= 1)
		{
			cnt++; n -= 1;
		}
	}

	printf("%d", cnt);

	return 0;
}