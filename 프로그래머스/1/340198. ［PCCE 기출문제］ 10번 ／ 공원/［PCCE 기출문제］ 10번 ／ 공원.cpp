#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int checkbound(int i, int j, vector<vector<string>>& park) {
    if(i < 0 || j < 0 || i >= park.size() || j >= park[i].size()) return 0;
    return 1;
}

int search(int y, int x, int mat, vector<vector<string>>& park) {
    for(int i = y; i < y + mat; i++) {
        for(int j = x; j < x + mat; j++) {
            if(!checkbound(i,j,park)) return -1;
            if(park[i][j] != "-1") return -1;
        }
    }
    
    return mat;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    
    sort(mats.rbegin(), mats.rend());
    for(int k=0; k<mats.size(); k++) {
        for(int i=0; i<park.size(); i++) {
            for(int j=0; j<park[i].size(); j++) {
                if(checkbound(i,j,park) && park[i][j] == "-1") {
                    answer = search(i, j, mats[k], park);
                    if(answer > 0) return answer;
                }
            }
        }
    }
    
    return -1;
}