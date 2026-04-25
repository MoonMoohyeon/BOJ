#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void)
{
	vector<int> vec;
	int num;
	scanf("%d", &num);
	int temp;
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &temp);
		vec.push_back(temp);
	}

	sort(vec.begin(), vec.end());

	for (auto iter = vec.begin(); iter != vec.end(); iter++)
	{
		printf("%d\n", *iter);
	}


	return 0;
}