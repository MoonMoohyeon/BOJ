#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include<algorithm>
#include <utility>
#include <string>
using namespace std;

int N;
int hp[3];
int visited[61][61][61] = { 0, };
int ans = 10e8;

struct SCV {
    int SCV1, SCV2, SCV3;
    int cnt = 0;
};

void BFS() {
    queue<SCV> q;
    q.push({ hp[0],hp[1],hp[2], 0 });
    visited[hp[0]][hp[1]][hp[2]] = 1;

    while (!q.empty()) {
        int s1 = q.front().SCV1;
        int s2 = q.front().SCV2;
        int s3 = q.front().SCV3;
        int cnt = q.front().cnt;
        //cout << "q : " << s1 << " " << s2 << " " << s3 << " " << cnt << "\n";
        q.pop();
        if (s1 <= 0 && s2 <= 0 && s3 <= 0) {
            ans = min(cnt, ans);
            cout << ans;
            return;
        }

        int ns1, ns2, ns3;
        if (s1 - 9 < 0) ns1 = 0;
        else ns1 = s1 - 9;
        if (s2 - 3 < 0) ns2 = 0;
        else ns2 = s2 - 3;
        if (s3 - 1 < 0) ns3 = 0;
        else ns3 = s3 - 1;
        if (!visited[ns1][ns2][ns3]) {
            q.push({ ns1, ns2, ns3, cnt + 1 });
            visited[ns1][ns2][ns3] = 1;
        }

        if (s1 - 9 < 0) ns1 = 0;
        else ns1 = s1 - 9;
        if (s2 - 1 < 0) ns2 = 0;
        else ns2 = s2 - 1;
        if (s3 - 3 < 0) ns3 = 0;
        else ns3 = s3 - 3;
        if (!visited[ns1][ns2][ns3]) {
            q.push({ ns1, ns2, ns3, cnt + 1 });
            visited[ns1][ns2][ns3] = 1;
        }

        if (s1 - 1 < 0) ns1 = 0;
        else ns1 = s1 - 1;
        if (s2 - 9 < 0) ns2 = 0;
        else ns2 = s2 - 9;
        if (s3 - 3 < 0) ns3 = 0;
        else ns3 = s3 - 3;
        if (!visited[ns1][ns2][ns3]) {
            q.push({ ns1, ns2, ns3, cnt + 1 });
            visited[ns1][ns2][ns3] = 1;
        }

        if (s1 - 3 < 0) ns1 = 0;
        else ns1 = s1 - 3;
        if (s2 - 9 < 0) ns2 = 0;
        else ns2 = s2 - 9;
        if (s3 - 1 < 0) ns3 = 0;
        else ns3 = s3 - 1;
        if (!visited[ns1][ns2][ns3]) {
            q.push({ ns1, ns2, ns3, cnt + 1 });
            visited[ns1][ns2][ns3] = 1;
        }

        if (s1 - 1 < 0) ns1 = 0;
        else ns1 = s1 - 1;
        if (s2 - 3 < 0) ns2 = 0;
        else ns2 = s2 - 3;
        if (s3 - 9 < 0) ns3 = 0;
        else ns3 = s3 - 9;
        if (!visited[ns1][ns2][ns3]) {
            q.push({ ns1, ns2, ns3, cnt + 1 });
            visited[ns1][ns2][ns3] = 1;
        }

        if (s1 - 3 < 0) ns1 = 0;
        else ns1 = s1 - 3;
        if (s2 - 1 < 0) ns2 = 0;
        else ns2 = s2 - 1;
        if (s3 - 9 < 0) ns3 = 0;
        else ns3 = s3 - 9;
        if (!visited[ns1][ns2][ns3]) {
            q.push({ ns1, ns2, ns3, cnt + 1 });
            visited[ns1][ns2][ns3] = 1;
        }
    }
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> hp[i];
    }
    BFS();
    //cout << ans;

    
    return 0;
}