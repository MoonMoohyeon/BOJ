#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <math.h>
#include <limits.h>
#include <string.h>
using namespace std;

struct member {
	int age;
	char name[101];
};

struct member arr[100001];

bool cmp(struct member a, struct member b)
{
	if (a.age < b.age) return true;
	else return false;
}


int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %s", &arr[i].age, arr[i].name);
	}

	stable_sort(arr, arr + N, cmp);
	for (int i = 0; i < N; i++)
	{
		printf("%d %s\n", arr[i].age, arr[i].name);
	}

	return 0;
}
