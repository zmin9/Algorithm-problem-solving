def dfs(arr, pos, visited, N):
    global count;

    x, y = pos
    
    # 방문 처리
    visited[x][y] = True
    count += 1

    dir = [[0, 1], [0, -1], [1, 0], [-1, 0]]
    for d in dir:
        next_x = x + d[0]
        next_y = y + d[1]

        if 0 <= next_x < N and 0 <= next_y < N:     # 다음 x, y가 범위 내
            if visited[next_x][next_y]==False:      # 다음 x, y에 방문한 적 X
                if arr[next_x][next_y]=='1':        # 다음 x, y에 집이 존재

                    dfs(arr, [next_x, next_y], visited, N)


def solution(): 
    N = int(input())    # 5 <= N <= 25

    arr = [[] for _ in range(N)]
    for n in range(N):
        arr[n] = list(input())

    visited=[[False] * N for _ in range(N)]
    ans = []

    global count;
    count = 0

    for i in range(N):
        for j in range(N):
            if visited[i][j]==False and arr[i][j]=='1':
                dfs(arr, [i, j], visited, N)
                ans.append(count)
                count = 0

    ans = sorted(ans)                            
    print(len(ans))
    for a in ans:
        print(a)

solution()
