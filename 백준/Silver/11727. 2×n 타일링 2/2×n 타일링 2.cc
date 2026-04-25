#include <iostream>
using namespace std;

int main(void)
{
	int num;
	int FF[1000] = {0, };
	scanf("%d", &num);
	FF[0] = 1;
	FF[1] = 1;
	for (int i = 2; i <= num; i++)
	{
		FF[i] = (FF[i - 2] * 2 + FF[i - 1]) % 10007;
	}
	
	printf("%d", FF[num]);
}