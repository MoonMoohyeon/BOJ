#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;


int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int maxdistance = 0;
    int distance[20001] = { 0, };
    vector<vector<int>> graph(n + 1);
    queue<int> q;

    for (int i = 0; i < edge.size(); ++i) {
        int a = edge[i][0];
        int b = edge[i][1];

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    q.push(1);
    int cur = 1;
    distance[cur] = 1;
    while(!q.empty()) {
        cur = q.front();
        q.pop();
    for (int next : graph[cur]) {
            if (distance[next] != 0) continue;

            distance[next] = distance[cur] + 1;
            maxdistance = max(maxdistance, distance[next]);
            q.push(next);
        }
    }
    
    for(int i=1; i<=n; ++i) {
        printf("%d", distance[i]);
    }
    
    for(int i=1; i<=n; ++i) {
        if(distance[i] == maxdistance && distance[i] != 0) answer++;
    }
    
    return answer;
}