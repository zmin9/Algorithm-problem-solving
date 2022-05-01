import sys
sys.setrecursionlimit(100000)

# N x N 그리드에 RGB가 칠해져 있음
N = int(input())

grid = [] * N
for i in range(N):
    line = input()
    row = []
    for j in range(N):
        row.append(line[j])
    grid.append(row)

visited = [[False]*N for _ in range(N)]


def dfs(grid, visited, color, v):
    x = v[0]; y = v[1]
    visited[y][x] = True

    for dir in ([0, 1], [0, -1], [1, 0], [-1, 0]):
        next_x = x + dir[0]; next_y = y + dir[1]
        # 범위 내 인가? 방문한 적이 있는가? 같은 색인가?
        if 0 <= next_x < N and 0 <= next_y < N and visited[next_y][next_x]==False and grid[next_y][next_x]==color:
            dfs(grid, visited, color, [next_x, next_y])


# 정상인
ans1 = 0
for i in range(0, N):  # X
    for j in range(0, N):  # y
        if visited[j][i]==False:
            dfs(grid, visited, grid[j][i], [i, j])            
            ans1 +=1



# 방문 기록 초기화
visited = [[False]*N for _ in range(N)]

# 적록색약 (R->G)
for i in range(N):
    for j in range(N):
        if grid[i][j]=='R': grid[i][j]='G'  # 모든 R을 G로 변환

ans2 = 0
for i in range(N):  # X
    for j in range(N):  # y
        if visited[j][i]==False:
            ans2 +=1
            dfs(grid, visited,grid[j][i], [i, j])

print(ans1, ans2)