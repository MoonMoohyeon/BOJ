#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <climits>
using namespace std;

int T, N;
int weights[10];
bool visited[10] = {false, };

int factorial[10];
int exponential[10];

int cnt = 0;
int temp = 0;

/*
    추를 올릴 때 항상 sum(left)가 sum(right)보다 커야 한다.
    right에 n개를 올렸을 때 left의 n-1개를 올린다.
    sum(right(n)) < sum(left(n-1))일 때 가능한 모든 순열의 수를 구한다.

    추의 개수만큼 순열을 생성한다.
    왼쪽과 오른쪽으로 추를 조건에 맞게 분배하는 경우만 남긴다.
*/

// @params 여태까지 놓은 추의 수, 왼쪽에 놓은 추의 무게, 오른쪽에 놓은 추의 무게
int recursive(int n, int leftsum, int rightsum) {
    if(n >= N) {
        cnt++;
        return 1;
    }

    // 왼쪽에 올린 추의 무게가 남은 추의 무게의 합보다 큰 경우 가지치기
    if(leftsum >= (temp - leftsum)) { // temp = 모든 추의 무게의 합, temp - leftsum = 모든 추의 무게의 합에서 왼쪽에 올린 무게를 뺀 값 -> 오른쪽에 올린 추의 무게 + 남은 추의 무게
        // cnt += pow(2, N-n) * tgamma(N-n+1); // n이 현재까지 올린 추의 개수, N-n = 남은 추의 개수
        // return pow(2, N-n) * tgamma(N-n+1); // 순열을 재귀 호출로 계산하지 않고 남은 추들만으로 순열을 계산한 값을 반환한다.
        // cout << exponential[N-n] << " " << factorial[N - n] << "\n";
        cnt += exponential[N-n] * factorial[N - n];
        return exponential[N-n] * factorial[N - n];
    }

    for(int i=0; i<N; i++) {
        if(visited[i] == false) {
            visited[i] = true;
            recursive(n+1, leftsum + weights[i], rightsum);
            
            if(leftsum >= rightsum + weights[i]) { // 오른쪽의 무게가 더 큰 경우는 고려하지 않는다.
                recursive(n+1, leftsum, rightsum + weights[i]);
            }

            visited[i] = false;
        }
    }

    return 0;
}

void CalcFactorial(int n) {
    factorial[0] = 1;
    for(int i = 1; i < n; i++) {
        factorial[i] = factorial[i-1] * i;
    }

    return;
}

void CalcExponential(int n) {
    exponential[0] = 1;
    for(int i = 1; i < n; i++) {
        exponential[i] = exponential[i-1] * 2;
    }

    return;
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    CalcFactorial(10);
    CalcExponential(10);

    cin >> T;

    for(int q=1; q<=T; q++) {
        cin >> N;
        cnt = 0;
        temp = 0;

        for(int i=0; i<N; i++) {
            cin >> weights[i];
            temp += weights[i];
            visited[i] = false;
        }

        recursive(0, 0, 0); // 오른쪽에 먼저 올리는 경우는 고려하지 않는다.

        // for(int i=0; i<N; i++) {
        //     if(visited[i] == false) {
        //         visited[i] = true;
        //         recursive(1, weights[i], 0); // 오른쪽에 먼저 올리는 경우는 고려하지 않는다.
        //         visited[i] = false;
        //     }
        // }

        cout << "#" << q << " " << cnt << "\n";
    }

    return 0;
}