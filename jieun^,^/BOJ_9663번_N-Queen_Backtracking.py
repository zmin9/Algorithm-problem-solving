N = int(input())    # 1 <= N < 15

# N개의 행에 대한 배열
row = [-1] * N  # 아직 해당 행에 퀸이 없으면 -1 / 퀸이 존재하면 열의 인덱스

global ans;
ans = 0

def check(x, y):
    if row[x] != -1: return False        # 행 체크
    if y in row: return False       # 열 체크
    for i in range(x):  # 0~x-1
        if abs(i-x) == abs(row[i]-y): return False    # 대각선 체크
    return True

def Backtrack(i, j):    # i번째 행, j번째 열에 퀸 배치
    row[i] = j

    if i==N-1:          # 마지막 행을 채웠음
        global ans;
        ans += 1
        return

    for k in range(N):  # 이번 행에 어떤 값이 들어가야 할지 탐색
        if check(i+1, k):
            Backtrack(i+1, k)
            row[i+1] = -1   # Back


for n in range(N):
    Backtrack(0, n)     # 0번째 행에 n번째 열에 첫 퀸 배치

print(ans)

# Python3에서는 시간초과!!!
# PyPy3에서는 통과!!