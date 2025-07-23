import sys

input = sys.stdin.readline

n, k = [*map(int,input().strip().split())]

left = []
right = []
ans = []

left = [i+1 for i in range(n)]

while len(ans) != n :
    for i in range(k):
        if len(right) == 0: 
            right = left[::-1]
            left = []
        if i+1 == k: # k번째라면
            ans.append(str(right.pop()))
        else :
            left.append(right.pop())

print(f"<{", ".join([str(a) for a in ans])}>")

