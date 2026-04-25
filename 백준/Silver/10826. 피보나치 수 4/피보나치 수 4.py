n = int(input())
DP = [0] * 10001
DP[0] = 0
DP[1] = 1
DP[2] = 1
DP[3] = 2;
for i in range(4, n+1):
    DP[i] = DP[i-1] + DP[i-2]

print(DP[n])
