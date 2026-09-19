#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;
vector<vector<int>> graph(52, vector<int>(52, 0));
vector<string> w;
int visited[52] = {0,};
int siz;

void makegraph(int idx) {
    for(int i=0; i<siz; ++i) {
        if(idx == i) continue;
        int wsiz = w[i].size();
        int cnt = 0;
        
        for(int j=0; j<wsiz; ++j) {
            if(w[idx][j] != w[i][j]) cnt++;
        }
        
        if(cnt == 1) {
            graph[idx][i] = 1;
            graph[i][idx] = 1;
        }
    }
}


int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    if (find(words.begin(), words.end(), target) == words.end()) {
        return 0;
    }
    
    words.push_back(begin);
    int total_words = words.size();
    int start = total_words - 1;
    int end = -1;
    w = words;
    siz = words.size();
    
    for(int i=0; i<siz; ++i) {
        makegraph(i);
        if(words[i] == target) end = i;
    }
    
    queue<int> q;
    
    q.push(start);
    visited[start] = 1;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for(int i=0; i<graph[cur].size(); ++i) {
            if(graph[cur][i] == 1 && visited[i] == 0) {
                visited[i] = visited[cur] + 1;
                q.push(i);
            }
        }
    }
    
    answer = visited[end] - 1;
    
    return answer;
}