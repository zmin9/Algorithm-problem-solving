# 백준 2580번

board = [[0]*9 for i in range(9)]
blank = []

def checkRow(x, a): # x번째 가로줄에 a가 들어갈 수 있나?
    for i in range(9):
        if a==board[x][i]: return False
    return True


def checkCol(y, a): # y번째 세로줄에 a가 들어갈 수 있나?
    for i in range(9):
        if a == board[i][y]: return False
    return True
    

def checkRect(x, y, a): # x, y가 속해있는 칸에 a가 들어갈 수 있나?
    nx = x//3 * 3
    ny = y//3 * 3
    for i in range(3):
        for j in range(3):
            if a == board[nx+i][ny+j]: return False
    return True


def dfs(idx):   #blank에서의 index
    if idx == len(blank):   # 모든 blank를 채웠으니 그만두기
        for i in range(9):
            print(*board[i])
        exit(0)

    for i in range(1, 10):  # 칸에 들어갈 수 있는 1~9
        x = blank[idx][0]
        y = blank[idx][1]
        if checkRow(x, i) and checkCol(y, i) and checkRect(x, y, i):
            board[x][y] = i
            dfs(idx+1)
            board[x][y] = 0     # 만약 갔던 길에서 되돌아올 경우 0으로 초기화


def solution():
    for i in range(9):  # board 입력받기
        board[i] = input().split()

    for i in range(9):  # blank 찾아내기
        for j in range(9):
            if board[i][j] == '0':
                blank.append((i,j))

    dfs(0)
    
solution()