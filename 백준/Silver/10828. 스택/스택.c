#include <stdio.h>
#include <string.h>

int main(void)
{
	int num;
	scanf("%d", &num);
	char cmd[20];
	int stack[100001];
	int n;
	int SP = 0;

	for (int i = 0; i < num; i++)
	{
		scanf("%s", &cmd);
		if (!strcmp(cmd, "push"))
		{
			scanf("%d", &n);
			stack[SP++] = n;
		}
		else if (!strcmp(cmd, "pop"))
		{
			if (!SP) printf("-1\n");
			else printf("%d\n", stack[--SP]);
		}
		else if (!strcmp(cmd, "size"))
		{
			printf("%d\n", SP);

		}
		else if (!strcmp(cmd, "empty"))
		{
			if (!SP) printf("1\n");
			else printf("0\n");
		}
		else if (!strcmp(cmd, "top"))
		{
			if (!SP) printf("-1\n");
			else printf("%d\n", stack[SP - 1]);
		}
	}
	
	return 0;
}