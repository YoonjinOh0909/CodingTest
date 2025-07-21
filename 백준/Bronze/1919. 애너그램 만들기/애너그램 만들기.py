a = input()
b= input()
a_l = len(a)
b_l = len(b)

if a_l < b_l :
    a,b = b,a

count = 0
for a_i in a:
    if a_i in b:
        count += 1
        b = b.replace(a_i, "",1)
print(a_l + b_l - count * 2)