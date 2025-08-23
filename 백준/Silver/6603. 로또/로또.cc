#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <map>

using namespace std;

int numbers[14];
int visited[14];
int k = 1;

void select(int cnt, int start) {
    if (cnt >= 6) {
        for (int i = 0; i < k; i++) {
            if (visited[i]) {
                cout << numbers[i] << " ";
            }
        }
        cout << "\n";
        return;
    }

    for (int i = start; i < k; i++) {
        if (visited[i]) continue;
        visited[i] = 1;
        select(cnt + 1, i + 1);
        visited[i] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while (k != 0) {
        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> numbers[i];
        }

        select(0, 0);
        cout << "\n";
    }

    return 0;
}