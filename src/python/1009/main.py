# Date : 2017.12.4
# Author : seungyeon choi
# 1009 (분산처리)

import sys
for _ in range(int(sys.stdin.readline())):
    A, B = map(int, sys.stdin.readline().split())
    ans = A%10
    p = 4 if B%4 == 0 else B%4
    print (10 if ans == 0 else (ans**p)%10)
