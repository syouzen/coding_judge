# Date : 2017.11.5
# Author : seungyeon choi
# 1958 (LCS3)

s1 = input()
s2 = input()
s3 = input()
l1 = len(s1)
l2 = len(s2)
l3 = len(s3)
DP = [[[0]*(l3+1) for i in range(l2+1)] for i in range(l1+1)]

for i in range (1, l1+1):
    for j in range(1, l2+1):
        for k in range(1, l3+1):
            if s1[i-1] == s2[j-1] == s3[k-1]:
                DP[i][j][k] = DP[i-1][j-1][k-1] + 1
            else :
                DP[i][j][k] = max(DP[i-1][j][k], DP[i][j-1][k], DP[i][j][k-1])

print(DP[l1][l2][l3])
