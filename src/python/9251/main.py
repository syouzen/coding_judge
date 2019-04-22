# Date : 2017.11.5
# Author : seungyeon choi
# 9251 (LCS)

s1 = input()
s2 = input()
l1 = len(s1)
l2 = len(s2)
DP = [[0]*(l2+1) for i in range(l1+1)]

for i in range (1, l1+1):
    for j in range(1, l2+1):
        if s1[i-1] == s2[j-1]:
            DP[i][j] = DP[i-1][j-1] + 1
        else :
            DP[i][j] = max(DP[i-1][j], DP[i][j-1])

print(DP[l1][l2])
