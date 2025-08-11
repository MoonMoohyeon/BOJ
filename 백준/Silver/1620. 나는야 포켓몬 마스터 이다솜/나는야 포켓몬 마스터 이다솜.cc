#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <unordered_map>
using namespace std;

int N, M;
unordered_map<string, int> h;
string DAT[100001];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        h.insert({ str,i+1 });
        DAT[i + 1] = str;
    }

    for (int i = 0; i < M; i++) {
        string str;
        cin >> str;
        try {
            int value = stoi(str);
            cout << DAT[value] << "\n";
        }
        catch(exception e) {
            if (h.find(str) != h.end()) {
                cout << h[str] << "\n";
            }
        }
    }

    return 0;
}