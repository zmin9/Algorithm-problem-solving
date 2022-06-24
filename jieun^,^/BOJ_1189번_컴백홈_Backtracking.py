# ....
# .T..
# ....
# 왼쪽 아래 -> 오른쪽 위
# 갈 수 있는 모든 방법을 구한 후, 거리가 K인 방법만 카운트

def backtrack(pos, visited):
    global R, C, K;
    global ans;
    global board;

    # 방문 처리
    r, c = pos
    visited.append((r, c))
    
    # 종료 조건 (목적지에 도착)
    if r==0 and c==C-1:
        if len(visited) == K: 
            ans += 1
        return

    # 갈 수 있는 방향
    dir = [(0,1), (0,-1), (1,0), (-1,0)]
    for d in dir:
        # 이동할 좌표
        next_r = r + d[0]; next_c = c + d[1]
        # 1) 범위에 맞는지 확인
        if 0 <= next_r < R and 0 <= next_c < C:
            # 2) 갈 수 있는지 확인 (T는 안 됨)
            if board[next_r][next_c] == '.':
                # 3) 아직 방문한 적 X
                if (next_r, next_c) not in visited:
                    backtrack((next_r, next_c), visited)
                    visited.remove((next_r, next_c))    # 되돌리기 (back)


def solution():
    global R, C, K
    R, C, K = map(int, input().split())     # R(행) x C(열) 맵, 거리: K

    
    # 지도 입력 받기
    global board
    board = []       # . -> 갈 수 있음, T -> 갈 수 없음
    for r in range(R):
        board.append(list(input()))

    # board[R-1][0] (왼쪽 아래) -> board[0][C-1] (오른쪽 위)

    global ans  # 거리가 K인 경우의 개수
    ans = 0

    backtrack((R-1, 0), [])  # 왼쪽 아래에서 출발

    print(ans)

solution()
