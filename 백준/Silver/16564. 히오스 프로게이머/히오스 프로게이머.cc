#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define ll long long
using namespace std;

ll N, K;
ll characters[1000001];
ll ans = 0;

void search(ll left, ll right, ll k) {
    if (left > right) return;
    ll mid = (left + right) / 2;
    ll flag = 0;
    for (int i = 0; i < N; ++i) {
        if (characters[i] < mid) {
            k -= (mid - characters[i]);
            if (k < 0) {
                flag = 1;
            }
        }
    }
    //cout << "mid : " << mid << " k : " << k << "\n";
    if (flag) { // 레벨이 부족함. 목표 레벨 낮추기
        search(left, mid - 1, K);
    }
    else { // 레벨이 남음. 목표 레벨 높이기
        ans = max(ans, mid);
        search(mid + 1, right, K);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> characters[i];
    }

    search(0, 1000000001, K);
    cout << ans;

    return 0;
}