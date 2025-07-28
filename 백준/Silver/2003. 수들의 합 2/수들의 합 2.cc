#include <iostream>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <climits>
using namespace std;

long long arr[250001];

int main(int argc, char** argv) {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    /*
    base i = 0, j = 0, sum = i + ... + j
    sum < M인 동안
    j++
    sum > M인 동안
    i++
    sum == M인 경우
    cnt++, j++
    j < N, i < N
    */

    int i, j, cnt;
    long long sum;
    i = j = cnt = sum = 0;

    while(1) {
        if (i >= N || j >= N) break;
        if (i == j) sum = arr[i];

        if (sum < M) {
            sum += arr[++j];
        }
        else if (sum > M) {
            sum -= arr[i++];
        }
        else if (sum == M) {
            //cout << "ij = " << i << " " << j << " " << sum << "\n";
            cnt++;
            sum += arr[++j];
        }
    }

    cout << cnt;


    return 0;
}