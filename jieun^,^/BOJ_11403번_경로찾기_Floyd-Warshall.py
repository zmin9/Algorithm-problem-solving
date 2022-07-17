from cmath import inf

def solution():
    N = int(input())
    
    dist = []
    for n in range(N):
        line = list(map(int, input().split()))
        dist.append(line)

    # 플로이드 워셜
    for k in range(N):
        for i in range(N):
            for j in range(N):
                # i->k 경로가 존재하고, k->j 경로가 존재한다면 -- i->j 경로도 존재 
                if dist[i][k]==1 and  dist[k][j]==1:
                    dist[i][j]=1

    # 정답 출력
    for i in range(N):
        line = ""
        for j in range(N):
            line += str(dist[i][j]) + " "
        print(line)


solution()
