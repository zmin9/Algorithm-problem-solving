# n개의 포도주가 있을 때, 최대한 많은 양의 포도주를 마셔라 (단, 연속으로 놓여있는 3잔은 마실 수 없음)
n = int(input())

wine = []
for _ in range(n):
    w = int(input())
    wine.append(w)

# [6, 10, 13, 9, 8, 1]
# [6, 16, 23, 28, 33, 32]   # dp[n-1] or dp[n-2]

dp = [0] * n    # i번째까지에서 최대의 경우

def D():

    dp[0] = wine[0]
    if n==1: return
    
    dp[1] = dp[0]+wine[1]
    if n==2: return

    # 2-3 = -1이므로 따로 처리해주기 --> [a, b, c]일 때, a+c or b+c or a+b
    dp[2] = max(dp[0]+ wine[2], wine[1]+ wine[2], dp[1]) 
    if n==3: return

    # max 후보에 dp[i-1]이 추가되어야 하는 이유: 현재 i를 포함하지 않고, i-1, i-2번째를 연속으로 합하는 것이 더 큰 경우 고려
    # ex) [1, 1, 0, 0, 1, 1] 

    # bottom - up DP
    for i in range(3, n):   # 3 ~ n-1
        dp[i] = max(dp[i-2]+ wine[i], dp[i-3]+wine[i-1]+ wine[i], dp[i-1]) 

D()

ans = dp[n-1]
print(ans)
