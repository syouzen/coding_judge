# Date : 2017.11.4
# Author : seungyeon choi
# 1010 (다리놓기)

N = int(input())
bridge = [0 for i in range(2)]
for i in range(N):
    bridge = list(map(int, input().split()))

    n1 = 1
    n2 = 1
    t1 = bridge[1]
    t2 = bridge[0]
    for _ in range(t2):
        n1 *= t1
        t1 -= 1

    for _ in range(t2):
        n2 *= t2
        t2 -= 1

    print (int(n1/n2))
