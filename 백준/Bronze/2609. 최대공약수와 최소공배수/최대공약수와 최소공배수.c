#include <stdio.h>

int main(void)
{
	int num1, num2;
	scanf("%d %d", &num1, &num2);
	int f, s;

	if (num1 > num2)
	{
		f = num1;
		s = num2;
	}
	else
	{
		s = num1;
		f = num2;
	}

	int r;

	while (1)
	{
		r = f % s;

		if (r == 0) break;

		f = s;
		s = r;
	}

	printf("%d\n", s);
	printf("%d\n", num1 * num2 / s);
	

	

	return 0;
}