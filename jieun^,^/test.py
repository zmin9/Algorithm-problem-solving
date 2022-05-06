N, M, start=map(int,input().split())   # N: 정점의 개수, M: 간선의 개수
# 정점 번호: 1~N

graph=[[] for _ in range(N+1)]   # 정점의 번호가 1부터 시작하기 때문에 N+1까지 필요

for i in range(M):
    a, b=map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)

for i in range(N+1):
    graph[i].sort()

visited=[False]*(N+1)

def dfs(graph,v,visited):
    # 현재 노드 방문 처리
    visited[v]=True
    print(v, end=' ')

    # 인접 노드 방문
    for i in graph[v]:
        if visited[i]==False:   # 아직 방문 x
            dfs(graph,i,visited)

dfs(graph,start,visited)
print()
visited=[False]*(N+1)   # bfs도 해야하니깐 방문 기록 초기화

from collections import deque

def bfs(graph,start,visited):
    # 시작 노드 큐에 넣기
    Q=deque()
    Q.append(start)
    visited[start]=True

    # 큐가 비워질 때까지
    while Q:
        v=Q.popleft()
        print(v,end=' ')
        for i in graph[v]:
            if visited[i]==False:
                Q.append(i)
                visited[i]=True

bfs(graph,start,visited)