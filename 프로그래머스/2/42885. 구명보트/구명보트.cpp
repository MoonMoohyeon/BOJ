#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int siz = people.size();
    sort(people.begin(), people.end());
    // for(int i=0; i<siz; ++i) {
    //     cout << people[i] << " ";
    // }
    // cout << "\n";
    int first = 0;
    int last = siz - 1;
    int cnt = 0;
    
    while(1) {
        if(people[last] + people[first] <= limit) {
            // cout << "debug: "<< people[last] << " " << people[first] << " " << cnt + 2 << "\n";
            answer++;
            first++;
            last--;
            cnt += 2;
        }
        else {
            // cout << "debug: "<< people[last] << " " << people[first] << " " << cnt + 1 << "\n";
            answer++;
            last--;
            cnt++;
        }
        
        if(cnt >= siz) {
            break;
        }
    }
    
    
    return answer;
}