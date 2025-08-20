#include <iostream>
#include <algorithm>
#include <utility>
#include <map>
#include <vector>

using namespace std;

int N;

struct comp {
    bool operator()(int left, int right) const {
        if (left < right) return true;
        return false;
    }
};

map<int, int, comp> m; // greater<pair<int,int>>

void pop(int rank) {
    // pop
            // b == 꺼낼 순위, 한 개만 빼기
    int cnt = 0;
    // m.erase(k->first)를 호출하는 순간, map에서 해당 원소가 삭제되면서 그 원소를 가리키고 있던 반복자 k가 무효화
    // k++가 실행되는 순간 무효화된 반복자에 접근하게 되어 프로그램이 비정상적으로 종료
    //for (auto k = m.begin(); k != m.end(); k++) {
    //    cnt++;
    //    if (cnt == b) {
    //        if (k->second == 1) {
    //            cout << "output : " << k->first << " " << k->second << "\n";
    //            m.erase(k->first);
    //        }
    //        else {
    //            cout << "output : " << k->first << " " << k->second << "\n";
    //            k->second--;
    //        }
    //        break;
    //    }
    //}

    // C++11부터 map::erase는 삭제된 원소의 다음 원소를 가리키는 유효한 반복자를 반환
    for (auto k = m.begin(); k != m.end(); /* 여기서 k++를 제거 */) {
        cnt += k->second;
        //cout << "cnt : " << cnt << endl;
        if (cnt >= rank) {
            if (k->second == 1) {
                //cout << "output : " << k->first << " " << k->second << "\n";
                cout << k->first << "\n";
                // k를 삭제하고, k에 다음 원소의 반복자를 대입
                k = m.erase(k);
            }
            else {
                //cout << "output : " << k->first << " " << k->second << "\n";
                cout << k->first << "\n";
                k->second--;
                k++; // 삭제하지 않았으므로 수동으로 다음으로 이동
            }
            break; // 원하는 작업을 끝냈으므로 break
        }
        else {
            k++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a;
        if (a == 1) {
            cin >> b;
            pop(b);
        }
        if (a == 2) {
            cin >> b >> c;
            // push
            // b == 맛, c == 개수만큼 넣기, 음수이면 빼는 것
            if (c > 0) {
                m[b] += c; // 키가 없을 때는 새로 만들고, 있을 때는 기존 값에 접근한다.
                // m.insert({ b, c });
            }
            else if (c < 0) {
                // [] 연산자를 사용하면 코드가 훨씬 간결해집니다.
                // 만약 키 b가 없다면 아무 일도 일어나지 않아야 하므로, find를 먼저 쓰는 것이 안전합니다.
                auto it = m.find(b);
                if (it != m.end()) {
                    it->second += c; // c가 음수이므로 개수가 줄어듦
                    // 만약 개수가 0 이하가 되면 맵에서 완전히 제거
                    if (it->second <= 0) {
                        m.erase(it);
                    }
                }
            }
        }
    }

    return 0;
}