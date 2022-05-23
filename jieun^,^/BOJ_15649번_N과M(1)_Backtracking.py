N, M = map(int, input().split())    # 1 ~ N까지의 자연수 중 중복없이 M개를 고른 수열을 모두 구하여라

def Backtrack(num, ans, visited):
    
    # 해당 num 방문 처리 & 답에 추가
    visited[num] = True
    ans.append(num+1)

    # ans의 길이가 M이면 출력하고, 멈추기
    if len(ans) == M:
        ans_string = ""
        for a in ans:
            ans_string += str(a) + " "
        print(ans_string)
        return

    # 아직 길이가 M보다 작음 -> 더 탐색하기
    for next_num in range(N):
        if visited[next_num]==False:
            Backtrack(next_num, ans, visited)
            visited[next_num]=False
            ans.remove(next_num+1)


            
visited = [False] * N   # 0 ~ N-1 방문여부

for n in range(N):
    Backtrack(n, [], visited)
    visited = [False] * N   # 방문 기록 초기화
