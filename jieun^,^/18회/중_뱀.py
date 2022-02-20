# 백준 3190번

def solution():
    N = int(input())  # 보드의 크기 N x N
    K = int(input())  # 사과의 개수 K

    # 보드판 생성 (1 ~ N) x (1 ~ N)
    board = [[0]*(N+1) for i in range(N+1)]   # 0 ~ N+1 (인덱스 1부터 사용 예정) (0번째는 비워두기)
    
    # 사과 위치 입력받기
    for i in range(K):
        y, x = input().split()
        y = int(y)          # 행
        x = int(x)          # 열
        board[y][x] = 1     # 사과의 존재는 1로 표시

    L = int(input())    # 방향 전환 횟수 L
    direction_change = []   # 방향 전환 리스트 (시간순)
    for i in range(L):
        X, C = input().split()  # X초 후 방향 전환, C가 'L' -> 왼쪽으로 90도 'D' -> 오른쪽으로 90도
        X = int(X)
        direction_change.insert(len(direction_change), (X,C))

    body = [(1,1)]  # 뱀의 몸은 (1,1)에서 시작
    direction_list = ((0,1), (1,0), (0,-1), (-1,0))     # 동, 남, 서, 북
    direction = 0   # 처음 방향은 오른쪽

    sec = 0 # 0초에서 시작
    while(1):
        sec+=1  # 1초 증가

        # 해당 방향으로 1칸 전진
        # body의 맨 앞 값은 머리, 맨 뒤 값은 꼬리
        body.insert(0, (body[0][0]+direction_list[direction][0], body[0][1]+direction_list[direction][1]))
        
        # 전진한 칸이 보드에서 이탈했는지 확인
        if body[0][0]>N or body[0][0]<1 or body[0][1]>N or body[0][1]<1:    # 보드 이탈
            break   # 보드를 이탈했으므로 중단
        
        # 자신의 몸과 부딪혔는지 확인
        # body 리스트에 중복값이 있는지 확인
        if len(body) != len(set(body)):   # 중복 요소를 제거하는 set의 특성을 활용
            break   # 자신의 몸과 부딪힘
        

        # 전진한 칸에 사과가 존재하는지 확인
        if board [body[0][0]] [body[0][1] ] == 0:  # 사과 X
            body.pop()  # 꼬리를 pop
        # 사과가 있으면 꼬리가 해당 칸에 그대로 존재
        else: board [body[0][0]] [body[0][1] ] = 0 # 사과 먹었으니깐 보드에서의 값을 0으로 바꿈
        
        
        # 현재 초가 방향 전환해야할 초인지 확인
        if len(direction_change) ==0 : pass     # 더이상 방향 전환 필요 x
        # 아직 방향 전환할 일 남아있음
        elif sec == direction_change[0][0]:   # 리스트의 가장 앞이 다가올 제일 가까운 시간
            if direction_change[0][1] == 'L':   # 왼쪽으로 90도
                direction -= 1
                if direction<0: # 동에서 90도 왼쪽 -> 북
                    direction = 3
            elif direction_change[0][1] == 'D': # 오른쪽으로 90도
                direction += 1
                if direction > 3:   # 북에서 90도 오른쪽 ->동
                    direction = 0
            direction_change.pop(0) # 방향전환 수행했으므로 삭제

    return sec


print(solution())