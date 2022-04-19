# N개의 지방, 지방별로 예산 요청, 총 예산 M (N<=M<=1,000,000,000)

N = int(input())
budget = list(map(int, input().split()))
M = int(input())

# 모든 요청이 가능 -> 그대로 배정
# 모든 요청을 들어줄 수 X -> 상한액 계산 -> 상한액 이상 요청: 상한액 배정, 이하: 그대로 배정

# 이분 탐색 - 오름차순 정렬된 배열에서만 가능
budget.sort()

# 최소값: 1, 최대값: 최대 요청 예산
min_value = 1
max_value = max(budget)

ans = 0

while min_value<=max_value:
    mid_value = (min_value + max_value)//2

    m = M   # 국가 전체 예산을 m에 넣어둠
    for b in budget:
        if b>= mid_value:   # 요청 예산 >= mid_value --> mid_value
            m -= mid_value
        else:               # 요청 예산 <= mid_value --> 요청 예산
            m -= b
    
    if m < 0:   # mid_value를 줄여야 함 
        max_value = mid_value - 1    #왼쪽으로 이동해서 탐색
        
    else:       # mid_value를 늘려도 됨
        min_value = mid_value + 1
        ans = mid_value

print(ans)