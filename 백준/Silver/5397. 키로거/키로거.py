# < : 왼쪽으로 커서 이동
# > : 오른쪽으로 커서 이동
# - : 삭제
# 문자 : 입력

import sys
input = sys.stdin.readline

cnt = int(input().strip())

for _ in range(cnt):
    left = []
    right = []

    order = input().strip()

    for a in order:
        if a == '<' and left : # 왼쪽 커서 입력 했을 때 (왼쪽에 문자가 있을 때)
            right.append(left.pop())
        elif a == '>' and right : # 오른쪽 커서 입력 했을 때 (오른쪽에 문자가 있을 때)
            left.append(right.pop())
        elif a == '-' and left: # 삭제 입력
            left.pop()
        elif a not in ['<', '>','-']:
            left.append(a)
    
    print("".join(left + right[::-1]))