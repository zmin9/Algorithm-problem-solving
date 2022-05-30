N = int(input())    # 0 <= N < 1,000,000
# 최소 수: 0
# 최대 수: 9876543210

global cnt;
cnt = 0

def Backtrack(ans, digit):    # ans는 배열
    global cnt
    #print(ans, cnt)
    
    # N번째까지 count -> 끝내기!
    if cnt == N and len(ans)==digit:
        cnt += 1            
        # ans 출력
        ans_string=""
        for a in ans:
            ans_string += str(a)
        # print("ans:", ans_string)
        print(ans_string)
        return
        
    if len(ans)==digit:
        cnt += 1
        return

    for i in range(0, 10):  # 올 수 있는 자리수 0 ~ 9
        if i < ans[-1]:     # 마지막 자리보다 작은 수
            ans.append(i)
            Backtrack(ans, digit)
            ans.pop()


for i in range(1, 11):  # digit: 1~10
    for j in range(0, 10):  # 첫 자리수: 0~9        
        Backtrack([j], i)        
        #if i==1: cnt+=1        
        if cnt > N: break
    if cnt > N: break


### N번째 감소하는 수가 없는 경우 ###
if N>1022: print("-1")