# 서로 다른 C개의 알파벳 소문자 중 L개 = 최소 한 개의 모음(a e i o u), 최소 두 개의 자음
# 순서는 오름차순 - ex) abc ( a < b )

L, C = map(int, input().split())    # 3 <= L <= C <= 15
alp = sorted(list(input().split()))     # 알파벳 사전순 정렬

def Backtrack(ans, num):
    
    # 방문 처리
    ans.append(alp[num])

    # 길이가 L이 됨 -> 끝내고 출력
    if len(ans)==L:
        # 모음을 포함하는지 확인
        if 'a' in ans or 'e' in ans or 'i' in ans or 'o' in ans or 'u' in ans:  
            
            # 자음을 2개 이상 포함하는지 확인
            cnt = 0
            for a in ans:
                if a not in ['a', 'e', 'i', 'o', 'u']: cnt += 1
            
            if cnt >=2: # 2개 이상의 자음
                # 정답 출력
                ans_string = ""
                for a in ans:
                    ans_string += a
                print(ans_string)

        return   # 이번 ans 배열 끝.

    # 뒷부분을 더 탐색 - 오름차순이어야 하기 때문에 이번 num 뒷부분에서만 탐색
    for i in range(num+1, C):
        Backtrack(ans, i)
        ans.pop()   # 이번 요소 다시 빼기 - backtrack

for c in range(C):
    Backtrack([], c)