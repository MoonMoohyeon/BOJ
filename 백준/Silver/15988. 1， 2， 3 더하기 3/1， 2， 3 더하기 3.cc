#include <iostream>
using namespace std;

long long DT[1000001] = { 0, };

int main(void)
{
	int tc;
	int num;
	DT[0] = 1;
	DT[1] = 1;
	DT[2] = 2;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++)
	{
		scanf("%d", &num);
		for (int i = 3; i <= num; i++)
		{
			DT[i] = (DT[i - 3] + DT[i - 2] + DT[i - 1]) % 1000000009;
		}
		printf("%lld\n", DT[num]);
	}

	return 0;
}