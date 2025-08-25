n, m = [*map(int,input().strip().split())]

board = []

for _ in range(n):
    board.append([*map(int, input().strip().split())])

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

vis = [[0 for _ in range(m)] for _ in range(n)]

paint = []

for x in range(n) : # 
    for y in range(m) :
        if board[x][y] != 1 or vis[x][y]  != 0 : # 만약 그 칸이 1이 아니거나 (그림이 아니거나) vis 칸이 0이 아니거나(이미 들렸거나) 그렇다면 넘어간다.
            # print("넘어갑니다!")
            continue
        Q = [] # queue
        vis[x][y] = 1
        Q.append((x,y)) # 해당 좌표값 Q에 넣는다.
        size = 0 # 시작을 했으니 size 초기화 한다.

        while len(Q) != 0 : # len(Q)가 0이라면 Q가 비었다는 뜻
            size += 1
            cur = Q.pop(0)
            for i in range(4):
                nx = cur[0] + dx[i]
                ny = cur[1] + dy[i]
                # print(f"nx {nx} ny {ny}")
                if nx < 0 or ny < 0 or nx >= n or ny >= m: # 범위 내의 값이 아니라면
                    # print(f"1 nx {nx} ny {ny}")
                    continue
                if vis[nx][ny] == 1 or board[nx][ny] == 0: # 이미 들렸던 곳이라면, 혹은 그림이 아니라면
                    # print(f"2 nx {nx} ny {ny}")
                    continue
                # print(f"nx {nx} ny {ny} 추가")
                vis[nx][ny] = 1 # 들린 곳이라고 체크
                Q.append((nx,ny)) # Q에 추가해서 계산하도록 한다.
        
        paint.append(size) # 연속한 그림을 모두 다 찾으면 paint에 size를 추가한다

print(len(paint))
if len(paint) == 0:
    print(0)
else :
    print(max(paint))