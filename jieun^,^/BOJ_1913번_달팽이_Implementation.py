N = int(input())    # 1 ~ N^2까지의 자연수를 달팽이 모양으로 N x N 표 채우기
board = [[0]*N for _ in range(N)]

num = int(input())  # 1 <= num <= N^2, 표에서의 좌표를 출력 (행, 열)

pos = (N//2, N//2)  # 정답 출력할 때, +1씩 해주기 (배열 좌표+1 => 문제 좌표)
num_ans = pos    # board 채울 때, num을 찾으면 정답 채워넣기

board[pos[0]][pos[1]] = 1

# pos = (x, y) -> board[x][y] (행, 열)

n = 1
unit = 1   # 행, 열 몇씩 이동하는지 단위 (홀수: 행-,열+ / 짝수: 행+,열-)
break_flag=0
while 1:   # 1 ~ N

    # unit만큼 행 이동 (unit이 홀수 -> -, 짝수 -> +)
    for i in range(unit):
        n += 1

        if n > N**2: 
            break_flag=1
            break

        if unit%2==0:   # 짝수
            pos = (pos[0]+1, pos[1])
            if n==num:
                num_ans=pos
        else:           # 홀수
            pos = (pos[0]-1, pos[1])
            if n==num:
                num_ans=pos

        board[pos[0]][pos[1]] = n
              
    if break_flag==1: break

    # unit만큼 열 이동 (unit이 홀수 -> +, 짝수 -> -)
    for i in range(unit):
        n += 1

        if unit%2==0:   # 짝수
            pos = (pos[0], pos[1]-1)
            if n==num:
                num_ans=pos            
        else:           # 홀수
            pos = (pos[0], pos[1]+1)
            if n==num:
                num_ans=pos            

        board[pos[0]][pos[1]] = n
        

    unit += 1


for i in range(N):
    line = ""
    for j in range(N):
        line += str(board[i][j]) + " "
    print(line)

print(num_ans[0]+1, num_ans[1]+1)
