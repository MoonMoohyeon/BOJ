#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <climits>
#include <set>
using namespace std;

int N, M;
set<int> A;
set<int> B;

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A.insert(a);
    }

    for (int i = 0; i < M; i++) {
        int b;
        cin >> b;
        B.insert(b);
    }

    int ans = A.size() + B.size();

    for (auto nowA = A.begin(); nowA != A.end(); nowA++) {
        if (B.find(*nowA) != B.end()) {
            ans -= 2;
        }
    }

    cout << ans;

    return 0;
}