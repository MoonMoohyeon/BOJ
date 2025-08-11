#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <unordered_set>
using namespace std;

int N, M;
unordered_set<string> h;
vector<string> db;

int main(void)
{
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        h.insert(str);
    }

    int cnt = 0;
    for (int i = 0; i < M; i++) {
        string str;
        cin >> str;
        if (h.count(str)) {
            cnt++;
            db.push_back(str);
        }
    }

    sort(db.begin(), db.end());
    cout << cnt << "\n";
    for (int i = 0; i < db.size(); i++) {
        cout << db[i] << "\n";
    }

    return 0;
}