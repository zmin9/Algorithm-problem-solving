# N(짝수)명을 N/2명씩 2팀으로 나눌 때, 두 팀의 능력치 차이의 최소값은?
# ( Sij -> i와 j가 한 팀이 됐을 때의 능력치 ex) 1,3,6이 한 팀이 됐을 때 능력치 = S13 + S16 + S31 + S36 + S61 + S63 )

# 입력 받기
N = int(input())    # 4 <= N <= 20
S = []
for i in range(N):
    s = list(map(int, input().split()))
    S.append(s)

# 가능한 경우의 수 배열 생성하기 --> 조합 구하는 방법: combinations (기존 배열, 몇개씩 추출할건지)
from itertools import combinations

# 팀원들에게 번호 붙이고 배열 생성
n = []
for i in range(N):  # 0 ~ N-1
    n.append(i)

comb = list(combinations(n, N//2))  # 가능한 조합 -> N C (N//2)

ans_diff = 100  # 최대 차이:99 (1 <= Sij <= 100)

# 어차피 두 팀의 차이를 구하면 되기 때문에 조합 목록의 절반만 탐색 ex) (0, 1, 2) - (3, 4, 5) 는 한 쌍으로 묶임
for i in range(len(comb)//2): 
    start_team = comb[i]
    link_team = comb[len(comb)-1-i]   # start team의 인덱스 + link team의 인덱스 == 조합 개수 -1
    
    diff = 0    # 이번 조합에서의 팀 능력치 차이
    
    for s in start_team:    # + start_team 능력치 합
        for ss in start_team:
            diff += S[s][ss]

    for l in link_team:     # - link_team 능력치 합
        for ll in link_team:
            diff -= S[l][ll]

    diff = abs(diff)        # 절대값으로 변환
    ans_diff = min(ans_diff, diff)  # 기존 차이와 이번 차이 중 작은 쪽으로 답을 교체

print(ans_diff)
