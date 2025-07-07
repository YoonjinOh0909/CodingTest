s = input()
alpha = "abcdefghijklmnopqrstuvwxyz"
arr =[0 for _ in range(0, 26)]

# print(alpha.index("a"))

for ss in s:
    arr[alpha.index(ss)] += 1

for a in arr:
    print(a, end =" ")
