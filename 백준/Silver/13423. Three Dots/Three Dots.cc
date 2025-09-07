#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <cstring>
#define ll long long
using namespace std;

int T, N;
set<int> s;
int arr[1001];

int main(int argc, char** argv) {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int ans = 0;
        s.clear();
        cin >> N;
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < N; ++i) {
            cin >> arr[i];
            s.insert(arr[i]);
        }

        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                ll diff = abs(arr[i] - arr[j]);
                if (s.find(max(arr[i], arr[j]) + diff) != s.end()) ans++;
            }
        }
        
        cout << ans << "\n";
    }

    return 0;
}