# 백준 2210번

# 그래프 이론, 브루트포스, 그래프 탐색, DFS, 백트래킹

# DFS - 노드 스택에 삽입, 방문처리 / 스택의 최상단 노드에 방문x인 인접 노드 O -> 그 노드 스택에 넣고, 방문처리 / 스택의 최상단 노드에 방문x인 인접 노드 X -> 스택의 최상단 노드 POP

# DFS의 시작 노드를 25개 노드 모두 다 해보기
# 중복 값은 set으로 제거 -> '서로 다른' 여섯 자리의 수의 개수 구하기
# 이게 DFS 인가..? 그냥 브루트포스인 거 같은데...

ans = set()
way = [(1,0),(-1,0),(0,1),(0,-1)]   # ▽ △ ▷ ◁
board = [[-1]*5 for i in range(5)]  # (0 ~ 4) x (0 ~ 4)

def dfs(pos, res):
    if len(res)==6: ans.add(res); return 0  # 이미 6자리면, 끝

    # pos에 따라서 가지 못하는 방향
    exc = []    
    if pos[0]<=0:   # 위로는 못 감
        exc.append(1)
    if pos[0]>=4: # 아래로는 못 감   
        exc.append(0)
    if pos[1]<=0:   # 왼쪽으로는 못 감
        exc.append(3)
    if pos[1]>=4: # 오른쪽으로는 못 감
        exc.append(2)

    for i in range(4):
        if i in exc:
            pass
        else:
            dfs((pos[0]+way[i][0], pos[1]+way[i][1]), res+board[pos[0]+way[i][0]][pos[1]+way[i][1]])


def solution():
    for i in range(5):                  # 보드판의 숫자 입력 받기
        board[i]=input().split()

    for i in range(5):
        for j in range(5):
            dfs((i,j), board[i][j])

    return len(ans)

    
print(solution())