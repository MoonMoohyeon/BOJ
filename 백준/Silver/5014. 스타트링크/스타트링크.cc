#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue<pair<int,int>> q;

int piso[1000001] = {0, };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int F, S, G, U, D;
    int up, down;

    cin >> F >> S >> G >> U >> D;

    piso[S] = 1;

    up = S + U;
    down = S - D;
    if (up > F) up = 0;
    if (down <= 0) down = 0;
    piso[up] = 1;
    piso[down] = 1;
    q.push({ up, down });
    piso[0] = 0;

    while (!q.empty()) {
        auto next = q.front();
        q.pop();

        if (next.first != next.first + U && next.first != 0) {
            up = next.first + U;
        }
        if (next.first != next.first - D && next.first != 0) {
            down = next.first - D;
        }
        if (up > F) up = 0;
        if (down <= 0) down = 0;
        if (piso[up] == 0 || piso[down] == 0) {
            q.push({ up, down });
            if (piso[up] == 0) {
                piso[up] = piso[next.first] + 1;
            }
            if (piso[down] == 0) {
                piso[down] = piso[next.first] + 1;
            }
        }

        if (next.second != next.second + U && next.second != 0) {
            up = next.second + U;
        }
        if (next.second != next.second - D && next.second != 0) {
            down = next.second - D;
        }
        if (up > F) up = 0;
        if (down <= 0) down = 0;
        if (piso[up] == 0 || piso[down] == 0) {
            q.push({ up, down });
            if (piso[up] == 0) {
                piso[up] = piso[next.second] + 1;
            }
            if (piso[down] == 0) {
                piso[down] = piso[next.second] + 1;
            }
        }
    }

    /*for (int i = 1; i <= F; i++) {
        printf("%d ", piso[i]);
    }*/

    if (G == S) cout << "0\n";
    else if (piso[G] == 0) {
        cout << "use the stairs\n";
    }
    else {
        cout << piso[G];
    }

    return 0;
}
