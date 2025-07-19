#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <utility>
using namespace std;

int A[10001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int N, K;
    
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int cnt = 0;
    for (int i = 1; i < N; i++) {
        int loc = i - 1;
        int newitem = A[i];
        while (0 <= loc && newitem < A[loc]) {
            A[loc + 1] = A[loc];
            loc--;
            cnt++;
            if (cnt == K) goto label;
        }
        if (loc + 1 != i) {
            A[loc + 1] = newitem;
            cnt++;
            if (cnt == K) goto label;
        }
    }
label:
    //cout << "cnt = " << cnt << endl;
    if (cnt < K) cout << "-1";
    else {
        for (int i = 0; i < N; i++) {
            cout << A[i] << " ";
        }
    }

    return 0;
}
