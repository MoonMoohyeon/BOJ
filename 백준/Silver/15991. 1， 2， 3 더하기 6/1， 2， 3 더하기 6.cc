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

int T, N;
int DP[100001];
int ans = 0;



int solution(int cur, int cnt) {
    
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    for(int t=1; t<=T; ++t) {
        ans = 0;
        cin >> N;
        DP[0] = 1;
        DP[1] = 1;
        DP[2] = 2;
        DP[3] = 2; // DP[N] = N을 1,2,3을 사용하여 대칭으로 만들 수 있는 경우의 수
        for(int i=4; i<=6; ++i) {
            DP[i] = (DP[i-2] + DP[i-4]) % 1000000009;
        }
        for(int i=6; i<=N; ++i) {
            DP[i] = ((DP[i-2] + DP[i-4]) % 1000000009 + DP[i-6]) % 1000000009;
        }
        cout << DP[N] % 1000000009 << "\n";
    }

    return 0;
}