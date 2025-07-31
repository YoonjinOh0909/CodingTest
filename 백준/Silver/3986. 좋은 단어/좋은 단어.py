import sys 

input = sys.stdin.readline

cnt = int(input().strip())

ans = 0
for _ in range(cnt):
    val = input().strip()
    st = []
    for v in val:
        if st and st[-1] == v:
            st.pop()
        else : # st가 비었거나, st[-1] 과 v 의 값이 다를 때
            st.append(v)
    if not st: # st가 비어있을 경우에
        ans += 1

print(ans)