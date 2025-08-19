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

int T;
int board[9][9];
int visited[10];
string ans;

void resetvisit() {
    for (int i = 0; i < 10; i++) {
        visited[i] = 0;
    }
}

int checkall() {
    for (int i = 0; i < 9; i++) {
        resetvisit();
        for (int j = 0; j < 9; j++) {
            visited[board[i][j]]++;
            if (visited[board[i][j]] >= 2) {
                return 0;
            }
        }
    }

    for (int j = 0; j < 9;j++) {
        resetvisit();
        for (int i = 0; i < 9;i++) {
            visited[board[i][j]]++;
            if (visited[board[i][j]] >= 2) {
                return 0;
            }
        }
    }

    return 1;
}

int checksub(int y, int x) {
    for (int i = y; i < y + 3; i++) {
        for (int j = x; j < x + 3; j++) {
            visited[board[i][j]]++;
            if (visited[board[i][j]] >= 2) {
                return 0;
            }
        }
    }

    return 1;
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for(int t=1; t<=T; t++) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cin >> board[i][j];
            }
        }
        ans = "CORRECT";
        int flag = 0;
        if (!checkall()) {
            ans = "INCORRECT";
        }
        else {
            for (int i = 0; i < 9; i += 3) {
                for (int j = 0; j < 9; j += 3) {
                    resetvisit();
                    if (!checksub(i, j)) {
                        ans = "INCORRECT";
                        flag = 1;
                        break;
                    }
                }
                if (flag) break;
            }
        }

        cout << "Case " << t << ": " << ans << "\n";
    }

    return 0;
}