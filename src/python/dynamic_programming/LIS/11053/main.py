# Date : 2017.11.13
# Author : seungyeon choi
# 11053 (가장 긴 증가하는 부분 수열 - LCS)

N = int(input())
S = list(map(int, input().split()))
DP = []
DP.append(S[0])
for i in range(1, N):
    if S[i] > DP[len(DP)-1] :
        DP.append(S[i])
    else :
        def BS(a, b, v):
            while a < b :
                mid = (a + b) // 2
                if DP[mid] >= v : b = mid
                else : a = mid + 1
            return b
        DP[BS(0, len(DP)-1, S[i])] = S[i]
print (len(DP))
