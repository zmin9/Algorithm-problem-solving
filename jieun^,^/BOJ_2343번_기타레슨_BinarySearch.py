# N개의 강의를 M개의 블루레이에 나누어 담을 때, 최소 블루레이의 크기는? (강의 순서는 유지)

N, M = map(int, input().split())
length = list(map(int, input().split()))

# 블루레이의 크기: min_value = max(length), max_value = sum(length)
min_value = max(length) # 한 강의를 나눠서 담을 수는 없으니깐, 강의 중 가장 긴 길이가 블루레이의 최소 크기가 되어야 함
max_value = sum(length)

ans = 0

while min_value <= max_value :

    # 블루레이의 크기
    mid_value = ( min_value + max_value ) // 2

    cnt = 1  # mid_value의 크기의 블루레이로 강의를 나눌 때 생기는 블루레이의 개수
    one_bluray_length = 0   # 이번 블루레이에 담겨있는 강의의 길이
    for l in length:
        # 이번 강의를 블루레이에 담았을 때 크기를 초과하지 않음
        if one_bluray_length + l <= mid_value :
            one_bluray_length += l  # 기존 블루레이에 이번 강의를 담음
        # 초과
        else:
            one_bluray_length = l   # 새 블루레이에 이번 강의를 담음
            cnt += 1

    if cnt > M: # mid_value 길이의 블루레이로 강의를 담았더니 M개보다 많이 나온다 
        # -> 길이를 늘려야 함
        min_value = mid_value + 1

    else: # mid_value 길이의 블루레이로 강의를 담았더니 M개보다 적거나 같게 나온다 
        # -> 길이를 줄여야 함 (최적화)
        max_value = mid_value - 1
        ans = mid_value


print(ans)
