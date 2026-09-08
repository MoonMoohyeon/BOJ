#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i=0; i<scoville.size(); ++i) {
        pq.push(scoville[i]);
    }
    
    while(1) {
        if(pq.empty()) return -1;
        int first = pq.top();
        // printf("%d\n", first);
        if(first >= K) break;
        pq.pop();
        if(pq.empty()) return -1;
        int second = pq.top();
        pq.pop();
        // printf("f = %d s = %d\n", first, second);
        
        int sum = first + second * 2;
        pq.push(sum);
        // printf("sum = %d\n", sum);
        answer++;
    }
    
    return answer;
}