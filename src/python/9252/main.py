# Date : 2017.11.4
# Author : seungyeon choi
# 9252 (LCS2)

s1 = input()
s2 = input()
l_s1 = len(s1)
l_s2 = len(s2)
LCS = [[0]*(l_s2+1) for i in range(l_s1+1)]

for i in range(1, l_s1+1) :
    for j in range(1, l_s2+1) :
        if s1[i-1] != s2[j-1]:
            LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1])
        else :
            LCS[i][j] = LCS[i-1][j-1] + 1

print(LCS[l_s1][l_s2])

ans = []
i, j = l_s1, l_s2
while LCS[i][j] != 0 :
    if LCS[i][j] == LCS[i-1][j]: i -= 1
    elif LCS[i][j] == LCS[i][j-1]: j -= 1
    elif (LCS[i][j]-1) == LCS[i-1][j-1]:
        ans.insert(0, s1[i-1])
        i -= 1
        j -= 1

print ("".join(ans))
