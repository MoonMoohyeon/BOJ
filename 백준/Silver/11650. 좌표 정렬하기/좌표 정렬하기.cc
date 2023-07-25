#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

vector<pair<int, int>> v;

int main(void)
{
    int N;
    int x, y;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &x, &y);
        v.push_back({ x, y });
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++)
    {
        printf("%d %d\n", v[i].first, v[i].second);
    }

    return 0;
}
