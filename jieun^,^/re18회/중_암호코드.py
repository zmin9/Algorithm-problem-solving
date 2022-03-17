# 백준 2011번

# ! @ # $ -> 3번째 자리에서 가능한 경우: $ 단독 존재 (dp[2]) + #$로 존재 (dp[1])

def solution():
    
    code = input()
    if len(code)==0: return 0

    dp=[0]*(5001)   # n번째 숫자까지 가능한 경우의 수 (5000자리 수까지 존재)

    # dp[0] 채우기
    if int(code[0])==0: dp[0]=0; return dp[0]   # 0번째 자리부터 0이면... 끝
    else: dp[0]=1
    if len(code)==1: return dp[0]   # 1자리 수인 경우 생각하기!!

    # dp[1] 채우기
    if int(code[1]) == 0:
        if int(code[0]) ==1 or int(code[0]) ==2: dp[1] = 1  # 10 또는 20 일 경우 합쳐서만 존재해야 함
        else: dp[1]=0; return dp[1]    # 30, 40 ... 끝
    elif int(code[0])*10 + int(code[1]) >=27 : dp[1] = 1  # 27이상의 알파벳은 없으므로, 0번째와 1번째 각자 존재
    else: dp[1]=2

    # dp[2] ~ dp[len(code)-1] 채우기
    for i in range(2, len(code)):   
        if int(code[i])==0:  # i번째 자리가 0인 경우
            if int(code[i-1])==1 or int(code[i-1])==2: dp[i] = dp [i-2]  # 10또는 20 -> 무조건 앞자리 수와 같이 존재
            else: return 0    # 30, 40 ... 끝
        elif int(code[i-1])==0: dp[i] = dp[i-1]
        elif int(code[i-1])*10 + int(code[i]) >=27 : dp[i] = dp[i-1]  # 무조건 앞자리수와 따로 존재
        else: dp[i] = dp[i-1] + dp[i-2]

    ans = dp[len(code)-1]
    #print(dp)
    return ans

print(solution() % 1000000)
