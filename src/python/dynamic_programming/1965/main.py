# Date : 2017.11.12
# Author : seungyeon choi
# 1965 (상자넣기)

N = int(input())
S = list(map(int, input().split()))
D = [0 for _ in range(N)]
for i in range(N):
    D[i] = 1
    for j in range(i):
        if S[i] > S[j] and D[i] < D[j] + 1 :
            D[i] = D[j] + 1
print (max(D))
