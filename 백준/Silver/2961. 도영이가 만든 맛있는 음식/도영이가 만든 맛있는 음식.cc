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
using namespace std;

int N;
int taste[11][2];
int visited[11];

int ans = 10e8;
int check() { // 신맛과 쓴맛 차이 검사
    int a = 1;
    int b = 0; // a와 b의 차이가 최소가 되도록
    int flag = 0;
    for (int i = 0; i < N; i++) {
        if (visited[i]) {
            a *= taste[i][0];
            b += taste[i][1];
            flag = 1;
        }
    }

    if (!flag) return 10e8;
    return abs(a - b);
}

void generate(int cnt) { // 조합 생성
    if (cnt >= N) {
        int temp = check();
        ans = min(ans, temp);
        return;
    }

    visited[cnt] = 0;
    generate(cnt + 1); // 현재 숫자를 고른 경우
    visited[cnt] = 1;
    generate(cnt + 1); // 현재 숫자를 안 고른 경우

    return;
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> taste[i][0] >> taste[i][1];
    }

    /*
        i를 1개부터 N개까지 고르는 모든 조합을 탐색한다.
    */

    generate(0);

    cout << ans;

    return 0;
}
