### EPPER 19회 ###

def solution():
    stick = input()
    stick = stick.replace("()", "R")    # 레이저는 아예 다른 문자로 치환

    list = []
    ans = 0

    for s in stick:
        if s=="R":  # 레이저 : list에 있는 막대 수 만큼 잘림 (+ans)
            ans += len(list)
        elif s=="(":    # ( : list에 push
            list.append("(")
        elif s==")":    # ) : 막대의 끝 -> 막대 개수를 ans에 추가
            list.pop()
            ans += 1

    print(ans)

solution()
