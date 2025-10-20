#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;

int G, P;
int parent[100001];

int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void uni(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        parent[a] = b;
    }
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> G >> P;

    for (int i = 1; i <= G; ++i) {
        parent[i] = i;
    }

    int cnt = 0;
    for (int i = 0; i < P; ++i) {
        int g;
        cin >> g;

        int root = find(g);
        if (root <= 0) {
            break;
        }
        cnt++;

        // 다음 find로 찾아지는 root는 1만큼 감소
        uni(root, root - 1);
    }

    cout << cnt << endl;

    return 0;
}