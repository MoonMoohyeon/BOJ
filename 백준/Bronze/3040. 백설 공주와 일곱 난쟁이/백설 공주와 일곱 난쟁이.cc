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
int arr[101];
int visited[101] = { 0, };
vector<int> v;

void find(int n, int sum, int last) {
    if (n == 7 && sum == 100) {
        for (int i = 0; i < 7; i++) {
            cout << v[i] << "\n";
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        if (sum < 100) {
            if (visited[arr[i]] == 0 && last < arr[i]) {
                v.push_back(arr[i]);
                visited[arr[i]] = 1;
                find(n + 1, sum + arr[i], arr[i]);
                v.pop_back();
                visited[arr[i]] = 0;
            }
        }
    }

}

int main(int argc, char** argv) {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    N = 9;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);
    find(0, 0, -1);

    return 0;
}