#include <iostream>
#include <vector>
using namespace std;

int dp[2][100011];

int main(void) {
    int T, n;
    scanf("%d ", &T);
    for(int i=0; i<T; i++) {
        scanf("%d ", &n);

		for (int j = 0; j < 2; j++)
			for (int k = 0; k < n; k++)
				scanf("%d", &dp[j][k]);

		dp[0][1] += dp[1][0];
		dp[1][1] += dp[0][0];


        for(int i=2; i<n; i++) {
        dp[0][i] = dp[0][i] + max(dp[1][i-2], dp[1][i-1]);
        dp[1][i] = dp[1][i] + max(dp[0][i-2], dp[0][i-1]);
        }

        printf("%d\n", max(dp[0][n-1], dp[1][n-1]));
    }

    return 0;
}
