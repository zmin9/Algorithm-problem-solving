# 체력과 기쁨 교환하는 배낭 문제
# N-1번째 사람부터 시작해서 전 사람에게 인사하는 것과 인사하지 않는 경우의 이득을 재귀적으로 따져보기

def knapsack(health, n, L, J):  # health: 남은 체력 / n: 사람 인덱스 / L: 잃는 체력 / J: 얻는 기쁨
    
    # 남은 체력이 0이거나
    if health==0 or n==0:
        return 0
    if L[n-1] >= health:
        return knapsack(health, n-1, L, J)
    else:
        # 전 사람과 인사하는 경우
        # 전 사람과 인사하지 않는 경우
        return max(J[n-1] + knapsack(health-L[n-1], n-1, L, J), knapsack(health, n-1, L, J))


def solution():
    N = int(input())    # 사람의 수
    L = list(map(int, input().split()))
    J = list(map(int, input().split()))

    ans = knapsack(100, N, L, J)

    print(ans)
    
solution()