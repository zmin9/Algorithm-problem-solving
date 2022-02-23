# 백준 9012번

def VPS(PS):  # 올바른 문자열 VPS - return 1, 아니면 - return 0
    # '('와 ')'로만 구성
    # '('가 들어오면 스택에 넣고,
    # ')'가 들어오면 스택이 isempty인지 확인하고 스택을 pop하기, 만약 empty거나, 최종 스택에 남는게 있으면 잘못됐음 -> return 0

    stack=[]
    for i in range(len(PS)):
        if PS[i] == '(':
            stack.append('(')
        
        else:   # PS[i] == ')'
            if len(stack)==0:   # 스택이 empty
                return 0        # 잘못된 문자열
            else:
                stack.pop()
        
    if len(stack)!=0: return 0  # 최종 스택에 남아있는 것이 있다면 잘못된 문자열

    return 1    # 올바른 문자열


def solution():
    T = int(input())
    PS = []
    for i in range(T):
        x=input()
        PS.append(x)

    for i in range(T):
        res = VPS(PS[i])
        if res==1:
            print("YES")
        else:
            print("NO")    


solution()