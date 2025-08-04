#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <string>
using namespace std;

int N;

void stari(int cnt, int print, int blank) {
    if (cnt >= N) return;
    for (int i = blank; i > 1; i--) cout << " ";
    for (int i = 0; i <= print; i++) cout << "*";
    cout << "\n";
    stari(cnt + 1, print + 2, blank - 1);
}

void stard(int cnt, int print, int blank) {
    if (cnt <= 0) return;
    for (int i = 0; i < blank; i++) cout << " ";
    for (int i = 0; i <= print; i++) cout << "*";
    cout << "\n";
    stard(cnt - 1, print - 2, blank + 1);
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    stari(0, 0, N);
    //cout << "\n";
    stard(N - 1, (N - 2) * 2, 1);

    return 0;
}