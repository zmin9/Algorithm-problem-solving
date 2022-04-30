# python3에서 시간초과의 경우 대부분 입력 값이 많은 경우.. ㅠㅠ 
# (이 문제의 경우 최대 N이 1000, 최대 M은 (1000)x(999)/2 이므로 입력값이 거의 50만개!!)
# 여러줄을 입력 받을 때는 input 대신 sys.stdin.readline을 쓰면 입력 받는 부분에서 시간이 줄어들 수 있음

# RecursionError
# python의 기본 재귀 깊이: 1000 -> 늘려줌 (삼성 코테에서는 sys 라이브러리 사용 불가)
import sys
sys.setrecursionlimit(100000)

# 방향 없는 그래프가 주어졌을 때, 연결 요소(connected component)의 개수를 구하여라

# 정점의 개수 N (1 <= N <= 1,000), 
# 간선의 개수 M (0 <= M <= Nx(N-1)/2)  (N개의 점을 모두 연결하면 Nx(N-1)/2 개의 간선이 필요)
# N, M = map(int, input().split())
N, M = map(int, sys.stdin.readline().split())

# 그래프
graph = [[] for _ in range(N+1)]    # 1~N 사용

# 간선 입력 받음
for _ in range(M):
    u, v = map(int, sys.stdin.readline().split())   # sys.stdin.readline()으로 수정 후 python3로도 통과
    # u, v = map(int, input().split())      # python3 -> 시간초과, pypy3 -> 통과
    graph[u].append(v)
    graph[v].append(u)
#print("graph:",graph)

# 방문 여부 체크
visited = [False] * (N+1)

# DFS 사용해서 방문,
def dfs(graph, v, visited):
    # 현재 노드 v 방문 처리
    visited[v] = True
#    print(v)
    for node in graph[v]:
        if visited[node] == False:
            dfs(graph, node, visited)

# 연결 요소의 개수
CC = 0

for node in range(1, N+1):  # 1 ~ N 번 노드
    if visited[node] == False:
        #print("node:", node)
        CC += 1
        dfs(graph, node, visited)

#print("CC:", CC)
print(CC)