# Date : 2017.11.5
# Author : seungyeon choi
# 11047 (동전0)

temp = list(map(int, input().split()))
N, V = temp[0], temp[1]
coin = [0 for i in range(N+1)]
for i in range(1, N+1):
    coin[i] = int(input())
ans = 0
while V :
    for i in range(N, 0, -1):
        if coin[i] <= V and N == i:
            ans += int(V / coin[i])
            V = (V % coin[i])
        if coin[i] <= V :
            ans += int(V / coin[i])
            V = (V % coin[i])
print(ans)
