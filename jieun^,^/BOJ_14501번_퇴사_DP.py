# 상담원 백준이는 N일 동안 상담 일을 했을 때 벌 수 있는 최대 금액은?
# 하루에 예약된 상담은 1개씩

N = int(input())    # 1 <= N <= 15
T = []  # 걸리는 기간
P = []  # 얻을 수 있는 금액
for i in range(N):
    t, p = map(int, input().split())
    T.append(t)
    P.append(p)

dp = [0]*(N+1)  # 0~N-1 번째 날에 대한 dp

# 시작일 & 끝나는 날
# dp[3] = 10
# dp[6] = 20
# dp[3] = 10
# 시작일>3: dp[4] = 20 + dp[3] = 30
# 시작일>4: dp[6] = 15 + dp[4] = 45 vs dp[6]=20 --> dp[6] = 45
# dp[8] -> 범위 초과
# 끝

for i in range(N): # i: 시작일(0 ~ N-1) 
    
    max_dp = 0
    for j in range(0, i):   # 0 ~ i-1   # 시작일 전 날들에 대해 훑어봄
        if max_dp < dp[j] : max_dp = dp[j]      # i번째 이전이라서 겹치지도 않으면서 최대 dp
   
    end = i + T[i] -1       # i번째날에 시작해서 끝나는 날 구하기   ex) 0번째 날에 시작해서 3일 동안 상담 -> end = 2
    if end >= N: continue   # 범위 벗어나면 패스
    if dp[end] < max_dp + P[i]: # 같은 dp의 경우 더 큰 것을 유지
        dp[end] = max_dp + P[i]
    

ans = max(dp)
print(ans)
