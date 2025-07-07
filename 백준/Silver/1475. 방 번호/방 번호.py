val = input()
arr = [0] * 10
for a in val:
    arr[int(a)] = val.count(a)
sixNnine = arr[6] + arr[9]
arr[6] = 0
arr[9] = int(sixNnine/2) + sixNnine%2

print(*sorted(arr)[-1:])
