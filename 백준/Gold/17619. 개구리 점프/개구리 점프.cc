#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct namoo {
    int idx, x1, x2, y;
};

namoo namu[100001];
pair<int, int> q[100001];
int disjoint[100001] = { 0, };

bool comp(namoo a, namoo b) {
    if (a.x1 < b.x1) return true;
    if (a.x1 > b.x1) return false;
    if (a.y < b.y) return true;
    if (a.y > b.y) return false;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q;
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        int x1, x2, y;
        cin >> x1 >> x2 >> y;
        namu[i].idx = i + 1;
        namu[i].x1 = x1;
        namu[i].x2 = x2;
        namu[i].y = y;
    }

    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        q[i] = { a,b };
    }

    /*
        a -> b 건너뛸 수 있는 조건
        b.x1 <= a.x2이다. b.y와 a.y 사이에 다른 통나무가 없다.

        x1으로 정렬한다(오름차순)
        같으면 y가 낮은 순서로 정렬
        left.x2 > right.x1인 동안 같은 집합으로 묶는다. (점프 가능)

        끊기면 다른 집합으로 새로 시작한다.
    */

    sort(namu, namu + N, comp);


    int set = 1;
    disjoint[namu[0].idx] = set;
    int mx = namu[0].x2;
    
    for (int i = 0; i < N - 1; i++) {
        //cout << "mx : " << mx << "\n";
        if (mx >= namu[i + 1].x1) {
            disjoint[namu[i + 1].idx] = set;
            if (namu[i + 1].x2 > mx) {
                mx = namu[i + 1].x2;
            }
        }
        else {
            set++;
            disjoint[namu[i + 1].idx] = set;
            mx = namu[i + 1].x2;
        }
    }

    //cout << "disjoint: ";
    //for (int i = 1; i <= N; i++) {
    //    cout << disjoint[i] << " ";
    //}
    //cout << "\n";

    for (int i = 0; i < Q; i++) {
        int src = q[i].first;
        int dst = q[i].second;

        if (disjoint[src] == disjoint[dst]) {
            cout << "1" << "\n";
        }
        else {
            cout << "0" << "\n";
        }
    }

    return 0;
}