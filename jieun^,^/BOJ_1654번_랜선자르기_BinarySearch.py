# 제각각 길이의 K개의 랜선 -> 같은 길이로 N개의 랜선 (남게 되는 길이는 버려야 함) (K >= N)
# N개의 랜선으로 나눴을 때 최대 길이를 구하기

# Binary Search (이진 탐색) - 오름차순 정렬된 자료를 반으로 나누어 탐색하는 방법
# (순차 검색 - 순서대로 보면서 찾는다 (정렬 상관 X) O(n)) vs (이진 탐색 - 반.드.시 정렬된 상태 O(log n))

# 랜선 길이를 (1 ~ 주어진 랜선 중 가장 짧은 길이) 중 가장 긴 길이 & N개 만족하는지 찾기
# (start+end) // 2 = mid, 
# mid 값에서 가능한 랜선 개수 >= N -> 더 긴 길이로 (mid ~ end) 탐색
# mid 값에서 가능한 랜선 개수 < N -> 더 짧은 길이로 (start ~ mid) 탐색

# 입력 받기
K, N = map(int, input().split())
lines = []
for k in range(K):
    lines.append(int(input()))

# 인덱스 대신 길이를 직접 넣음
left = 1    # 최소 길이
right = max(lines)  # 최대 길이

ans = 0

# 이분탐색이 완료될 때까지 탐색
while left <= right:
    mid = (left+right)//2

    cnt = 0
    for l in lines:
        cnt += l // mid

    # 아예 안 됨 - 길이 줄여야 함
    if cnt < N:   # 현재 mid에 있는 길이로 만들 수 있는 랜선의 개수 < N --> 길이를 줄여야 함
        right = mid - 1 # 왼쪽으로 이동해서 탐색

    # 최적화 - 최대한 긴 길이로 향함
    else:           # 현재 mid에 있는 길이로 만들 수 있는 랜선의 개수 > N --> 길이를 늘려야 함
        left = mid + 1  # 오른쪽으로 이동해서 탐색
        ans = mid   # 정답이 아닌 경우에도 mid는 계속 계산되어지기 때문에 ans를 따로 두어야 함

print(ans)
