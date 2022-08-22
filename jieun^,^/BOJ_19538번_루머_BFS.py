from collections import deque
import math

def solution():
    # 사람의 수
    N = int(input())

    graph = [[]]
    # 주변인 관계
    for n in range(1, N+1): # 1 ~ N 번 사람 (0번째는 비워둠)
        relation = (list(map(int, input().split())))
        relation.pop()
        graph.append(relation)

    # 최초 유포자의 수
    M = int(input())

    # 최초 유포자
    first = list(map(int, input().split()))

    turn = [0]*(N+1)  # 주변 인들
    for g in range(1, N+1):
        turn[g] = math.ceil(len(graph[g])/2)


    ans = [-1]*(N+1)    # 안 믿는 사람은 -1로 초기화
    Q = deque()
    for f in first:
        Q.append(f) # 루머를 믿고 있는 사람을 큐에 넣음
        ans[f]=0    # 최초 유포자의 루머 믿기 시작한 시간은 0분
    
    while Q:
        # 믿고 있는 사람을 꺼내기
        rumor = Q.popleft()

        # 주변인에게 전파
        for g in graph[rumor]:
            turn[g]-=1

            if ans[g]==-1 and turn[g]<=0:
                ans[g]=ans[rumor]+1
                Q.append(g)

    ans = ans[1:]
    ansString=""
    for a in ans:
        ansString += str(a) + " "
    
    print(ansString)

solution()
