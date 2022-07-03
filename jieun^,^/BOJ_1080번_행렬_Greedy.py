def reverse(pos, A):    # 3x3 부분행렬 전체를 뒤집기
    n, m = pos
    for i in range(3):  # +0 +1 +2
        for j in range(3):  # +0 +1 +2
            if A[n+i][m+j]== '1' : A[n+i][m+j]= '0'
            else: A[n+i][m+j]= '1'


def solution():
    N, M = map(int, input().split())    # N, M <= 50 자연수

    # N x M 행렬 A -> B
    A = []; B = []
    for _ in range(N):
        A.append(list(input()))
    for _ in range(N):
        B.append(list(input()))

    ans = 0

    # 주어진 행렬이 3x3보다 작은 경우
    if N < 3 or M < 3: 
        if A==B:    # 뒤집지 않아도 A 행렬 = B 행렬
            ans = 0
        else: ans = -1  # 뒤집지 못하는데 A 행렬 != B 행렬
        return ans

    # (i, j) -> 3x3 단위의 왼쪽 위의 위치   ->  당장의 (i, j)만 생각하기 (그리디)
    # 행렬 전체를 3x3 필터로 1번씩 탐색
    for i in range(N-2):
        for j in range(M-2):
            if A[i][j] != B[i][j]:  
                pos = (i, j)    # i: 행 / j: 열
                reverse(pos, A)
                ans += 1

    if A != B: ans=-1

    return ans
    
print(solution())
