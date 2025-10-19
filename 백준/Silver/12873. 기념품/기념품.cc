#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <numeric>
using namespace std;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    if (N == 1) {
        cout << 1 << endl;
        return 0;
    }

    vector<int> arr(N);
    iota(arr.begin(), arr.end(), 1);

    long long stage = 1;
    int current_idx = 0;

    while (arr.size() > 1) {
        long long cnt = (stage * stage * stage) - 1; // t ^ 3 - 1
        int remove = (current_idx + cnt) % arr.size();
    
        arr.erase(arr.begin() + remove);
        current_idx = remove;
        stage++;
    }

    cout << arr[0] << endl;

    return 0;
}