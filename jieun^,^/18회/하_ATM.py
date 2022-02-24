# 백준 11399번

def solution():
    N = int(input())
    P = [0]*(N+1)   # 0~N-1 (P[n]: n+1번째 사람이 돈 뽑는 데에 걸리는 시간)
    P = input().split()
    
    for i in range(N):
        P[i] = int(P[i])
    P = sorted(P)

    for i in range(1,N):
        P[i] += P[i-1]

    res = sum(P)
    print(res)

solution()