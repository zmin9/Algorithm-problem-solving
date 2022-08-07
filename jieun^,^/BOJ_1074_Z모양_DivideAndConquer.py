# 분할 정복 사용
# 1~4 사분면으로 쪼개가기
# 가장 작은 단위인 4칸까지 쪼개지는 것을 목표로

def solution():
    N, R, C = map(int, input().split())  # R: 행, C: 열

    ans = 0
    while N>0:  # N==0이 되면, 최소 단위가 되므로, 그만두기

        half = 2**(N-1) # 4

        # 1 사분면
        if R<half and C<half:
            pass

        # 2 사분면
        if R<half and C>=half:
            ans += 1 * (half)**2
            C -= half
        
        # 3 사분면
        if R>=half and C<half:
            ans += 2 * (half)**2
            R -= half        
        
        # 4 사분면
        if R>=half and C>=half:
            ans += 3 * (half)**2
            R -= half
            C -= half

        # 한 단위 작은 사각형으로 이동
        N -= 1

    print(ans)

solution()
