#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
int dp[10001];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, K; cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int input; cin >> input;
        v.push_back(input);
    }

    dp[0] = 1;
    for (int i = 0; i< v.size(); i++) {
        for (int j = v[i]; j <= K; j++) {
            dp[j] += dp[j - v[i]];
        }
    }
    cout << dp[K] << "\n";

    return 0;
}