# 백준 2011번

import sys
sys.setrecursionlimit(10000)

global dp
dp = [-1]*5001


# dp 2부터 채우면 됨 (dp[0]과 dp[1]은 이미 정의)
def d(n, code):
    if dp[n] != -1: return dp[n]
    
    elif code[n] == '@' or code[n-1] == '@':    # n 혹은 n-1에 @가 존재
        dp[n] = d(n-1, code)  # '@'는 단독으로 존재하는 경우만 가능
        return dp[n]
    
    # @는 존재 x
    elif int(code[n-1])*10 + int(code[n]) > 26:   # n 앞의 숫자까지 고려했을 때 27이상 -> 단독으로 존재
        dp[n] = d(n-1, code)
        return dp[n]
    
    else:
        dp[n] = d(n-1, code) + d(n-2, code)
        return dp[n]


def solution():
    code = input()

    # code에 0이 존재하는 경우에 대해서 처리
    while(1):
        if code.find('0')==-1: break        # code에 0이 존재하지 않음
    
        elif code.index('0')==0 : return 0  # code의 맨 앞에 0이 존재 -> 잘못된 code
    
        else:   # code에 0이 존재 (맨 앞은 아님)
            if code[code.index('0')-1]=='1' :  # 0 앞에 1 -> '10' -> '@'
                code = code.replace('10', '@')
            elif code[code.index('0')-1]=='2' : # 0 앞에 2 -> '20' -> '@'
                code = code.replace('20', '@')
            else:               # 0 앞에 3 이상 -> 잘못된 code
                return 0

    length = len(code)

    dp[0] = 1
    if length == 1: return 1
    elif code[0]=='@' or code[1]=='@': dp[1] = 1    # 1번째 혹은 2번째에 @가 존재할 때
    # @는 존재 x
    elif int(code[0])*10 + int(code[1]) > 26 : dp[1] = 1  # 1-2 번째가 27이상일 때
    else: dp[1] = 2

    
    d(length-1, code) # dp 채우기 실행
    
    ans = dp[length-1]
    ans %=1000000
    return ans

print(solution())