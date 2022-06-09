# 1. 4자리가 아님 -> 앞부분 0 생략
# 2. :: -> 0000 생략 (몇 개의 그룹인지는 모름 -> 전체 그룹 개수 생각해서 만들기) (대신, ::은 1번만 쓸 수 있음)

ip_addr = list(input().replace("::", "Z"))      # :: -> Z로 치환

ip=[[] for _ in range(8)]

idx=0
for i in ip_addr:
    
    if i==":":
        idx+=1

    elif i=="Z":
        if ip[idx]==[]:
            ip[idx]=["ZERO"]
            idx+=1
        else:
            idx+=1
            ip[idx]=["ZERO"]
            idx+=1
    
    else:
        ip[idx].append(i)
    

zero_cnt = ip.count([])

for i in range(len(ip)):
    if ip[i]==["ZERO"]:
        ip[i] = ["0", "0", "0", "0"]
        for z in range(zero_cnt):
            ip.insert(i, ["0", "0", "0", "0"])

    else:
        while 1:
            if len(ip[i])==4: break
            else: ip[i].insert(0, "0")


#### 출력 ####
ans = ""
for i in range(len(ip)):
    if ip[i]==[]: continue

    elif i==0:
        for j in range(4):
            ans += ip[i][j]
    else:
        ans += ":"
        for j in range(4):
            ans += ip[i][j]

print(ans)
