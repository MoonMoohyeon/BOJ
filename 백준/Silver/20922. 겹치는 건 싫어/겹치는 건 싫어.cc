#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, k;
int arr[200000];
int dat[100001] = { 0, };
int pre[100001] = { 0, };

int ans = 0;

// 투포인터를 사용하자...
// 아까 O(N^2) 이었던 걸 O(N) 으로 대폭 개선할 수 있다.
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int ptr1 = 0;
    int ptr2 = 0;

    for (ptr2; ptr2 < n; ptr2++) {
        dat[arr[ptr2]]++;

        while (dat[arr[ptr2]] > k) {
            dat[arr[ptr1]]--;
            ptr1++;
        }
        ans = max(ans, ptr2 - ptr1 + 1);
    }

    cout << ans;

    return 0;
}
