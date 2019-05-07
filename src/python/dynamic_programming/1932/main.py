# Date : 2017.11.7
# Author : seungyeon choi
# 1932 (정수 삼각형)

N = int(input())
DP = [[0]*(N+2) for _ in range(N+2)]
T = [[0]*(N+1) for _ in range(N+1)]
for i in range(1, N+1):
    temp = input()
    if len(temp) <= 1 : T[i][1] = int(temp)
    else :
        temp_list = temp.split()
        for j in range(1, len(temp_list)+1):
            T[i][j] = int(temp_list[j-1])

for i in range(N, 0, -1):
    for j in range(N, 0, -1):
        DP[i][j] = max(T[i][j]+DP[i+1][j], T[i][j]+DP[i+1][j+1])

print (DP[1][1])
