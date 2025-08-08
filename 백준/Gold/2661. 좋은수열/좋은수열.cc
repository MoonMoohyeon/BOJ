#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <climits>
#include <cstring>
#include <queue>
#include <cmath>
#include <unordered_set>
using namespace std;

int N, M;
int flag = 0;
void good(int n, string seq) {
    if (flag) return;
    if (n >= N) {
        if (seq.size() >= N && !flag) {
            cout << seq << endl;
            flag = 1;
        }
        return;
    }

    /*
        넣고 나서
        1: back-1과 back이 같으면 안됨
        2: substr(back-1, back)과 substr(back-3, back-2)이 같으면 안됨
        3: substr(back-2, back)과 substr(back-5, back-3)이 같으면 안됨
        4: substr(back-3, back)과 substr(back-7, back-4)이 같으면 안됨
        ...
        n:  substr(back-n+1, back)과 substr(back-n+1-n, back-n)이 같으면 안됨.
    */

    for (int i = '1'; i <= '3'; i++) {
        if (i == seq.back()) {
            continue;
        }

        seq += i;
        for (int j = 2; j <= seq.size() / 2; j++) {
            //cout << "in" << endl;
            if (seq.substr(seq.size() - j, j) == seq.substr(seq.size() - j - j, j)) {
                //cout << "pop :" << seq.back() << endl;
                seq.pop_back();
                goto label;
            }
        }

        good(n + 1, seq);
        seq.pop_back();
    label:;
    }


    return;
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string test = "1212";

    //cout << test.substr(test.size() - 2, 2) << " " << test.substr(test.size() - 4, 2) << endl;
    //cout << (test.substr(test.size() - 2, 2) == test.substr(test.size() - 4, 2));
    cin >> N;
    if (N == 1) {
        cout << "1";
        return 0;
    }
    good(2, "12");

    return 0;
}