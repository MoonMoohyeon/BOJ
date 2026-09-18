#include<string>
#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;
    
    for(auto i : s) {
        cout << i;
        if(i == '(') {
            st.push(i);
        }
        else if(i == ')') {
            if(st.empty()) {
                answer = false;
                continue;
            }
            st.pop();
        }
    }
    
    if(!st.empty()) answer = false;
    
    return answer;
}