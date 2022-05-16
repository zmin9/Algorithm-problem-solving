T = int(input())    # 테스트 케이스의 수
for t in range(T):
    
    N = int(input())    # 이번 테스트 케이스에서 해빈이가 가진 의상의 수
    hash = [[] for _ in range(20)]      # 모든 문자열은 1~20자 길이 (0~19 사용)
    
    # 신해빈이 가지고 있는 의상 입력 받기
    for n in range(N):
        name, kind = input().split()    # hat, headgear
        hash_func = len(kind)-1     # 문자열 길이를 hash function으로 사용

        #### hash에 추가하기 ####
        append_flag = 0
        if hash[hash_func]!=[]:   # 같은 hash function값을 가짐
            for h in hash[hash_func]: # ex) h[6] = [eyewear, sunglasses], [abcdefg, asdf]
                if h[0]==kind:          # 같은 종류 (같은 face)
                    h.append(name)
                    append_flag = 1
        
        # 아직 추가 x
        if append_flag == 0 :   
            hash[hash_func].append([kind, name])

    ans = 1
    ### 가능한 조합의 개수 구하기 ###
    for h in hash:
        if len(h)!=0:
            for hh in h:
                ans *= len(hh)

    if N==0: print(0)
    else: print(ans-1)  # 아무것도 안 입는 경우는 빼기
