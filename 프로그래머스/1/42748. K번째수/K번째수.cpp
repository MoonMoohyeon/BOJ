#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;
    
    for(auto it = commands.begin(); it != commands.end(); ++it) {
       // printf("%d", (*it)[0]);
        int i = (*it)[0];
        int j = (*it)[1];
        int k = (*it)[2];
        
        printf("ijk = %d %d %d\n", i, j, k);
        
        for(int t=i; t<=j; ++t) {
            temp.push_back(array[t - 1]);
        }
        
        sort(temp.begin(), temp.end());
        for(int i=0; i<temp.size(); ++i) {
            printf("%d ", temp[i]);
        }
        answer.push_back(temp[k - 1]);
        printf("k = %d\n", temp[k - 1]);
        
        temp.clear();
    }
    
    return answer;
}