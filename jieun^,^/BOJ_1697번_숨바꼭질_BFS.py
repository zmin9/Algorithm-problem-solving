# 수빈이의 위치 N, 동생의 위치 K
N, K = map(int, input().split())

# graph의 인덱스 - 현재 점 위치, 값 - 이 위치까지 오는 데 걸린 시간
graph = [0 for _ in range(100_001)]    # 0 <= N, K <= 100_000

from collections import deque

# queue에 위치를 넣음
Q = deque()
Q.append(N) # 시작 위치 넣음

while 1:
    X = Q.popleft() # 왼쪽부터 pop
    
    if X==K:    # 우리가 찾던 K인 경우 끝!
        break    

    # (X-1) or (X+1) or (2*X) -> 3가지 경우
    for NX in (X+1, X-1, 2*X):
        # NX가 범위 내 && 아직 방문 X (시작 위치 N을 제외하고는 0초인 건 아직 업데이트 하지 않았다는 뜻)
        if 0 <= NX <= 100_000 and graph[NX] == 0:   
            graph[NX] = graph[X] + 1    # X -> NX 로 이동 시간 1초
            Q.append(NX)
    
print(graph[K])
