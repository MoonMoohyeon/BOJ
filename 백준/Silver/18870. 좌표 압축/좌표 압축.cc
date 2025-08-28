#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;

int N;
int arr[1000001];
set<int> s;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        s.insert(arr[i]); // 정렬됨, 중복 제거
    }

    vector<int> compressed(s.begin(), s.end());

    for (int i = 0; i < N; i++) {
        auto it = lower_bound(compressed.begin(), compressed.end(), arr[i]); // 해당 원소 위치 반환
        cout << it - compressed.begin() << " ";
    }


    return 0;
}