#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

const int INF = 10000009;

struct cmp {
    bool operator()(const pair<int,int>& a, const pair<int, int>& b) const {
        if(a.first != b.first) {
            return a.first > b.first;
        }
        else {
            return a.second < b.second;
        }
    }
};

priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

vector<vector<pair<int,int>>> graph(51);
int dist[51] = {0,};

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    
    for(int i=0; i<51; ++i) {
        dist[i] = INF;
    }
    dist[1] = 0;
    
    for (int i = 0; i < road.size(); ++i) {
        int u = road[i][0];
        int v = road[i][1];
        int cost = road[i][2];
        graph[u].push_back({cost, v});
        graph[v].push_back({cost, u});
    }
    
    pq.push({0, 1});
    
    while(!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();
        
        int cdist = cur.first;
        int cnode = cur.second;
        
        if(cdist > dist[cnode]) continue;
        
        for(int i=0; i<graph[cnode].size(); ++i) {
            int cost = graph[cnode][i].first;
            int nnode = graph[cnode][i].second;
            int ndist = cdist + cost;
            
            if(ndist < dist[nnode]) {
                dist[nnode] = ndist;
                pq.push({ndist, nnode});
            }
        }
    }
    
    for(int i=1; i<=N; ++i) {
        if(dist[i] <= K) answer++;
    }
    

    return answer;
}