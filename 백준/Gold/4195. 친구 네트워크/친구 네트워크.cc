#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <set>
#include <queue>
#include <cstring>
using namespace std;

int T, N, M;
map<string, int> name_to_idx;
map<int, string> idx_to_name;
int parent[200001];
int ran[200001];
int sz[200001];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void uni(int a, int b) {
    int ra = find(a);
    int rb = find(b);

    if (ra != rb) {
        if (ran[ra] < ran[rb]) swap(ra, rb);
        parent[rb] = ra;
        sz[ra] += sz[rb];
        if (ran[ra] == ran[rb]) ran[ra]++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        name_to_idx.clear();
        idx_to_name.clear();
        for (int i = 0; i < 200001; i++) {
            parent[i] = i;
            ran[i] = 0;
            sz[i] = 1;
        }
        int fcnt = 0;
        for (int i = 0; i < N; i++) {
            string a, b;
            cin >> a >> b;
            if (name_to_idx.find(a) == name_to_idx.end()) {
                name_to_idx[a] = fcnt;
                idx_to_name[fcnt] = a;
                fcnt++;
            }
            if (name_to_idx.find(b) == name_to_idx.end()) {
                name_to_idx[b] = fcnt;
                idx_to_name[fcnt] = b;
                fcnt++;
            }

            uni(name_to_idx[a], name_to_idx[b]);
            int ra = find(name_to_idx[a]);
            cout << sz[ra] << "\n";
        }
    }


    return 0;
}