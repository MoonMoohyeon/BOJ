#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int T, N;
string p;
string arrinput;
deque<int> dq;

void printResult(bool isReversed) {
    cout << "[";
    if (isReversed) {
        // 뒤집힌 상태면 뒤에서부터 출력
        for (auto it = dq.rbegin(); it != dq.rend(); ++it) {
            cout << *it;
            if (it + 1 != dq.rend()) {
                cout << ",";
            }
        }
    }
    else {
        // 정방향 상태면 앞에서부터 출력
        for (auto it = dq.begin(); it != dq.end(); ++it) {
            cout << *it;
            if (it + 1 != dq.end()) {
                cout << ",";
            }
        }
    }
    cout << "]\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> p;
        cin >> N;
        cin >> arrinput;

        dq.clear();

        string numStr = "";
        for (int i = 1; i < arrinput.length() - 1; i++) {
            if (isdigit(arrinput[i])) {
                numStr += arrinput[i];
            }
            else { // 쉼표를 만났을 때
                if (!numStr.empty()) {
                    dq.push_back(stoi(numStr));
                    numStr = "";
                }
            }
        }
        if (!numStr.empty()) { // 마지막 숫자 처리
            dq.push_back(stoi(numStr));
        }

        bool isReversed = false;
        bool isError = false;

        for (int i = 0; i < p.size(); i++) {
            if (p[i] == 'R') {
                isReversed = !isReversed;
            }
            if (p[i] == 'D') {
                if (dq.empty()) {
                    isError = true;
                    break;
                }

                if (isReversed) {
                    dq.pop_back();
                }
                else {
                    dq.pop_front();
                }
            }
        }
        if (isError) {
            cout << "error\n";
        }
        else {
            printResult(isReversed);
        }
    }


    return 0;
}