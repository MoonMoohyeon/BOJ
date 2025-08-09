#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
using namespace std;

int N, M;
int arr[101];
int mark[2000001] = { 0, };

int main(int argc, char** argv) {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= M; j++) {
            if (j % arr[i] == 0 && mark[j] == 0) {
                mark[j] = 1;
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}