def solution(N, times):
    minTime = 1 # 최소: 1분
    maxTime = max(times) * N # 최대: 제일 오래 걸리는 심사원 X N명

    while minTime < maxTime:
        midTime = (minTime + maxTime) // 2

        tmp = 0     # midTime 동안 처리한 사람의 수
        for t in times:
            tmp += (midTime // t)
        
        if tmp >= N: # midTime 동안 N명 이상 처리 -> midTime을 더 줄이자
            maxTime = midTime
        else:    #  tmp =< N - midTime 동안 N명을 처리하지 못 함 -> midTime을 늘리자
            minTime = midTime + 1


    return minTime


print(solution(6, [7, 10]))
