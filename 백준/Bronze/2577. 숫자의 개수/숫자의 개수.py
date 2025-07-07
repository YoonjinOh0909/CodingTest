a = int(input())
b = int(input())
c = int(input())

val = str(a * b * c)

ans = [0] * 10

for v in val:
    ans[int(v)] += 1

for a in ans:
    print(a)
