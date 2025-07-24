import sys
input = sys.stdin.readline

cnt = int(input().strip())
ans = []
for _ in range(cnt):
    val = int(input().strip())
    if val == 0:
        ans.pop()
    else:
        ans.append(val)

print(sum(ans))