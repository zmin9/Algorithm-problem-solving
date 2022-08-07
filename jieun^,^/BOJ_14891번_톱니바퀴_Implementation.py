### 순수하게 해당 톱니바퀴만 회전시키는 함수 ###
def turn(gear, g, dir): 
    tmp = gear[g].copy()

    if dir==1:  # 시계 방향       
        for i in range(8):
            if i==0: gear[g][i]=tmp[7]
            else: gear[g][i]=tmp[i-1]

    if dir==-1:       # 반시계 방향
        for i in range(8):
            if i==7: gear[g][i]=tmp[0]
            else: gear[g][i]=tmp[i+1]


def rotation(gear, g, dir, checked):    # gear: 톱니바퀴 배열, g: 회전시킬 톱니바퀴 번호, dir: 시계 or 반시계, checked: 이번 순서에 이미 회전시켰는지 체크
    before = gear[g].copy()
    turn(gear, g, dir)
    checked[g]=True

    ### 인접 톱니바퀴 체크 ###
    # 오른쪽 톱니바퀴 체크
    if g!=3:    # 제일 오른쪽 톱니바퀴가 아닌 경우
        if before[2]!= gear[g+1][6]:   # 오른쪽 톱니바퀴와 만나는 부분이 N과 S임
            if checked[g+1]!=True:
                rotation(gear, g+1, -dir, checked)


    # 왼쪽 톱니바퀴 체크
    if g!=0:    # 제일 왼쪽 톱니바퀴가 아닌 경우
        if before[6]!= gear[g-1][2]:
            if checked[g-1]!=True:
                rotation(gear, g-1, -dir, checked)


def calGear(gear):
    # 12시 방향이 S극일 때만 점수 획득
    ans = 0
    if gear[0][0]=='1': ans += 1   
    if gear[1][0]=='1': ans += 2
    if gear[2][0]=='1': ans += 4
    if gear[3][0]=='1': ans += 8    

    return ans

def solution():
    ### 톱니 바퀴의 현재 상태 입력 받기 ###
    gear = []
    for g in range(4):
        gear.append(list(input()))  # N: '0', S: '1'

    ### K번 회전하기 ###
    K = int(input())
    for k in range(K):
        g, d = map(int, input().split())    # a: 회전할 바퀴(1~4), b: 회전 방향 (1: 시계, -1: 반시계)
        rotation(gear, g-1, d, [False, False, False, False])

    #print("회전 후 gear: ", gear)


    ### 회전 후 계산하기 ###
    return calGear(gear)

print(solution())
