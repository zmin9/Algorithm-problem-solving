def is_prime(num):  # num이 소수인지 확인
    t = int(num**0.5) + 1   # sqrt(num)까지만 탐색해도 소수인지 확인 가능
    for i in range(2, t):
        if num%i==0: return False
    return True


def backTrack(N, ans):
    str_ans = str(ans)
    if len(str_ans)==N:
        print(str_ans)
        return

    pos_range=[1, 3, 5, 7, 9]   # 0과 2의 배수로 끝나는 수는 소수 X
    for p in pos_range:  
        tmp = ans*10 + p
        if is_prime(tmp):
            backTrack(N, tmp)


def solution():
    N = int(input())    # 자리수

    # 한 자리수 중 소수
    primes = [2, 3, 5, 7]

    # 맨 앞자리가 소수로 시작하는 신기한 소수 탐색
    for p in primes:
        backTrack(N, p)
    

solution()