from queue import PriorityQueue     # 파이썬 우선순위 큐
import sys

N = int(input())    # 1 <= N <= 100_000
q = PriorityQueue()
for n in range(N):
    x = int(sys.stdin.readline())   # 그냥 input() -> 시간 초과 (받아야 할 줄이 많음 (최대 100_000))
    if x==0:
        if q.empty():       # 큐에 아무것도 없으면 -> 0 출력
            print(0)
        else:               # 큐에서 가장 우선순위가 높은 것 출력 (가장 작은 수)
            print(q.get())
    else:
        q.put(x)        # 큐에 추가
    