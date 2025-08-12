#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <climits>
using namespace std;

int T, D, W, K, ans;
int film[14][21];

void input() {
    cin >> D >> W >> K;
    ans = INT_MAX;

    for (int i = 0; i < D; i++) {
        for (int j = 0; j < W; j++) {
            cin >> film[i][j];
        }
    }
}

bool isvalid() {

    // K=1이면 어떤 필름이든 항상 통과
    if (K == 1) {
        return true;
    }

    for (int j = 0; j < W; j++) {
        int count = 1;
        bool col_passed = false;

        for (int i = 1; i < D; i++) {
            if (film[i][j] == film[i - 1][j]) {
                count++;
            }
            else {
                count = 1;
            }

            if (count >= K) {
                col_passed = true;
                break;
            }
        }

        if (!col_passed) {
            return false;
        }
    }

    return true;
}

/*
    약품 X, 약품 A, 약품 B
    각 행별로 약품을 처리하는 경우의 수 3가지
    각 열별로 테스트를 통과하는지 검사하기
*/
void solution(int row, int count) {
    // [가지치기] 현재까지의 투입 횟수가 이미 찾은 최소 횟수보다 크거나 같으면 더 볼 필요 없음
    if (count >= ans) {
        return;
    }

    // [종료 조건] 모든 행에 대한 처리를 결정했다면
    if (row == D) {
        if (isvalid()) {
            ans = min(ans, count);
        }
        return;
    }

    // 1. 현재 'row' 행에 약품을 투입하지 않는 경우
    solution(row + 1, count);

    int original_row[21];
    for (int j = 0; j < W; j++) {
        original_row[j] = film[row][j];
    }

    // 2. 현재 'row' 행에 약품 A(0)를 투입하는 경우
    for (int j = 0; j < W; j++) {
        film[row][j] = 0;
    }
    solution(row + 1, count + 1);

    // 3. 현재 'row' 행에 약품 B(1)를 투입하는 경우
    for (int j = 0; j < W; j++) {
        film[row][j] = 1;
    }
    solution(row + 1, count + 1);

    // [백트래킹] 다른 경우의 수 탐색을 위해 변경했던 행을 원상 복구
    for (int j = 0; j < W; j++) {
        film[row][j] = original_row[j];
    }
}

int main(void) {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for (int q = 1; q <= T; q++) {
        input();
        solution(0, 0);
        cout << "#" << q << " " << ans << "\n";
    }


    return 0;
}