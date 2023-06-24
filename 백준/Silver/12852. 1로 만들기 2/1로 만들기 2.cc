#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int DP[1000001];

queue<int> q;

int main(void)
{
    int N;
    scanf("%d", &N);
    int DPvalue = N;
    int pushvalue = N;
    DP[0] = 0;
    DP[1] = 0;
    DP[2] = 1;
    DP[3] = 1;
    DP[4] = 2;
    DP[5] = 3;

    for (int i = 6; i <= N; i++)
    {
        if (i % 3 == 0 && i % 2 == 0)
        {
            DP[i] = min({ DP[i / 3], DP[i / 2], DP[i - 1] }) + 1;
        }
        else if (i % 3 == 0)
        {
            DP[i] = min({ DP[i / 3], DP[i - 1] }) + 1;
        }
        else if (i % 2 == 0)
        {
            DP[i] = min(DP[i / 2], DP[i - 1]) + 1;
        }
        else
        {
            DP[i] = DP[i - 1] + 1;
        }
    }

    q.push(DPvalue);
    while (DPvalue > 1)
    {
        if (DPvalue % 3 == 0 && DPvalue % 2 == 0)
        {
            DPvalue = min({ DP[DPvalue / 3], DP[DPvalue / 2], DP[DPvalue - 1] });
            if (DPvalue == DP[pushvalue / 3])
            {
                pushvalue = pushvalue / 3;
                DPvalue = pushvalue;
                q.push(pushvalue);
            }
            else if (DPvalue == DP[pushvalue / 2])
            {   
                pushvalue = pushvalue / 2;
                DPvalue = pushvalue;
                q.push(pushvalue);
            }
            else
            {
                pushvalue = pushvalue - 1;
                DPvalue = pushvalue;
                q.push(pushvalue);
            }
        }
        else if (DPvalue % 3 == 0)
        {
            DPvalue = min({ DP[DPvalue / 3], DP[DPvalue - 1] });
            if (DPvalue == DP[pushvalue / 3])
            {
                pushvalue = pushvalue / 3;
                DPvalue = pushvalue;
                q.push(pushvalue);
            }
            else
            {
                pushvalue = pushvalue - 1;
                DPvalue = pushvalue;
                q.push(pushvalue);
            }
        }
        else if (DPvalue % 2 == 0)
        {
            DPvalue = min(DP[DPvalue / 2], DP[DPvalue - 1]);
            if (DPvalue == DP[pushvalue / 2])
            {
                pushvalue = pushvalue / 2;
                DPvalue = pushvalue;
                q.push(pushvalue);
            }
            else
            {
                pushvalue = pushvalue - 1;
                DPvalue = pushvalue;
                q.push(pushvalue);
            }
        }
        else
        {
            pushvalue = pushvalue - 1;
            DPvalue = pushvalue;
            q.push(pushvalue);
        }
    }

    printf("%d\n", DP[N]);
    while (!q.empty())
    {
        printf("%d ", q.front());
        q.pop();
    }

    return 0;
}
