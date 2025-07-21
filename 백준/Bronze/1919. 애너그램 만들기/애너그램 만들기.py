li = [0] * 26

a = input()
b = input()

for a_i in a:
    li[ord(a_i)-97] += 1

for b_i in b:
    li[ord(b_i)-97] -= 1

ans = 0

for a in li:
    if a > 0 :
        ans += a
    if a < 0:
        ans -= a

print(ans)