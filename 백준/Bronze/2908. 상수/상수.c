#include <stdio.h>

int main(void)
{
	int num1, num2;
	scanf("%d %d", &num1, &num2);

	int n1 = num1 % 10;
	num1 /= 10;
	int n2 = num1 % 10;
	num1 /= 10;
	int n3 = num1 % 10;
	num1 /= 10;
	int r1 = n1 * 100 + n2 * 10 + n3;

	int m1 = num2 % 10;
	num2 /= 10;
	int m2 = num2 % 10;
	num2 /= 10;
	int m3 = num2 % 10;
	num2 /= 10;
	int r2 = m1 * 100 + m2 * 10 + m3;
	printf("%d", (r1 > r2) ?  r1 : r2);

	return 0;
}