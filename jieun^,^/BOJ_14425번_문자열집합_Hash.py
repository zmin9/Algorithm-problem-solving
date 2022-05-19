import sys
N, M = map(int, input().split())    # 집합 S에 포함되는 N개의 문자열, 체크해야하는 M개의 문자열

# 1 <= 문자열의 길이 <= 500 ==> hash table의 크기: 500
hash = set(sys.stdin.readline().rstrip() for _ in range(N))

ans = 0
for m in range(M):
    s = sys.stdin.readline().rstrip()
    if s in hash:
        ans += 1

print(ans)

## Python에서 set은 hash table로 구현됩니다. 
## 그래서 원소 판단이 O(1)로 가능합니다. 
## 반면 list는 모든 원소를 다 확인해야 하므로 원소판단이 O(N)이 걸립니다.