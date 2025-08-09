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
int card[500001];
int target[500001];
int DAT[20000001] = { 0, };

int main(int argc, char** argv) {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> card[i];
        if (card[i] < 0) {
            card[i] *= -1;
            DAT[card[i] + 10000000]++;
        }
        else  DAT[card[i]]++;
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> target[i];
    }

    for (int i = 0; i < M; i++) {
        if (target[i] < 0) {
            target[i] *= -1;
            cout << DAT[target[i] + 10000000] << " ";
        }
        else cout << DAT[target[i]] << " ";
    }

    return 0;
}