#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, X;
vector<int> graph[100001];
vector<int> graph_rev[100001];
int visited[100001] = { 0, };

void DFS(int start) {
    
    for (auto i = graph[start].begin(); i != graph[start].end(); i++) {
        if (visited[*i] == 0) {
            visited[*i] = 1;
            DFS(*i);
        }
    }

    return;
}

void DFS_rev(int start) {

    for (auto i = graph_rev[start].begin(); i != graph_rev[start].end(); i++) {
        if (visited[*i] == 0) {
            //cout << "visited : " << *i << endl;
            visited[*i] = 1;
            DFS_rev(*i);
        }
    }

    return;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> X;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph_rev[b].push_back(a);
    }

    //for (int i = 1; i <= N; i++) {
    //    cout << "node " << i << " : ";
    //    for (auto j = graph[i].begin(); j != graph[i].end(); j++) {
    //        cout << *j << " ";
    //    }
    //    cout << endl;
    //}

    //cout << endl;
    //for (int i = 1; i <= N; i++) {
    //    cout << "node " << i << " : ";
    //    for (auto j = graph_rev[i].begin(); j != graph_rev[i].end(); j++) {
    //        cout << *j << " ";
    //    }
    //    cout << endl;
    //}

    int tcnt, rcnt;
    tcnt = rcnt = 0;
    DFS(X);
    for (int i = 1; i <= N; i++) { // 내 밑에 몇 명 있는지
        //cout << visited[i] << " ";
        if (visited[i] == 1) {
            rcnt++;
        }
        visited[i] = 0;
    }
    //cout << endl << "vistied : ";
    //for (int i = 1; i <= N; i++) {
    //    cout << visited[i] << " ";
    //}
    DFS_rev(X);
    for (int i = 1; i <= N; i++) { // 내 위에 몇 명 있는지
        //cout << visited[i] << " ";
        if (visited[i] == 1) {
            tcnt++;
        }
    }

    int tbound, rbound;
    tbound = 1;
    rbound = N;
    //cout << tcnt << " " << rcnt << "\n";
    cout << tbound + tcnt << "\n" << rbound - rcnt;


    return 0;
}