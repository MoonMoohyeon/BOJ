#include <iostream>
using namespace std;

int main(void)
{
	int tc;
	int num;
	int DT[1000] = {0, };
	DT[0] = 1;
	DT[1] = 1;
	DT[2] = 2;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++)
	{
		scanf("%d", &num);
		for (int i = 3; i <= num; i++)
		{
			DT[i] = (DT[i - 3] + DT[i - 2] + DT[i - 1]) % 10007;
		}
		printf("%d\n", DT[num]);
	}	

	return 0;
}