n = int(input())
arr = [*map(int, input().split())]
x = int(input())

cnt = 0
x_arr = [0] * (1000000)
for av in arr :
    x_arr[av] += 1

for av in arr :
    if x-av<1000000 and x -av > 0 and x_arr[x-av] == 1 :
        cnt += 1

print(cnt // 2)