# import sys

# input = sys.stdin.readline

# cnt = int(input().strip())

# li = []
# ans = 0
# for _ in range(cnt):
#     val = int(input().strip())

#     if li : # 만약 li에 들어있으면
#         if li[0] <= val : # li[0] val 비교
#             ans += len(li)

# import sys
# from collections import deque
# input = sys.stdin.readline

# cnt = int(input().strip())
# li = deque()
# ans = 0

# for _ in range(cnt):
#     val = int(input().strip())

#     # 만약 li에 들어있으면 li[0]과 val을 비교한다.
#     if li:
#         # li가 없거나 li[0] > val 이 될때까지 반복한다
#         while li and li[0] <= val:
#             ans += (len(li) -1) 
#             li.popleft()

#         # while 구문을 빠져나왔다는 뜻은 li가 비어있거나, li[0] > val 일 때
#         li.append(val)
#     # 없으면 val을 li에 추가한다.
#     else :
#         li.append(val)
    
# 만약 li[0] > val 이면 li에 추가하고 다음 val을 받는다.
# 만약 li[0] <= val 이면 ans += len(li) -1 을 하고  popleft를 한다

# 근데 이렇게 했을 경우 10 3 6 4 2 이렇게 되면 어떻게 다시 계산을 하나??
    # 안될듯


import sys
from collections import deque
input = sys.stdin.readline

cnt = int(input().strip())
li = []
ans = 0
for _ in range(cnt):
    val = int(input().strip())
    if not li:
        li.append([val, 0]) # [0]에는 val 값을, [1]에는 해당 건물을 바라볼 수 있는 관리인 수.
    else:
        while li :
            li_last = len(li)-1
            if li[li_last][0] > val : # 만약 직전의 높이가 현재 val의 값보다 크다면
                li.append([val, li[li_last][1]+1])
                break
            else :
                tmp = li.pop()
                ans += tmp[1]
        if not li :
            li.append([val, 0])

while li :
    ans += li.pop()[1]

print(ans)
