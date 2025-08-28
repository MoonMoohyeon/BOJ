#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <set>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int rec[1001][1001];
int DP[1001][1001];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    N = M = 1;
    while (1) {
        cin >> N >> M;
        memset(DP, 0, sizeof(DP));
        int ans = 0;

        if (N == 0 && M == 0) break;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> rec[i][j];
                if (i == 0 || j == 0) {
                    if (rec[i][j]) {
                        DP[i][j] = 1;
                        ans = 1;
                    }
                }
            }
        }

        for (int i = 1; i < N; i++) {
            for (int j = 1; j < M; j++) {
                if (rec[i][j]) {
                    DP[i][j] = min(DP[i - 1][j - 1], min(DP[i - 1][j], DP[i][j - 1])) + 1;
                    ans = max(ans, DP[i][j]);
                }
            }
        }

        cout << ans << "\n";
    }


    return 0;
}