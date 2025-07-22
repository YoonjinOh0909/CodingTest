
import sys
input = sys.stdin.readline

left = list(input().strip())
right = []

cmd_cnt = int(input().strip())

for _ in range(cmd_cnt):
    cmd = list(input().strip().split())
    if cmd[0] == "L" and left:
        right.append(left.pop())
    elif cmd[0] == "D" and right:
        left.append(right.pop())
    elif cmd[0] == "B" and left:
        left.pop()
    elif cmd[0] == "P":
        left.append(cmd[1])

print("".join(left + right[::-1]))
