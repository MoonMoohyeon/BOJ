#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
#define ll long long

int N;
vector<ll> rectangle(100001);

int solution(int left, int right) {
    if (left == right) {
        return rectangle[left];
    }

    int mid = (left + right) / 2;
    ll ans = max(solution(left, mid), solution(mid + 1, right));

    int lptr = mid;
    int rptr = mid + 1;

    ll height = min(rectangle[lptr], rectangle[rptr]);
    ans = max(ans, height * 2);

    while (lptr > left || rptr < right) {
        if (rptr < right && (lptr == left || rectangle[lptr - 1] < rectangle[rptr + 1])) {
            rptr++;
            height = min(height, rectangle[rptr]);
        }
        else {
            lptr--;
            height = min(height, rectangle[lptr]);
        }

        ans = max(ans, height * (rptr - lptr + 1));
    }

    return ans;
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> rectangle[i];
    }

    cout << solution(0, N - 1);


    return 0;
}