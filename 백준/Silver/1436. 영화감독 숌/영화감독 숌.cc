#include <iostream>
using namespace std;


int main()
{
	int N;
	scanf("%d", &N);

	int num = 0;
	int cnt = 0;

	while (cnt != N)
	{
		num++;
		int tmp = num;

		while (tmp >= 666)
		{
			if (tmp % 1000 == 666)
			{
				cnt++;
				break;
			}
			else tmp /= 10;
		}
	}
	
	printf("%d", num);

	return 0;
}