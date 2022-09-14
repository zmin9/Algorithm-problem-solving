### EPPER 19회 ###

import sys  # sts,stdin.readline()을 쓰지 않으면.. 시간 초과

def solution():
    N = int(sys.stdin.readline())    # 도현이네 반 학생의 수
    students=[] # 이름 국어 영어 수학
    for n in range(N):
        students.append(list(sys.stdin.readline().split()))

    # 정렬 기준
    # 1. 국어 점수 높 -> 낮
    # 2. 영어 점수 낮 -> 높
    # 3. 수학 점수 높 -> 낮
    # 4. 이름 사전순 낮 -> 높

    # 국어: 내림차순, 영어: 오름차순, 수학: 내림차순, 이름: 오름차순
    students.sort(key = lambda x: (-int(x[1]), int(x[2]), -int(x[3]), x[0]))    # 다중 조건 정렬

    for s in students:
        print(s[0])

solution()