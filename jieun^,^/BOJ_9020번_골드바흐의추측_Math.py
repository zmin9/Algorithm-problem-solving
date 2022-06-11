# 10,000 까지의 소수 여부 구하기

primes = [True] * 10001
primes[0] = False; primes[1] = False
for i in range(2, 100):
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
            j = n-i
            if primes[j]==True: 
                ans = [i, j]
                break
        
    print(ans[0], ans[1])

            
