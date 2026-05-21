#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graph(101);
int visited[101];

int DFS(int cur, int cutA, int cutB) {
    visited[cur] = 1;
    int cnt = 1;
    for(auto edge : graph[cur]) {
        if(visited[edge] == 1 || (cur == cutA && edge == cutB) || (cur == cutB && edge == cutA)) continue;
        cnt += DFS(edge, cutA, cutB);
    }
    
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    
    for(auto edge : wires) {
        int v1 = edge[0];
        int v2 = edge[1];
        
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    
    for(auto edge : wires) {
        int v1 = edge[0];
        int v2 = edge[1];
        
        for(int i=0; i<101; ++i) visited[i] = 0;
        
        visited[v1] = visited[v2] = 1;
        
        int cnt1 = DFS(v1, v1, v2);
        int cnt2 = n - cnt1;
        int diff = abs(cnt1 - cnt2);
        answer = min(answer, diff);
    }
    
    return answer;
}