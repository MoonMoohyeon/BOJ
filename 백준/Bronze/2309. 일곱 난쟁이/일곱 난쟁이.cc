#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void)
{
	int arr[9];
	int sum = 0;
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
	}

	int df = sum - 100;
	int n1, n2;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (arr[i] + arr[j] == df)
			{
				n1 = arr[i];
				n2 = arr[j];
			}
		}
	}

	sort(arr, arr+9);
	for (int i = 0; i < 9; i++)
	{
		if (arr[i] == n1 || arr[i] == n2) continue;
		printf("%d\n", arr[i]);
	}

	return 0;
}

