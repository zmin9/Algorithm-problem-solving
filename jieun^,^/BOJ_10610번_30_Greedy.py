# N의 순서를 바꿔서 30의 배수가 되는 수 중 가장 큰 수를 만들기
# 30의 배수가 아예 존재하지 않는다면 -1

# 간단하게 생각하면..? 만들 수 있는 모든 수, 가장 큰 수 -> 작은 수, 30배수인지 확인

# 하.지.만.
# 10의 배수 -> 1의 자리는 무.조.건. 0
# 3의 배수 -> 각 자리 수의 합이 무.조.건. 3의 배수
# => N에 0이 포함되어 있고, 자릿수의 합이 3의 배수라면 무.조.건. 가능

# => 가장 큰 수 = 높은 순으로 sort한 수

def solution():
    N = input()    # 마르코가 만난 양수 N
    ans = 0 # 정답 0으로 초기화

    if '0' in N:    # 10배수
        arr = []
        for n in N:
            arr.append(int(n))

        if sum(arr)%3==0:   # 3배수
            arr.sort(reverse=True)
            ans_str = ''
            for a in arr:
                ans_str += str(a)
            ans = int(ans_str)
 
        else: ans = -1  # 3배수 X
        
    else:       # 10배수 X
        ans = -1

    print(ans)

solution()

# 시간 초과 나오길래.. sort가 오래 걸리나? 해서 퀵 sort 까지 해봤는데 .. 여전히 시간초과
# 아마도 N을 배열에 넣을 때, %10으로 각 자리 수를 넣었는데, 그게 오래 걸렸던 것 같다