# 백준 2607번

# 비슷한 단어 조건
# 1) 같은 구성 가지기 (같은 종류의 문자가 같은 개수만큼)
# 2) '한 문자만' 더하거나 빼기 혹은 다른 문자로 바꾸기

import copy

def solution():
    num = int(input())

    ans = 0

    w1 = input()
    w1 = list(w1)

    for j in range(num-1):
        # word에 원본 w1 저장
        word = copy.deepcopy(w1)   # 파이썬에서 내부 객체들까지 모두 새롭게 카피하려면 깊은 복사를 사용해야함 (앝은 복사는 같은 메모리 주소를 바라보게 함)

        w2 = input()
        w2 = list(w2)

        # w1과 w2의 길이 차이가 2 이상
        if abs(len(w1) - len(w2)) >=2 : pass
        
        # w1, w2 길이가 1 -> 무조건 비슷한 단어
        elif len(w1) == len(w2) == 1: ans+=1

        # w1 길이 == w2 길이
        elif len(w1) == len(w2): 
            for i in range(len(w1)):
                if w1[i] in w2:
                    w2.remove(w1[i])
            if len(w2)<=1: ans+=1
                
        # w1, w2 길이가 1 차이
        elif abs(len(w1) - len(w2)) == 1:
            # w1 > w2
            if len(w1)>len(w2): 
                for i in range(len(w2)):
                    if w2[i] in word:
                        word.remove(w2[i])
                if len(word) == 1: ans+=1 # 긴 거는 무조건 1개만 남아야 함

            # w1 < w2
            elif len(w1)<len(w2):
                for i in range(len(w1)):
                    if w1[i] in w2:
                        w2.remove(w1[i])
                if len(w2) == 1: ans+=1  # 긴 거는 무조건 1개만 남아야 함

    return ans

print(solution())