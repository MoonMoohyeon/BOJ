#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;
vector<vector<int>> d;
int visited[9] = { 0, };
int answer = -1;
int siz = 0;

void DFS(int cnt, int cur_k) {
    answer = max(answer, cnt);

    for (int i = 0; i < siz; ++i) {
        if (!visited[i] && cur_k >= d[i][0]) {
            visited[i] = 1;
            DFS(cnt + 1, cur_k - d[i][1]);
            visited[i] = 0;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    siz = dungeons.size();
    d = dungeons;
    
    for(int i=0; i<siz; ++i) {
        DFS(0, k);
    }
    
    return answer;
}