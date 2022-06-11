import sys
sys.setrecursionlimit(100000)


def DFS(x, y, visited):
    # 방문 처리
    visited[y][x] = True
    #print("y, x:", y, x)

    dir = [(0, 1), (0, -1), (1, 0), (-1, 0)]    # 상하좌우
    for d in dir:
        next_x=x+d[0]; next_y=y+d[1]
        if 0<=next_x<M and 0<=next_y<N:
            if visited[next_y][next_x]==False:
                if board[next_y][next_x]==1:
                    DFS(next_x, next_y, visited)

T = int(input())    # Testcase
for t in range(T):
    
    ## 입력 받기 ##
    M, N, K = map(int, input().split()) # M: 가로길이, N: 세로길이, K: 배추 개수
    board = [[0]*M for _ in range(N)]   # N x M
    for k in range(K):
        x, y = map(int, input().split())
        board[y][x] = 1

    visited = [[False]*M for _ in range(N)] 
    ans = 0
    for i in range(M):
        for j in range(N):
            if visited[j][i]==False and board[j][i]==1:
                ans += 1
                DFS(i, j, visited)
    
    print(ans)
    