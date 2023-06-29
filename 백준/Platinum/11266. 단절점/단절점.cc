#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
	Cut Vertex를 구한다.
	어떤 노드를 제거했을 때 그래프의 연결이 끊어지는 노드.

	루트의 자식 노드가 두 개 이상이면 루트가 cut vertex이다.
	DFS 한 번으로 루트가 아닌 노드들이 cut vertex인지 확인한다.

	1. DFS 트리를 만든다. 트리를 만들었을 때 트리에 들어가지 않은 엣지들은 모두 백엣지이다. 크로스엣지는 존재하지 않기 때문에.

	2. 벡엣지를 타고 올라갔을 때 어디까지 갈 수 있는가?
	어떤 노드 t에 대하여 그 아래에 존재하는 모든 백엣지의 경로를 보았을 때 t 이상으로 올라갈 수 없다면, t는 cut vertex이다. t 이하에 모두 갇히기 때문에.

	3. L(t)를 구한다. pre = 전위 순회로 붙인 번호. 작은 값은 위쪽(루트쪽)이다.
		1. pre(t) - 백엣지를 사용하지 않은 경우. 자기 자신의 값.
		2. (t, s)가 벡엣지인 경우의 min of pre(s) - level이 가장 작은(가장 높이 올라가는) 곳으로 가는 백엣지의 값.
		3. t의 모든 자식들 중 min of L(u) - t 이하에서 백엣지를 한 번 사용해서 level이 가장 작은 곳으로 가는 백엣지의 값 == 자식에게 받은 2번 값(재귀적).

	t의 자식 u에 대하여 L(u) >= pre(t)가 존재하면 == t가 cut vertex이다.
	L(u)에서 t 위쪽 노드로 가는 백엣지가 없으므로, 반드시 t를 거쳐야 한다. == t가 cut vertex이다.
	* 모든 자식에 대해 L(u) < t이면 t를 거치지 않고 연결된다. == t가 cut vertex가 아니다. t가 없어도 상관이 없으므로.
*/

int dfn;
int cnt = 0;
int Dfn[10001];
vector<int> Edge[100001];
vector<int> Type[100001]; // 간선 종류 구별 1 parent 2 child 3 back/forward
int L[10001]; // 자기 dfn, 모든 벡엣지의 dfn, 자식에게 받은 dfn 중 최소
int Cut[10001];
queue<int> q;

void dfs(int x, int p)
{
	int i, s; // s = 해당 노드에 붙은 간선의 개수
	Dfn[x] = ++dfn; // dfs로 노드에 번호를 붙임.
	s = Edge[x].size();
	for (i = 0; i < s; i++)
	{
		if (Edge[x][i] == p) // 부모 노드인 경우
		{
			Type[x][i] = 1;
		}
		else if (Dfn[Edge[x][i]] == 0) // 방문한 적 없는 노드인 경우
		{
			Type[x][i] = 2;
			dfs(Edge[x][i], x);
		}
		else // 방문한 적 있는 노드인 경우
		{
			Type[x][i] = 3;
		}
	}
}

int dfs2(int x, int p)
{
	int i, s, rv, cc;
	L[x] = Dfn[x];
	s = Edge[x].size();
	for (i = 0; i < s; i++) // L 값을 계산함.
	{
		if (Type[x][i] == 1); // 부모인 경우 생략.
		else if (Type[x][i] == 2) // 자식에게 받은 dfn
		{
			rv = dfs2(Edge[x][i], x); // 자식의 L값을 받음.
			L[x] = min(L[x], rv);
		}
		else // 모든 백엣지 중 최소
		{
			L[x] = min(L[x], Dfn[Edge[x][i]]);
		}
	}

	if (p == 0) // 루트인 경우 따로 체크함. 두 개 이상이면 루트가 cut vertex
	{
		cc = 0; // 자식의 개수
		for (i = 0; i < s; i++)
			if (Type[x][i] == 2) cc++;

		if (cc > 1)
		{
			Cut[x] = 1;
		}
	}
	else
	{
		for (i = 0; i < s; i++)
		{
			if (Type[x][i] == 2) // 자식인 경우만
			{
				if (L[Edge[x][i]] >= Dfn[x])
				{
					Cut[x] = 1;
				}
			}
		}
	}

	return L[x];
}

int main(void)
{
	int i, n, m, x, y;
	scanf("%d %d", &n, &m); // 그래프 입력
	for (i = 0; i < m; i++)
	{
		scanf(" %d %d", &x, &y);
		Edge[x].push_back(y);
		Type[x].push_back(0);
		Edge[y].push_back(x);
		Type[y].push_back(0);
	}



	dfn = 0;

	for (i = 1; i <= n; i++)
	{
		if (Dfn[i] == 0)
		{
			dfs(i, 0);
			q.push(i);
		}
	}

	while (!q.empty())
	{
		dfs2(q.front(), 0);
		q.pop();
	}

	/*for (i = 1; i <= n; i++) // 그래프의 연결 검사
	{
		if (Dfn[i] == 0) break;
	}*/

	/*if (i <= n)
	{
		printf("Disconnected Graph!\n");
		exit(1);
	}*/

	

	for (i = 1; i <= n; i++)
	{
		if (Cut[i] == 1)
			cnt++;
	}
	printf("%d\n", cnt);
	for (i = 1; i <= n; i++)
	{
		if (Cut[i] == 1)
			printf("%d ", i);
	}

	return 0;
}

/*
5 3
3 2
2 1
1 4

5 4
3 2
2 1
1 4
4 5


16 20
1 2
1 3
2 4
3 4
4 5
5 6
4 6
5 7
7 8
4 12
12 13
4 11
11 13
11 10
10 9
9 11
13 14
14 15
15 16
14 16
*/