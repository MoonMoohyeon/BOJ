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

int N;
int P[10001];
int DP[10001];

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i=1; i<=N; ++i) {
        cin >> P[i];
    }

    DP[1] = P[1];
    DP[2] = max(DP[1] + P[1], P[2]);
    DP[3] = max({DP[1] + P[2], DP[2] + P[1], P[3]});
    DP[4] = max({DP[1] + P[3], DP[2] + P[2], DP[3]+ P[1], P[4]});

    for(int i=3; i<=N; ++i) {
        for(int j=1; j<=i; ++j) {
            DP[i] = max(DP[i], DP[i - j] + P[j]);
        }
    }

    // for(int i=1; i<=N; ++i) {
    //     cout << DP[i] << " ";
    // }
    cout << DP[N] << '\n';

    return 0;
}