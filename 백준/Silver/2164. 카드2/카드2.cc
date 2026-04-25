#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	int num;
	scanf("%d", &num);
	queue<int> q;
	for (int i = 1; i < num + 1; i++)
	{
		q.push(i);
	}
	int temp;
	while (num != 1)
	{
		num--;
		q.pop();
		temp = q.front();
		q.push(temp);
		q.pop();
	}
	temp = q.front();
	printf("%d", temp);

	return 0;
}