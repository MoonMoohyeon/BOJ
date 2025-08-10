#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <climits>
using namespace std;

stack<int> s;
int seq[100001];
vector<char> op;
int N, K;

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    /*
        1부터 순서대로 숫자를 넣어서 해당 수열을 만들어야 한다.

        스택으로 정렬하지 못하는 경우가 있다.
        2 3 1 순서로 들어오면 스택으로 정렬이 안 된다.

        어떤 수열 A가 스택으로 생성될 수 있다면, 그 수열 A는 스택으로 정렬 가능
    */

    for (int i = 0; i < N; i++) {
        cin >> seq[i];
    }

    int num = 1;
    for (int i = 0; i < N; i++) {
        int target = seq[i]; // 이번에 만들어야할 숫자
        while (num <= target) { // 현재 숫자를 만들기 위해 스택에 넣는다.
            s.push(num++); // 수열에 뒷 부분에 작은 수가 나오는 경우 이미 스택에 들어가 있다.
            op.push_back('+');
        }
        if (s.top() == target) { // 현재 숫자를 꺼낸다.
            s.pop();
            op.push_back('-');
        }
        else { // 스택 맨 윗부분이 만들어야할 수열과 다르면 만들 수 없다.
            cout << "NO\n"; 
            return 0;
        }
    } // 더 작은 숫자를 꺼내야 하는데, 그보다 더 큰 숫자가 스택 위에서 길을 막고 있는 경우 -> 정렬이 불가능한 경우

    for (int i = 0; i < op.size(); i++) {
        cout << op[i] << "\n";
    }


    return 0;
}