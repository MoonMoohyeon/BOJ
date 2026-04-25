#include <iostream>
using namespace std;

int main(void)
{
	int num;
	scanf("%d", &num);

	long long DT[91];
	DT[0] = 1;
	DT[1] = 1;
	DT[2] = 1;
	for (int i = 3; i <= num; i++)
	{
		DT[i] = DT[i - 2] + DT[i - 1];
	}
	printf("%lld", DT[num]);

	return 0;
}