# 10,000 까지의 소수 여부 구하기

primes = [True] * 10001
primes[0] = False; primes[1] = False
for i in range(2, 100):     # sqrt(10,000)까지만 탐색해도 10,000까지의 소수여부를 알 수 있음
    if primes[i]==True:
        for j in range(2*i, 10001, i):
            primes[j]=False

T = int(input())
for t in range(T):
    n = int(input())    # 짝수

    ans = []
    for i in range(n//2, 1, -1):
        if primes[i]==False: continue
        else:   # primes[i]==True
            j = n-i     # i + j = n
            if primes[j]==True: 
                ans = [i, j]
                break       # i가 클수록 i-j가 작아짐
        
    print(ans[0], ans[1])
