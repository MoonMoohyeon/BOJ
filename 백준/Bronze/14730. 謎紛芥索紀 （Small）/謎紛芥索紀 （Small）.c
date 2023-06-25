#include <stdio.h>
#include <math.h>
int main(void)
{
	int num;
	int n, m;
	int sum = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d %d", &n, &m);
		if (m >= 0)
			sum += n * m;
		else
			sum += n / abs(m);
	}
	printf("%d", sum);

	return 0;
}