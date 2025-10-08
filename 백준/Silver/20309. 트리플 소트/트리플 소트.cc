#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    vector<int> arr(N);
    vector<int> sortedArr(N);

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        sortedArr[i] = arr[i];
    }

    sort(sortedArr.begin(), sortedArr.end());

    bool canSort = true;
    for (int i = 0; i < N; ++i) {
        int originalParity = i % 2;

        auto it = lower_bound(sortedArr.begin(), sortedArr.end(), arr[i]);
        int j = distance(sortedArr.begin(), it);

        int sortedParity = j % 2;

        // 원래 인덱스의 홀짝과, 정렬 후 인덱스의 홀짝이 다르면 정렬 불가
        if (originalParity != sortedParity) {
            canSort = false;
            break;
        }
    }

    if (canSort) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

    return 0;
}