# 수열 A = {10, 20, 10, 30, 20, 50} --> 가장 긴 증가하는 부분 수열 ={10, 20, 30, 50} 길이: 4

len_A = int(input())
A = list(map(int, input().split()))

dp = [0] * (len_A+1)  # i번째까지의 최대 길이 (i번째 수 자기 자신 포함)

dp[0] = 1             # 1번째는 하나밖에 없으니깐 길이: 1

for i in range(1, len_A):   # 2 ~ len_A-1 번째까지의 최대 길이 구하기
    
    # i 이전의 수 중에서 나보다 작으면서 && 최대 dp

    max_dp = 0              
    for j in range(0, i):   # i 이전까지를 한번 훑어서 보기
        if A[j]<A[i]:       # 나보다 작은가?
            if max_dp < dp[j]:  # 그러한 수 중 최대 dp를 갖는가?
                max_dp = dp[j]
    
    dp[i] = max_dp+1    # 나 이전의 최대 길이 수열에 나까지 추가되었으니깐 +1
    
print(max(dp))          # 최대 dp가 정답!