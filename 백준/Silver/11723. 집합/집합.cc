#include <iostream>
#include <cstring>
using namespace std;

int mask[21] = {0, };

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int M;
	string op = "";
	int num;

	cin >> M;
	for (int j = 0; j < M; j++)
	{
		cin >> op;
		if (op == "add")
		{
			cin >> num;
			if(mask[num] == 0)
				mask[num] = 1;
		}
		else if (op == "remove")
		{
			cin >> num;
			if (mask[num] == 1)
				mask[num] = 0;
		}
		else if (op == "check")
		{
			cin >> num;
			if (mask[num] == 1)
			{
				printf("1\n");
			}
			else
			{
				printf("0\n");
			}
		}
		else if (op == "toggle")
		{
			cin >> num;
			if (mask[num] == 1)
			{
				mask[num] = 0;
			}
			else
			{
				mask[num] = 1;
			}
		}
		else if (op == "all")
		{
			for (int i = 1; i <= 20; i++)
			{
				mask[i] = 1;
			}
		}
		else if (op == "empty")
		{
			memset(mask, 0, sizeof(mask));
		}
	}

	return 0;
}