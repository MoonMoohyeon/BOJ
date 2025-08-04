#include <iostream>
#include <vector>

using namespace std;

int arr[1001] = { 0, };
bool mark[1001] = { false, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    int cur = 1; // 현재 풍선의 위치
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        cout << cur << " ";
        mark[cur] = true;
        cnt++;

        if (cnt == N) {
            break;
        }

        int note = arr[cur];

        if (note > 0) {
            int t = 0;
            while (t < note) {
                cur++;
                if (cur > N) {
                    cur = 1;
                }
                if (!mark[cur]) {
                    t++;
                }
            }
        }
        else { // note < 0
            int t = 0;
            int nnote = -note;
            while (t < nnote) {
                cur--;
                if (cur < 1) {
                    cur = N;
                }
                if (!mark[cur]) {
                    t++;
                }
            }
        }
    }

    cout << "\n";

    return 0;
}