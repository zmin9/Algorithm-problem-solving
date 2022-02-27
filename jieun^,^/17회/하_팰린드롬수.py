# 백준 1259번

import math

def solution():
    while(1):
        N = input()
        if N=='0': break
        res = 1
        # if len(N): 짝수 - len(N)/2 - 1 까지 봐야 함, len(N):홀수 - len(N)//2 - 1까지 봐야함
        for i in range(len(N)//2):   # 0 1
            if N[i]!=N[len(N)-1-i]:
                res = 0; break
        
        # 결과 출력 
        if res==0: print("no")
        else: print("yes")

solution()