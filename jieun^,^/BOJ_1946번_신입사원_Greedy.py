import sys

T = int(input())    # 1 <= T <= 20

for t in range(T):
    N = int(input())    # 지원자의 수 1 <= N <= 100,000
    
    recruits = []
    for n in range(N):
        A, B = map(int, sys.stdin.readline().split())
        recruits.append([A, B])

    recruits.sort(key=lambda x:x[0])   

     # 서류 순위 순서대로 면접 순위를 비교
     # 서류 순위 순서대로 탐색할 때, 면접 순위가 이전 사람보다 높아야만 함
     # 탐색하다가 비교 기준 rank를 면접 순위가 더 높은 순위로 바꾸기

    ans = N
    rank = recruits[0][1]   # 서류 1

    for n in range(1, N):
        if rank < recruits[n][1]:   # 서류 & 면접 순위가 다 낮음
            ans -= 1    # 안 뽑음
        else:
            rank = recruits[n][1]   # 면접 순위가 이전보다 더 높음 -> 비교 기준 rank를 바꿈
        
    print(ans)
