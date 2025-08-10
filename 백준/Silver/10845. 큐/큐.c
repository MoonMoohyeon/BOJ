#include <stdio.h>
#include <string.h>

int main(void)
{
	int num;
	scanf("%d", &num);
	char cmd[20];
	int queue[100001];
	int n;
	int head = 0, tail = 0;

	for (int i = 0; i < num; i++)
	{
		scanf("%s", &cmd);
		if (!strcmp(cmd, "push"))
		{
			scanf("%d", &n);
			queue[head] = n;
			head = (head + 1) % 100001;
		}
		else if (!strcmp(cmd, "pop"))
		{
			if (head == tail) printf("-1\n");
			else
			{
				printf("%d\n", queue[tail]);
				tail = (tail + 1) % 100001;
			}
		}
		else if (!strcmp(cmd, "size"))
		{
			printf("%d\n", head - tail);

		}
		else if (!strcmp(cmd, "empty"))
		{
			if (head == tail) printf("1\n");
			else printf("0\n");
		}
		else if (!strcmp(cmd, "front"))
		{
			if (head == tail) printf("-1\n");
			else printf("%d\n", queue[tail]);
		}
		else if (!strcmp(cmd, "back"))
		{
			if (head == tail) printf("-1\n");
			else printf("%d\n", queue[head - 1]);
		}
	}
	
	return 0;
}