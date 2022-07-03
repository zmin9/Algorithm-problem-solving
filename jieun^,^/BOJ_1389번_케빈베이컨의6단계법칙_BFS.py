import sys

def solution():
    N, M = map(int, input().split())

    # graph[A]: A와 다른 친구까지의 거리
    graph = [[sys.maxsize] * N for _ in range(N)]  # 친구 번호 0 ~ N-1

    # 자기 자신과의 거리는 0
    for n in range(N):
        graph[n][n] = 0 

    # 직접 연관이 있는 친구 관계
    for m in range(M):
        A, B = map(int, sys.stdin.readline().split())
        graph[A-1][B-1] = 1
        graph[B-1][A-1] = 1

    # 플로이드 - 워셜 알고리즘
    for k in range(N):
        for a in range(N):
            for b in range(N):
                graph[a][b] = min(graph[a][b], graph[a][k]+graph[k][b])

    members = []
    for n in range(N):
        members.append(sum(graph[n]))
    
    tmp = min(members)
    ans = members.index(tmp) + 1
    return ans


print(solution())
