# N개의 수, N-1개의 연산자
N = int(input())    # 2 <= N <= 11
A = list(map(int, input().split()))
op = list(map(int, input().split()))    # [+, -, x, /]

ans_list = []

def max_DFS(A_idx, used_op, ans):
    remain_op = [op[0]-used_op[0], op[1]-used_op[1], op[2]-used_op[2], op[3]-used_op[3]]

    if remain_op == [0, 0, 0, 0]: ans_list.append(ans); return
    
    for i in range(4):
        if remain_op[i]>0:  # 남아있는 사용할 수 있는 연산자
            if i==0: 
                max_DFS(A_idx+1, [used_op[0]+1, used_op[1], used_op[2], used_op[3]], ans+A[A_idx])
            elif i==1: 
                max_DFS(A_idx+1, [used_op[0], used_op[1]+1, used_op[2], used_op[3]], ans-A[A_idx])
            elif i==2: 
                max_DFS(A_idx+1, [used_op[0], used_op[1], used_op[2]+1, used_op[3]], ans*A[A_idx])
            else: 
                if ans<0:   # 양수로 바꾼후 계산 후 - 붙임
                    max_DFS(A_idx+1, [used_op[0], used_op[1], used_op[2], used_op[3]+1], -((-ans)//A[A_idx]))
                else:
                    max_DFS(A_idx+1, [used_op[0], used_op[1], used_op[2], used_op[3]+1], ans//A[A_idx])


max_DFS(1, [0, 0, 0, 0], A[0])

print(max(ans_list))
print(min(ans_list))
