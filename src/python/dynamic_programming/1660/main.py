# Date : 2017.11.11
# Author : seungyeon choi
# 1660 (캡틴 이다솜)

N = int(input())
tri = [0 for _ in range(151)]
tri[1] = 1
tri[2] = 4
DP = [151 for _ in range(300001)]
for i in range(3, 151):
    tri[i] = 2 * tri[i-1] + i - tri[i-2]
    if tri[i] > N:
        break
DP[0] = 0
DP[1] = 1
for i in range(1, N+1):
    for j in range(1, 151):
        if tri[j] > i :
            break
        if tri[j] <= i :
            DP[i] = min(DP[i-tri[j]] + 1, DP[i])
print (DP[N])
