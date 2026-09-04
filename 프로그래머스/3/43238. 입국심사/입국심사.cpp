#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    int size = times.size();
    long long minv = 0;
    sort(times.begin(), times.end());
    long long maxv = times[size - 1];
    
    long long low = minv;
    long long high = maxv * n;
    long long cnt = 0;
    
    //printf("%d %d %d", low, high, size);
    while(low <= high) {
        long long mid = (low + high) / 2;
        cnt = 0;
        
        for(int i=0; i<size; ++i) {
            cnt += mid / times[i];
            
            if(cnt >= n) break;
        }
        
        if(cnt >= n) {
            answer = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    
    return answer;
}