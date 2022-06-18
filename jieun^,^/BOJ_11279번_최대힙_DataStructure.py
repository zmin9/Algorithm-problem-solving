from queue import PriorityQueue
import sys

N = int(input())    # 1 <= N <= 100,000
Q = PriorityQueue()

for n in range(N):
    X = int(sys.stdin.readline())   # 받아야 할 라인이 많기 때문에
    
    if X == 0:
        if Q.empty():
            print(0)
        else:
            print(-Q.get())
    else:
        Q.put(-X)

# 음수로 만들어서 우선순위를 정한 후에
# 꺼낸 후 다시 양수로 만든다
