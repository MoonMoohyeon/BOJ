#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;
unordered_map<string, int> name_to_idx;
unordered_map<int, string> idx_to_name;
queue<int> q;
vector<int> graph[1001];
int indegree[1001];
vector<string> root;
vector<string> children[1001];
int N, M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    vector<string> names(N);
    for (int i = 0; i < N; i++) {
        cin >> names[i];
    }
    sort(names.begin(), names.end());

    for (int i = 0; i < N; i++) {
        name_to_idx[names[i]] = i;
        idx_to_name[i] = names[i];
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        string parent, child;
        cin >> child >> parent;
        int pidx = name_to_idx[parent];
        int cidx = name_to_idx[child];

        graph[pidx].push_back(cidx);
        indegree[cidx]++;
    }

    for (int i = 0; i < N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            root.push_back(idx_to_name[i]);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto i = graph[cur].begin(); i != graph[cur].end(); i++) {
            if (--indegree[*i] == 0) {
                q.push(*i);
                children[cur].push_back(idx_to_name[*i]);
            }
        }
    }

    cout << root.size() << "\n";
    vector<string> s;
    sort(root.begin(), root.end());
    for (auto i = root.begin(); i != root.end(); i++) {
        cout << *i << " ";
    }
    cout << "\n";
    
    for (int i = 0; i < N; i++) {
        sort(children[i].begin(), children[i].end());
        cout << idx_to_name[i] << " " << children[i].size() << " ";
        for (int j = 0; j < children[i].size(); j++) {
            cout << children[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}