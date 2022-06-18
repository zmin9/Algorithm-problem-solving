from cmath import inf
import sys

N = int(input())    # 1 <= N <= 10^6    # 입력 받을 줄이 많으면 sys.stdin.readline() 써야 함!! 안 그러면 시간 초과
DT = []
for n in range(N):
    d, t = map(int, sys.stdin.readline().split())       
    DT.append([d, t])

DT.sort(key=lambda x:x[1], reverse=True)
# DT = [[1, 13], [3, 10], [2, 8]]

day = inf    # 그 전 과제 시작일

for dt in DT:
    # (그전 과제 시작일) > (이번 과제 마감일)
    if day > dt[1]: 
        day = dt[1]-dt[0]+1
    
    # (그전 과제 시작일) >= (이번 과제 마감일)
    # 이번 과제 기간: 그전 과제 마감일 - 기간 ~ 그전 과제 마감일-1
    else:
        day= day - dt[0]

ans = day -1
print(ans)