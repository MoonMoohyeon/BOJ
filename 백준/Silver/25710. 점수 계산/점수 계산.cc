#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <climits>
using namespace std;


int N;

int arr[100001];
int set[1000];

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        set[arr[i]]++;
    }

    int temp, sum, ans;
    ans = 0;
    for (int i = 1; i < 1000; i++) {
        for (int j = i; j < 1000; j++) {
            if (arr[i] > 999 || arr[j] > 999) continue;
            if (set[i] > 0 && set[j] > 0) {
                if (i != j) {
                    sum = 0;
                    temp = i * j;
                    while (temp > 0) {
                        //cout << temp << "\n";
                        sum += temp % 10;
                        temp /= 10;
                        //cout << sum << "\n";
                    }
                    //cout << endl;
                    if (sum > ans) ans = sum;
                }
                else if (i == j) {
                    if (set[i] >= 2) {
                        sum = 0;
                        temp = i * j;
                        while (temp > 0) {
                            //cout << temp << "\n";
                            sum += temp % 10;
                            temp /= 10;
                            //cout << sum << "\n";
                        }
                        //cout << endl;
                        if (sum > ans) ans = sum;
                    }
                }
            }
        }
    }

    cout << ans;

    return 0;
}