# 잔돈 - 500, 100, 50, 10, 5, 1
# 거스름돈의 개수가 가장 적게
# 잔돈은 항상 충분하게 준비 되어 있음

# 항상 1000을 냄
# 입력 price - 물건 값 (1<=price<1000)
price = int(input())

# 출력 ans - 잔돈의 개수
ans = 0

change = 1000 - price

# ex) 620 -> 500x1 + 100x1 + 10x2
# 최대한 큰 돈의 단위로 거스름돈을 지불해야 개수가 최소
money = [500, 100, 50, 10, 5, 1]
for m in money:
    x = change//m
    if x>=1:
        ans += x
        change %=m
    
print(ans)