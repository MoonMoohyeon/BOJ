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
int numbers[9] = { 0, };
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


    for (int i = 0; i < N; i++) {
        if (!visited[i])
        {
            selected.push_back(numbers[i]);
            visited[i] = 1;
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
        cin >> numbers[i];
    }
    sort(numbers, numbers + N);
    NM(0);

    return 0;
}