#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int minutes[1001];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    int result = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> minutes[i];
    }

    sort(minutes, minutes+t);

    for (int i = 0; i < t; i++) {
        for (int j = 0; j <= i; j++) {
            result += minutes[j];
       }
    }
    
    cout << result;
    
    return 0;
}
