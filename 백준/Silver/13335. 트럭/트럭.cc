#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#define ll long long
using namespace std;

int N, W, L;
int trucks[1001];
queue<int> q;

int main(int argc, char** argv) {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> W >> L;

    for (int i = 0; i < N; ++i) {
        cin >> trucks[i];
    }


    int time = 0;
    int weight = 0;
    int curtruck = 0;

    for (int i = 0; i < W; ++i) {
        q.push(0); // 다리 위 공간
    }

    while (curtruck < N) {
        time++;
        weight -= q.front();
        q.pop();

        int next_weight = trucks[curtruck];

        if (weight + next_weight <= L) {
            q.push(next_weight);
            weight += next_weight;
            curtruck++;
        }
        else {
            q.push(0); // 트럭이 못 올라가면 빈 공간으로
        }
    }

    time += W; // 마지막 트럭

    cout << time << endl;

    return 0;
}