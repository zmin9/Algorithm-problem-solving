from math import factorial

N = int(input())    # 0 <= N <= 500

# 10 x 9 x 8 x 7 x 6 x 5 x 4 x 3 x 2 x 1
# 10! = 3628800

fact_N = factorial(N)
tmp=fact_N

cnt = 0
while 1:
    if tmp%10==0:
        tmp = tmp//10       # /는 안 되고 //는 됨 ...
        cnt += 1
    else: break

print(cnt)
    