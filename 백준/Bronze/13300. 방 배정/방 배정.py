student_cnt = [[0]*6, [0]*6]

total_cnt, maxV = [*map(int,input().split())]

for i in range(0, total_cnt):
    gender, grade = [*map(int, input().split())]
    student_cnt[gender][grade-1] += 1

ans = 0

for i in range(0,2):
    for j in range(0,6):
        ans += (student_cnt[i][j]+(maxV-1)) // maxV
print(ans)