#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <climits>
using namespace std;

queue<int> q;
int N, K;

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        q.push(i);
    }

    cout << "<";
    while(!q.empty()) {
        for (int j = 0; j < K - 1; j++) {
            int t = q.front();
            q.pop();
            q.push(t);
        }
        if (q.size() == 1) break;
        cout << q.front() << ", ";
        q.pop();
    }
    cout << q.front() << ">";


    return 0;
}