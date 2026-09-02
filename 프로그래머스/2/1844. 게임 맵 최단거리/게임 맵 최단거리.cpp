#include<vector>
#include<iostream>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;

int solution(vector<vector<int> > maps)
{
    
    queue<pair<int,int>> q;

    int dy[4] = {0,0,1,-1};
    int dx[4] = {1,-1,0,0};
    
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    
    vector<vector<int>> visit(n, vector<int>(m, 0));
    
    // printf("%d %d", n, m);
    
    q.push({0,0});
    visit[0][0] = 1;
    
    while(!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        
        for(int i=0; i<4; ++i) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(visit[ny][nx] != 0) continue;
            if(maps[ny][nx] == 0) continue;
            
            visit[ny][nx] = visit[cy][cx] + 1;
            q.push({ny,nx});
        }
    }
    
    answer = visit[n-1][m-1];
    if(answer == 0) answer = -1;
    
    return answer;
}