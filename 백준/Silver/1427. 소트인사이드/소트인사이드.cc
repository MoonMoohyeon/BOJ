#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int main(void)
{
	char N[11];
	int arr[11];
	scanf("%s", N);
	for (int i = 0; i < strlen(N); i++)
	{
		arr[i] = (int)N[i] - 48;
	}

	sort(arr, arr + strlen(N), greater<int>());
	for (int i = 0; i < strlen(N); i++)
	{
		printf("%d", arr[i]);
	}
	
	return 0;
}

