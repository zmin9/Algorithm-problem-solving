import math

# 게임 횟수: X, 이긴 게임: Y, 승률: Z
X, Y = map(int, input().split())
Z = math.trunc((Y * 100 / X) )   # math.trunc - 소수점 버림
# Y / X * 100은 틀림.. 아마 부동소수점 문제인 듯

def BinarySearch(X, Y, Z):
    #print(X, Y, Z)
    ans = -1

    # 지금까지의 승률이 99% 이상
    # 100 -> 앞으로의 게임도 계속 이길 예정이기 때문에 절대 변하지 않는다
    # 99 -> 그 전 게임에서 1개 이상 틀렸기 때문에 99%, 절대 100%가 되지 못함
    if Z >= 99 : return ans

    # 추가로 할 게임 횟수
    min_value = 1   # 승률이 변하려면 최소 1번은 더 해야 함
    max_value = X

    # Z가 변하게 되는 최소 게임
    ans = -1    # Z가 절대 변하지 않는 경우 -> -1
    while min_value <= max_value:
        mid_value = (min_value+max_value) // 2

        win_rate = math.trunc( (Y+mid_value) * 100 / (X+mid_value) )

        if win_rate <= Z:   # 승률이 변하지 않음
            min_value = mid_value + 1   # 큰 쪽으로 이동해서 탐색
        
        else:   # 승률이 변함, 최소값을 찾기 위해 계속함
            max_value = mid_value - 1   # 작은 쪽으로 이동해서 탐색
            ans = mid_value
    
    return ans

ans = BinarySearch(X, Y, Z)
print(ans)
