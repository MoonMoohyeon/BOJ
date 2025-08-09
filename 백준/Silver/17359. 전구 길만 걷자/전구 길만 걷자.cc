#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <climits>
using namespace std;

int N, M;
string arr[11];
int cost[11] = { 0, };
bool visited[11] = { false, };
int ans = INT_MAX;

void bulb(int n, int c, char last) {
    if (n >= N) {
        if (c < ans) ans = c;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (visited[i] == false) {
            visited[i] = true;
            int total = cost[i];
            if (last != arr[i][0]) {
                total++;
            }
            c += total;
            bulb(n + 1, c, arr[i].back());
            visited[i] = false;
            c -= total;
            
        }
    }
}

int main(int argc, char** argv) {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int t = 0; t < N; t++) {
        int cnt = 0;
        for (int i = 1; i < arr[t].size(); i++) {
            if (arr[t][i] != arr[t][i - 1]) {
                cnt++;
            }
        }
        cost[t] = cnt;
    }

    //cout << endl;
    //for (int i = 0; i < N; i++) {
    //    cout << cost[i] << " ";
    //}
    //cout << endl;

    for (int i = 0; i < N; i++) {
        visited[i] = true;
        bulb(1, cost[i], arr[i].back());
        visited[i] = false;
    }

    cout << ans;

    return 0;
}