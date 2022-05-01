from collections import deque

# N x M 크기의 미로, (1,1) --> (N,M) 이동할 때 지나야 하는 최소 칸 수
# (0, 0) --> (N-1, M-1)
N, M = map(int, input().split())    # N: 행, M: 열
miro = [] 

# 미로 입력 받기
for i in range(N):
    row = []
    row_input = input()
    for j in range(len(row_input)):
        row.append(row_input[j])
    miro.append(row)

# 해당 칸까지 가는데 걸리는 시간
ans = [[0]*M for _ in range(N)]
ans[0][0] = 1

Q = deque()
Q.append([0,0])

while Q:
    v = Q.popleft()
    x = v[0]; y = v[1]

    # 최종 칸에 도착 -> while 루프 탈출
    if x == M-1 and y == N-1 : break
    else:
        # 4 방향에 대해서
        for direction in ([0, 1], [0, -1], [1, 0], [-1, 0]):
            next_x, next_y = x+direction[0], y+direction[1]
            
            # 범위 내 인가? / 이동할 수 있는 칸인가? / 아직 방문하지 않았는가?
            if 0 <= next_x < M and 0 <= next_y < N and miro[next_y][next_x] == '1' and ans[next_y][next_x]==0:
                Q.append([next_x, next_y])        
                # 이전 칸까지 가는데에 걸리는 시간 + 1
                ans[next_y][next_x] = ans[y][x] + 1
    
print(ans[N-1][M-1])