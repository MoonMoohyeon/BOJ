#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string,int> map;
    
    for(auto i = participant.begin(); i!= participant.end(); ++i) {
        // cout << *i << " ";
        map[*i]++;
    }
    
    for(auto i = completion.begin(); i!= completion.end(); ++i) {
        // cout << *i << " ";
        map[*i]--;
    }
    
    for(auto& [key, val] : map) {
        // cout << key << " " << val;
        if(map[key] >= 1) {
            answer += key;
        }
    }
    
    return answer;
}