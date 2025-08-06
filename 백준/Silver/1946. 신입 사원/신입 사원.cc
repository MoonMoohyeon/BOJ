#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <climits>
using namespace std;

vector<pair<int, pair<int, int>>> ap; // 지원자, 코딩, 면접

vector<int> coding;
vector<int> interview;

bool cmp(pair<int, pair<int, int>> l, pair<int, pair<int, int>> r) {
    // 코딩 순서로 정렬한다.
    if (l.second.first > r.second.first) return false;
    else return true;
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        ap.clear();
        for (int i = 1; i <= N; i++) {
            int a, b;
            cin >> a >> b;
            ap.push_back({ i, {a,b} });
        }

        /*
            코딩으로만 정렬한다.
            자기 뒤쪽으로 면접까지 더 못본 사람이 있는지 찾는다.
        */

        sort(ap.begin(), ap.end(), cmp);
        //for (int i = 0; i < N; i++) {
        //    cout << ap[i].second.first << " ";
        //}

        int cnt = 1;
        int mini = ap[0].second.second;
        for (int i = 1; i < N; i++) {
            if (ap[i].second.second < mini) {
                cnt++;
                mini = ap[i].second.second;

            }
        }

        cout << cnt << "\n";
    }
    return 0;
}