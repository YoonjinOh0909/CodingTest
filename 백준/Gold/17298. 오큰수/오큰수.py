import sys

input = sys.stdin.readline

cnt = int(input().strip())

li = [*map(int, input().strip().split())]

ans = [-1 for _ in range(cnt)]
stack = []

for i in range(cnt):
    while stack :
        top = stack[-1]
        if top[0] < li[i]: # 만약 맨 뒤에 있는 값보다 지금 들어오는 값이 더 크다면
            tmp = stack.pop()
            ans[tmp[1]] = li[i] # 맨 뒤 있던 index에 현재 값을 넣어준다.
        else :
            break
    stack.append([li[i], i])

ans = [*map(str,ans)]
print(" ".join(ans))