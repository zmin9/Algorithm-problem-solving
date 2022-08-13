from collections import deque


def solution():
    N = int(input())    # 컴퓨터 개수
    M = int(input())    # 연결 쌍 수
    graph = [[] for _ in range(N)]
    for m in range(M):
        a, b = map(int, input().split())
        graph[a-1].append(b-1)
        graph[b-1].append(a-1)
    
    Q = deque()
    for g in graph[0]:  # 1번 컴퓨터가 웜 바이러스에 걸렸을 때
        Q.append(g)

    visited = []
    while Q:
        com = Q.popleft()
        visited.append(com)

        for c in graph[com]:
            if c not in visited:
                Q.append(c)

    visited = set(visited)
    print(len(visited)-1)

solution()        
