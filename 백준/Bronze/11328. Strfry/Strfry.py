cnt = int(input())

for i in range(cnt):
    ali, bli = map(list, input().split())
    ali.sort()
    bli.sort()
    ans = "Possible" if ali == bli else "Impossible"
    print(ans)

