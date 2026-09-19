#include <string>
#include <vector>
#include <iostream>

using namespace std;

int DP[501][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int siz = triangle.size();
    
    for(int i=0; i<siz; ++i) {
        DP[siz - 1][i] = triangle[siz - 1][i]; // 맨 아래층
    }
    
    for(int i=siz - 2; i>=0; --i) {
        for(int j=0; j <= i; ++j) {
            DP[i][j] = triangle[i][j] + max(DP[i + 1][j], DP[i + 1][j + 1]);
            // cout << triangle[i][j] << " " << DP[i + 1][j] << " " << DP[i + 1][j + 1] << " ";
        }
        // cout << "\n";
    }
    
//     for(int i=0; i<siz; ++i) {
//         for(int j=0; j<=i; ++j) {
//             cout << DP[i][j] << " ";
//         }
//         cout << "\n";
//     }
    
    answer = DP[0][0];
    
    return answer;
}