#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int w, h, idw, idh;
    idw = idh = h = w = 0;
    for(int i=0; i<sizes.size(); i++) {
        if(sizes[i][1] > h) {
            h = sizes[i][1];
            idh = i;
        }
        if(sizes[i][0] > w) {
            w = sizes[i][0];
            idw = i;
        }
    }
    
    /*
        h = 높이 최대, w = 너비 최대
        높이와 너비 중 더 큰 값은 반드시 필요함.
        
        반대쪽 길이는 비교가 필요함.
        최대 높이가 정해지면, 남은 항목들에 대해서
        그대로 넣었을 때와 회전해서 넣었을 때를 고려해야 함.
        
        그대로 또는 회전했을 때 들어가는 경우 h< w<에는 넘어감.
        들어가지 않는 경우, 둘 중 작은 값이 반대쪽 피연산자가 된다.
        
        그대로 넣었을 때 비교
        sizes[idh][0] < sizes[i][0] && sizes[idh][1] < sizes[i][1];
        회전했을 때
        sizes[idh][0] < sizes[i][1] && sizes[idh][1] < sizes[i][0];
    */
    
    int maxv, secondv;
    maxv = secondv = 0;
    
    maxv = h>w?h:w;
    
    if(maxv == h) {
        for(int i=0; i<sizes.size(); i++) {
            if(sizes[idh][0] < sizes[i][0] && sizes[idh][1] < sizes[i][1] && sizes[idh][0] < sizes[i][1] && sizes[idh][1] < sizes[i][0]) {
                continue;
            }
            else {
                if(secondv < min(sizes[i][0], sizes[i][1])) {
                    secondv = min(sizes[i][0], sizes[i][1]);
                }
            }
        }
    }
    else {
        for(int i=0; i<sizes.size(); i++) {
            if(sizes[idw][0] < sizes[i][0] && sizes[idw][1] < sizes[i][1] && sizes[idw][0] < sizes[i][1] && sizes[idw][1] < sizes[i][0]) {
                continue;
            }
            else {
                if(secondv < min(sizes[i][0], sizes[i][1])) {
                    secondv = min(sizes[i][0], sizes[i][1]);
                }
            }
        }
    }
    
    
    cout << maxv << " " << secondv << "\n";
    
    answer = maxv * secondv;
    return answer;
}