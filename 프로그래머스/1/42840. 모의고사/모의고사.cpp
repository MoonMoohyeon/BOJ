#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int acnt, bcnt, ccnt;
    acnt = bcnt = ccnt = 0;
    int cnt = 1;
    for(auto it = answers.begin(); it != answers.end(); ++it) {
        if((cnt-1)%5+1 == *it) acnt++;
        
        if((cnt % 8 == 1 || cnt % 8 == 3 || cnt % 8 == 5 || cnt % 8 == 7) && *it == 2) bcnt++;
        if(cnt % 8 == 2 && *it == 1) bcnt++;
        if(cnt % 8 == 4 && *it == 3) bcnt++;
        if(cnt % 8 == 6 && *it == 4) bcnt++;
        if(cnt % 8 == 0 && *it == 5) bcnt++;
        
        if((cnt % 10 == 1 || cnt % 10 == 2) && *it == 3) ccnt++;
        if((cnt % 10 == 3 || cnt % 10 == 4) && *it == 1) ccnt++;
        if((cnt % 10 == 5 || cnt % 10 == 6) && *it == 2) ccnt++;
        if((cnt % 10 == 7 || cnt % 10 == 8) && *it == 4) ccnt++;
        if((cnt % 10 == 9 || cnt % 10 == 0) && *it == 5) ccnt++;
        
        cnt++;
    }
    
    if(acnt >= bcnt && acnt >= ccnt) answer.push_back(1);
    if(bcnt >= acnt && bcnt >= ccnt) answer.push_back(2);
    if(ccnt >= acnt && ccnt >= bcnt) answer.push_back(3);
    
    cout << acnt << " " << bcnt << " " << ccnt;
    sort(answer.begin(), answer.end());
    
    return answer;
}