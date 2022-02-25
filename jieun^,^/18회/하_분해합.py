# 백준 2231번

import math

def solution():
    N = int(input())

    res = 0
    for i in range(N):  # i: 0~N-1
        bun = i
        sum = i

        # 1_000_000 = 10^6  # 근데 생성자는 10^6 보다는 무조건. 작음
        for j in range(6):    # 0~5
            n = i // math.pow(10,5-j)   #
            sum += n
            i -= n * math.pow(10,5-j)
        
        if sum == N:
            res = bun
            break
    return res

print(solution())