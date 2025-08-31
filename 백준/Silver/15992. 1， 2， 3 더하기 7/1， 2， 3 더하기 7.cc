#include <iostream>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <climits>
using namespace std;

int T, N, M;
int DP[1001][1001];
int ans = 0;
constexpr int MOD = 1000000009;

int solution(int cur, int cnt) {
    // if(cur < 1 || cnt < 0) return 0;
    // if(cnt == 1 && cur <= 3) return 1;

    if(cur == 0 && cnt == 0) {
        return 1;
    }

    if(cur <= 0 || cnt == 0) {
        return 0;
    }
    
    int& num = DP[cur][cnt];
    if(num != -1) {
        return num;
    }

    num = ((solution(cur-1, cnt-1) + solution(cur-2, cnt-1)) % MOD + solution(cur-3, cnt-1)) % MOD;
    return num;
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    for(int i=0; i<=1000; ++i) {
        for(int j=0; j<=1000; ++j) {
            DP[i][j] = -1;
        }
    }

    cin >> T;
    for(int t=1; t<=T; ++t) {
        ans = 0;
        cin >> N >> M;

        ans = solution(N, M) % MOD; // 정수 N을 만드는 경우의 수
        /*
            DP[i][j] = DP[i-1][j-1] + DP[i-2][j-1] + DP[i-3][j-1];
        */
        cout << ans << "\n";
    }

    return 0;
}