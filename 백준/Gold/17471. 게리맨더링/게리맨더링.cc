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

int N, M;
int popul[11];
int visited[11];
vector<int> graph[11];

int visitA[11];
int visitB[11];
queue<int> q;

int ans = 10e8;

int bfs(int start, int group[11], int group_size) {
    
    bool bfs_visited[11] = {false};
    queue<int> local_q;

    local_q.push(start);
    bfs_visited[start] = true;
    
    int sum = 0;
    int count = 0;

    while(!local_q.empty()) {
        int cur = local_q.front();
        local_q.pop();

        sum += popul[cur];
        count++;

        for(int next_node : graph[cur]) {
            if (group[next_node] == 1 && !bfs_visited[next_node]) {
                bfs_visited[next_node] = true;
                local_q.push(next_node);
            }
        }
    }

    if(count != group_size) return 0;
    return sum;
}

void divide(int now, int cnt) {
    if(cnt >= 1 && cnt < N) {
        // BFS A
        // BFS B
        // 차이를 비교하여 최솟값 갱신

        for(int i=1; i<=N; i++) {
            if(visited[i]) {
                visitA[i] = 1;
                visitB[i] = 0;
            }
            else {
                visitA[i] = 0;
                visitB[i] = 1;
            }
        }

        for(int i = 1; i <= N; i++)
        {
            // printf("%d ", visited[i]);
        }
        // printf("\n");

        int asum, bsum;
        asum = bsum = 0;
        int startA, startB, cntA, cntB;
        startA = startB = -1;
        cntA = cntB = 0;
        for(int i=1; i<=N; i++) {
            if(visitA[i] == 1) {
                startA = i;
                cntA++;
            }
        }

        for(int i=1; i<=N; i++) {
            if(visitB[i] == 1) {
                startB = i;
                cntB++;
            }
        }

        if(startA != -1 && startB != -1) {
            asum = bfs(startA, visitA, cntA);
            bsum = bfs(startB, visitB, cntB);
        }

            // debug
            // cout << endl << "A visit : ";
            // for(int i=0; i<11; i++) {
            //     if(visitA[i]) cout << i << " ";
            // }
            
            // cout << endl << "B visit : ";
            // for(int i=0; i<11; i++) {
            //     if(visitB[i]) cout << i << " ";
            // }

            // cout << "\nasum, bsum : " << asum << " " << bsum << endl;

        if(asum > 0 && bsum > 0) {
            int temp = abs(asum - bsum);
            if(temp < ans) {
                ans = temp;
            }
        }
    }

    for(int i=now; i<=N; i++) {
        if(visited[i] == 0) {
            visited[i] = 1;
            divide(i+1, cnt+1);
            visited[i] = 0;
        }
    }
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> popul[i];
    }

    for(int i=1; i<=N; i++) {
        int num;
        cin >> num;
        for(int j=0; j<num; j++) {
            int input;
            cin >> input;
            graph[i].push_back(input);
        }
    }

    divide(1, 0); // 1번 노드부터, 현재 0개를 선택한 상태로 시작
    
    if (ans == 10e8) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}