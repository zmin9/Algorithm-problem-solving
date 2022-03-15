# 백준 2607번

# 비슷한 단어의 조건
# 같은 구성 가지기: 1) 같은 종류의 문자 2) 같은 문자는 같은 개수
# 한 문자를 더하거나, 빼거나, 다른 문자로 대체하기

import copy

def solution():
    count = int(input())    #단어의 개수
    
    w1 = input()    # 첫 단어
    w1 = list(w1)
    
    res = 0 # 정답

    for i in range(count-1):
        w = copy.deepcopy(w1)

        word = input()
        word = list(word)

        # w1과 word의 길이가 1
        if len(w) == len(word) == 1 :
            res+=1

        # w1과 같은 길이
        elif len(w) == len(word):
            for j in word:
                if j in w:        # 겹치는 글자는 삭제
                    w.remove(j)
            if len(w)<=1: res+=1
        
        # w1과 길이가 1 차이 남
        elif abs(len(w)-len(word)) == 1:
            if len(w)>len(word):
                for j in word:
                    if j in w:
                        w.remove(j)
                if len(w)==1: res+=1
            
            elif len(w)<len(word):
                for j in w:
                    if j in word:
                        word.remove(j)
                if len(word)==1: res+=1
    
    print(res)

solution()