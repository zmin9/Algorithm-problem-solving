N = int(input())
A = list(map(int, input().split()))

visited = [False] * N

global max_diff
max_diff = 0

def Backtrack(idx, visited, ans):
    global max_diff

    # 방문 처리
    visited[idx] = True
    ans.append(idx)

    if len(ans) == N:
        diff = 0
        
        for n in range(N-1):
            diff += abs(A[ans[n+1]] - A[ans[n]])
        
        if diff > max_diff: 
            max_diff = diff
        return

    for n in range(N):
        if visited[n] == False:
            Backtrack(n, visited, ans)
            visited[n] = False
            ans.remove(n)

for n in range(N):
    Backtrack(n, visited, [])
    visited = [False] * N

print(max_diff)