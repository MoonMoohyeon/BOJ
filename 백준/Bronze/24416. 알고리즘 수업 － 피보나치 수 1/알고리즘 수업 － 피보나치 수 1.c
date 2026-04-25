#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	int DP[41];
	DP[5] = 5;
	DP[6] = 8;
	for (int i = 7; i < 41; i++)
	{
		DP[i] = DP[i - 1] + DP[i - 2];
	}
	printf("%d %d",DP[n], n - 2);

	return 0;
}

//5
//4 3
//3 2 2 1
//2 1
//
//5
//
//6
//5 4
//4 3 3 2
//3 2 2 1 2 1
//2 1
//
//8
//
//7
//6 5
//5 + 8 = 13
//
//8
//13 + 8 = 21
//
//9
//21 + 13 = 34