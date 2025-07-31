import sys

input = sys.stdin.readline

val = input().strip()
st = []
ans = 0
for i,v in enumerate(val):
    if not st: # 만약 아무것도 없으면 st에 넣는다.
        st.append([v, i])
    else:
        if st[-1][0] != v: # '(' 와 ')' 밖에 없기 때문에 같은지 안 같은지만 판단.
            if i - st[-1][1] == 1: # 만약 현재의 index와 마지막 값의 index가 1 차이가 나면, ()로 레이저 위치를 표시
                st.pop()
                ans += len(st)
            else : # 만약 그렇지 않다면, 막대기의 끝을 뜻함. 
                st.pop()
                ans += 1 # 해당 막대만 끝이기 때문에 그 끝을 +1 해준다.
        else:
            st.append([v,i])

print(ans)
