# 백준 9012번

# '(' -> 스택에 넣음, ')' -> 스택을 pop
# ')'이 들어왔는데 스택이 비어있음 -> NO
# 다 끝났을 때 스택이 비었음 -> YES, 스택이 비지 않았음 -> NO

def solution():
    T = int(input())    # 테스트 데이터의 개수
    res = []
    for i in range(T):
        data = input()
        stack = []
        
        j=0
        while(1):
            if data[j]=='(': stack.append('(')
            
            elif data[j]==')':
                if len(stack)>=1: stack.pop()
                else: 
                    res.append("NO")
                    break
            
            j+=1
            if j==len(data): break

        if len(res)==i+1: pass
        
        else:
            if len(stack)==0: res.append("YES")
            else: res.append("NO")

    
    for i in res:
        print(i)

solution()