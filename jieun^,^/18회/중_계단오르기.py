# 백준 2579번

# 연속 3개 계단은 밟을 수 없다, 마지막 계단은 꼭 밟아야 한다.
# bottom - up DP -> 반복문 사용 
# 계단 시작 index: 0 , n번째 계단의 index: n

global dp
dp = [0]*301    # 계단의 수는 최대 300개

def solution():
    num = int(input())
    score = [0] * (301) # 계단의 수는 최대 300개
    for i in range(0,num):  # 1~6
        score[i+1] = int(input())
   
    dp[0]=0
    dp[1]=score[1]
    dp[2]=dp[1]+score[2]

    for i in range(3, num+1):  # 3~num
        dp[i] = max(dp[i-3]+score[i-1], dp[i-2]) + score[i]
        # dp[i]는 무조건 자기 자신의 점수는 포함,
        # (2칸 전에서 온 dp) 또는 (3칸 전에서 온 dp + 1칸 전 score) 중 max 값 고름

    print(dp[num])

solution()    