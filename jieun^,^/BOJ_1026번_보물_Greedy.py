# 길이가 N인 정수 배열 A, B
# 함수 S = A[0]xB[0] + ... + A[N-1]xB[N-1]
# S를 최소로 -> A를 재배열 (B는 불가)
# 가장 큰 값 x 가장 작은 값이 최소

N = int(input())
A=list(map(int, input().split()))
B=list(map(int, input().split()))

A.sort()
B.sort(reverse=True)

# 리턴 값
S=0
for i in range(N):
    S += A[i]*B[i]

print(S)