#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

priority_queue<int> maxpq;
priority_queue<int, vector<int>, greater<>> minpq;

int N;

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    /*
        최대 힙 - 작은 쪽 절반
        최소 힙 - 큰 쪽 절반

        힙의 크기 차이를 1 이하로 유지하기
        최대 힙의 모든 원소 < 최소 힙의 모든 원소 유지하기

        중앙 값(최대 힙의 탑)보다 크면 최소 힙으로, 아니면 최대 힙에 넣기.
        사이즈 비교 후 탑 원소를 옮기기.
    */

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if (maxpq.empty() || num <= maxpq.top()) {
            maxpq.push(num);
        }
        else {
            minpq.push(num);
        }

        if (maxpq.size() > minpq.size() + 1) {
            int temp = maxpq.top();
            maxpq.pop();
            minpq.push(temp);
        }
        else if (minpq.size() > maxpq.size()) {
            int temp = minpq.top();
            minpq.pop();
            maxpq.push(temp);
        }

        cout << maxpq.top() << "\n";
    }
    
    return 0;
}