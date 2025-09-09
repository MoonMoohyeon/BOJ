#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
#define INF 10e8

int N;
int origin_board[20][20];
int ans = 0;

//enum {
//    DOWN = 0,
//    LEFT = 1,
//    UP = 2,
//    RIGHT = 3
//};

int cur_dir = 0;

void turnLeft(int board[20][20]) {
    int temp[20][20];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            temp[N - 1 - j][i] = board[i][j];
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            board[i][j] = temp[i][j];
        }
    }
}

void pack(int board[20][20]) {
    for (int j = 0; j < N; ++j) {
        /*
            1. 0이 아닌 블록들을 저장한다.
            2. 합친다.
            3. 합친 것을 아래쪽에 놓는다.
            4. 모든 열에 대해 반복한다.
        */

        vector<int> temp;
        for (int i = N - 1; i >= 0; --i) {
            if (board[i][j] != 0) {
                temp.push_back(board[i][j]);
            }
        }

        for (int i = 0; i < temp.size(); ++i) {
            if (i+1 < temp.size() && temp[i] == temp[i + 1]) {
                temp[i] *= 2;
                temp.erase(temp.begin() + i + 1);
            }
        }

        for (int i = 0; i < N; ++i) { // 초기화
            board[i][j] = 0;
        }

        for (int i = 0; i < temp.size(); ++i) {
            board[N - 1 - i][j] = temp[i];
        }
    }
}

void simulation(int sequence[5]) {
    int cur_board[20][20];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cur_board[i][j] = origin_board[i][j];
        }
    }

    for (int i = 0; i < 5; ++i) {
        int dir = sequence[i];

        for (int j = 0; j < dir; ++j) { // 방향에 맞게 돌리기 / dir만큼
            turnLeft(cur_board);
        }

        pack(cur_board); // 돌렸으면 블록 합치기(아래로 내리기)
    }

    for (int i = 0; i < N; ++i) { // 검사
        for (int j = 0; j < N; ++j) {
            ans = max(ans, cur_board[i][j]);
        }
    }
}

void select(int cnt, int sequence[5]) {
    if (cnt == 5) {
        simulation(sequence);
        return;
    }

    // 4방향 중에 중복 포함 5개를 고르기
    for (int i = 0; i < 4; ++i) {
        sequence[cnt] = i;
        select(cnt + 1, sequence);
    }
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> origin_board[i][j];
        }
    }

    int sequence[5];
    select(0, sequence);
    cout << ans;

    return 0;
}