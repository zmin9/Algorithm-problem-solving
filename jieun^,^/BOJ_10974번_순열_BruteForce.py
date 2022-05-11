# 1~N까지의 수로 이루어진 순열을 사전순으로 출력하세요

from math import factorial

N = int(input())    # (1 <= N <= 8)


visited = [False] * N   # 0 ~ N-1 의 방문 여부 (-> 실제로는 1 ~ N (ans에서 +1씩 해주기))

def DFS(curNum, visited, ans):  # 이번 순열을 저장할 배열 ans = []  
    visited[curNum] = True
    ans.append(curNum)

    # 순열의 길이가 N이 될 경우, 이번 순열은 다 채운 거니깐 출력
    if len(ans)==N: 
        ans_str = ""
        for i in (ans):
            ans_str += str(i+1) 
            ans_str += " "
        print(ans_str)
        
    # 다음에 올 수를 탐색
    for i in range(N):
        if visited[i]==False:
            DFS(i, visited, ans)
            # 다시 되돌리기
            visited[i] = False  
            ans.pop()

# 첫 수가 1 ~ N
for i in range(N):
    DFS(i, visited, [])
    visited = [False]*N
