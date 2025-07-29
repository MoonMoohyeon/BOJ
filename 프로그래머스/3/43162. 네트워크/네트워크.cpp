#include <string>
#include <iostream>
#include <vector>

using namespace std;
int visit[201] = {0, };
vector<vector<int>> graph;
int N;

void DFS(int src) {
    if(visit[src]) return;
    visit[src] = 1;
    for(int i=0; i<N; i++) {
        if(graph[src][i]) {
            cout << "DFS:" << i << "\n";
            DFS(i);
        }
    }
    
    return;
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    graph = computers;
    N = n;
    
    for(int i=0; i<n; i++) {
        if(!visit[i]) {
            cout << answer;
            answer++;
            DFS(i);
        }
    }
    
    
    return answer;
}