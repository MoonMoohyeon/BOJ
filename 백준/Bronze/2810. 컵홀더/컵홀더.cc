#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main(void)
{
	char seat[101];
	int N;
	scanf("%d", &N);
	scanf("%s", seat);
	int cnt = 0;
	for (int i = 0; i < strlen(seat); i++)
	{
		if (seat[i] == 'S')
		{
			cnt++;
		}
		else if (seat[i] == 'L')
		{
			i++;
			cnt++;
		}
	}
	
	if (cnt >= N)
		printf("%d", N);
	else
		printf("%d", cnt + 1);
	
	return 0;
}

