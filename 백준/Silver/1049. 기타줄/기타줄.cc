#include <iostream>
using namespace std;

int main(void)
{
	int N, M;
	int o = 1001, s = 1001;
	scanf("%d %d", &N, &M);
	int tmp1, tmp2;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &tmp1, &tmp2);
		if (tmp1 < s) s = tmp1;
		if (tmp2 < o) o = tmp2;
	}

	
	int cnt = 0;
	int output = 0;

	while (cnt < N)
	{
		if (N - cnt <= 6)
		{
			if (o * (N - cnt) <= s)
			{
				output += o * (N - cnt);
				cnt += (N - cnt);
			}
			else
			{
				output += s;
				cnt += 6;
			}
		}
		else if (o * 6 <= s)
		{
			output += o * 6;
			cnt += 6;
		}
		else
		{
			output += s;
			cnt += 6;
		}
	}

	printf("%d", output);
	
	return 0;
}
