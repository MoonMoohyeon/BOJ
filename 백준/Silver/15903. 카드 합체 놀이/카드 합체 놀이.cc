#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define ll long long
using namespace std;

priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
int N, M;
ll cards[1001];

int main(int argc, char* argv[]) {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i) {
        scanf("%lld", &cards[i]);
        pq.push({ cards[i], i });
    }

    for (int i = 0; i < M; ++i) {
        ll first_v = pq.top().first;
        int first_i = pq.top().second;
        pq.pop();

        ll second_v = pq.top().first;
        int second_i = pq.top().second;
        pq.pop();

        ll res_v = first_v + second_v;
        cards[first_i] = res_v;
        cards[second_i] = res_v;

        pq.push({ res_v, first_i });
        pq.push({ res_v, second_i });
    }

    ll sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += cards[i];
    }

    printf("%lld", sum);

    return 0;
}