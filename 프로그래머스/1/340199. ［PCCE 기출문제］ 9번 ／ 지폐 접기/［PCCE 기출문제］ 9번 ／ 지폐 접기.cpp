#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    int minbill, minwallet, maxbill, maxwallet;
        
    if(bill[0] < bill[1]) {
        minbill = bill[0];
        maxbill = bill[1];
    }
    else {
        minbill = bill[1];
        maxbill = bill[0];
    }
    if(wallet[0] < wallet[1]) {
        minwallet = wallet[0];
        maxwallet = wallet[1];
    }
    else {
        minwallet = wallet[1];
        maxwallet = wallet[0];
    } 
    
    while(minbill > minwallet || maxbill > maxwallet) {
        maxbill /= 2;
        if(maxbill < minbill) swap(minbill, maxbill);
        answer++;
    }

    return answer;
}