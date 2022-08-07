def solution():
    N = int(input())    # 도시의 개수

    dist = list(map(int, input().split()))  # 도시 간의 거리

    price = list(map(int, input().split())) # 각 도시에서 기름의 가격
    # [5, 2, 4, 1]

    ans = dist[0] * price[0]
    minOil = price[0]

    for n in range(1, N-1): # 1 ~ N-2
        if minOil>price[n]:
            minOil = price[n]
        ans += minOil * dist[n]

    print(ans)

    
solution()
