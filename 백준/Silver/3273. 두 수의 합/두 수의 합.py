n = int(input())
arr = set([*map(int, input().split())])
x = int(input())

cnt = 0
for i in arr:
    if x-i in arr:
        cnt+=1
print(cnt // 2)