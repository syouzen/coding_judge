# Date : 2017.11.8
# Author : seungyeon choi
# 1920 (수 찾기)

N = int(input())
S = list(map(int, input().split()))
S.sort()
M = int(input())
F = list(map(int, input().split()))
def bs(s, e, v):
    if s > e : 
        print(0)
        return
    mid = (s + e) // 2
    if v > S[mid] : bs(mid+1, e, v)
    elif v < S[mid] : bs(0, mid-1, v)
    elif v == S[mid] : 
        print (1)
        return     
for i in range(M):
    bs(0, N-1, F[i])
