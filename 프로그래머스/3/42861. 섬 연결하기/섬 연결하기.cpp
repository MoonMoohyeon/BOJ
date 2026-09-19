#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>

using namespace std;

int parent[101];
int rk[101];

int search(int a) {
    if(parent[a] == a) return a;
    
    return parent[a] = search(parent[a]);
}

int isunion(int a, int b) {
    if(search(a) == search(b)) return 1;
    return 0;
}

int merge(int a, int b) {
    int roota = search(a);
    int rootb = search(b);
    
    if(!isunion(roota, rootb)) {
        if(rk[roota] < rk[rootb]) {
            swap(roota, rootb);
        }
        
        parent[rootb] = roota;
        
        if(rk[roota] == rk[rootb]) {
            rk[a]++;
        }
        return 1;
    }
    
    return 0;
}

struct cmp {
    bool operator() (const vector<int>& a, const vector<int>& b) const {
        return a[2] < b[2];
    }
};

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for(int i=1; i<=100; ++i) {
        parent[i] = i;
        rk[i] = 1;
    }
    
    sort(costs.begin(), costs.end(), cmp());
    int cnt = 0;
    for(int i=0; i<costs.size(); ++i) {
        int first = costs[i][0];
        int second = costs[i][1];
        int cost = costs[i][2];
        
        if(merge(first, second)) {
            answer += cost;
            cnt++;
        }
        
        if(cnt == n - 1) break;
    }
    
    return answer;
}