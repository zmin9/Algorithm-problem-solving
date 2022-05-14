# N명이 참가하는 토너먼트에서 (1라운드에서의) 김지민과 임한수의 번호
N, kim, lim = map(int, input().split())     # 2 <= N <= 100,000
import math
round = 1    # 김지민과 임한수가 대결하게 되는 라운드 번호 (서로 대결하지 않을 경우: -1)

kim_idx = math.ceil(kim/2)
lim_idx = math.ceil(lim/2)

while 1:
    if kim_idx == lim_idx: break

    kim_idx = math.ceil(kim_idx/2)
    lim_idx = math.ceil(lim_idx/2)

    round += 1

print(round)