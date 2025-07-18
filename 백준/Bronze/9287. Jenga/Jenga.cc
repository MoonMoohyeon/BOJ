#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int l, n, flag;
    char row[4];
    cin >> l;
    for (int i = 0; i < l; i++) {
        cin >> n;
        flag = 0;
        for (int j = 0; j < n; j++) {
            cin >> row;
            for (int k = 1; k < 4; k++) {
                if(row[k] == '0' && row[k-1] == '0')flag = 1;
            }
        }
        if(flag) cout << "Case " << i + 1 << ": " << "Fallen\n";
        else cout << "Case " << i + 1 << ": " << "Standing\n";
    }

    return 0;
}
