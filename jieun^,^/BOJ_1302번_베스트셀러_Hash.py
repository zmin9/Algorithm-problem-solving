N = int(input())    # 오늘 팔린 책의 개수

book = [[] for _ in range(50)]  # book[0] = [a, 3], [b, 3]

for _ in range(N):
    input_book = input()    # 책 입력 받기
    hash_func = len(input_book) - 1 # hash function = len(책 제목) - 1

    count_flag = 0  # book 리스트에 추가했는지 여부

    for h in book[hash_func]:
        # 똑같은 제목의 책이 이미 존재
        if h[0]==input_book:    
            h[1] += 1   # 개수 +1
            count_flag = 1
            break
    
    # 똑같은 책이 존재 X
    if count_flag==0:           
        book[hash_func].append([input_book, 1])     # 새로 추가


max_cnt = 0     # 책 개수 최대
ans = " "       # 최대 개수의 책 제목 초기화

# 해쉬 테이블 탐색하기
for b in book:

    # 해당 책 제목 길이의 책이 존재
    if len(b)!=0:   
        # 해당 길이를 갖는 책들 탐색
        for h in b:
            if h[1] > max_cnt:  # 지금까지 최대 개수의 책보다 많음
                max_cnt = h[1]
                ans = h[0]

            elif h[1] == max_cnt:   # 지금까지 최대 개수의 책과 개수가 같음 -> 제목 알파벳이 더 작은 것 선택 (ex) 'a' < 'b')
                if ans == " ":  # 아직 정해진 적 X -> 무조건 선택
                    ans = h[0]
                elif h[0] < ans:    # 'a' < 'b'
                    ans = h[0]

print(ans)
