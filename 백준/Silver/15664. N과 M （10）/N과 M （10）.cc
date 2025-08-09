#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
using namespace std;

int N, M;
vector<int> numbers;
//int numbers[9] = { 0, };
int visited[9] = { 0, };
vector<int> selected;

void NM(int cnt) {
    if (cnt == M) {
        for (auto i = selected.begin(); i != selected.end(); i++) {
            cout << *i << " ";
        }
        cout << "\n";
        return;
    }

    int last = -1;
    int back = -1;
    if (!selected.empty()) back = selected.back();
    for (int i = 0; i < numbers.size(); i++) {
        if (!visited[i] && last != numbers[i] && back <= numbers[i]) {
            selected.push_back(numbers[i]);
            visited[i] = 1;
            last = numbers[i]; // 같은 depth에서 중복 방지
            NM(cnt + 1);
            selected.pop_back();
            visited[i] = 0;
        }
    }
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;
        numbers.push_back(input);
    }

    sort(numbers.begin(), numbers.end());
    NM(0);

    return 0;
}