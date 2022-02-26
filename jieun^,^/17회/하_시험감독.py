# 백준 13458번

import math

def solution():
    N = int(input())    # N개의 시험장
    
    A = [0]*(N+1)       # A[n] - n+1번째 시험장의 사람 수
    A = input().split()
    for i in range(N):
        A[i] = int(A[i])

    B, C = input().split()
    B = int(B)
    C = int(C)
    # B: 총감독관이 한 시험장에서 감시할 수 있는 응시자의 수 (각 시험장에 총감독관은 1명)
    # C: 부감독관이 한 시험장에서 감시할 수 있는 응시자의 수

    sum = 0

    for i in range(N):
        A[i] -= B   # 총감독관
        sum += 1
        
        if A[i] > 0:    # 아직 감독할 응시자가 남음
            sum += math.ceil(A[i]/C)

    print(sum)

solution()