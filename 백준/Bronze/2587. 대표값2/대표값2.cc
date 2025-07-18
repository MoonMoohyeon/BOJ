#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n[5];
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        cin >> n[i];
        sum += n[i];
    }
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (n[j] < n[i]) swap(n[j], n[i]);
        }
    }

    cout << sum / 5 << "\n" << n[2];

    return 0;
}
