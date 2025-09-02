from collections import deque

# 상자의 모든 곳을 하나씩 확인하면서 1이 있는 (익은 토마토가 있는) 곳에서부터 queue를 활용해서 BFS를 진행한다.
# visit 배열을 모두 -2로 채운다. 익은 토마토로 시작할 때 -2이라면 그 부분을 0으로 설정한다.
# 익은 토마토로 인해 다음 토마토가 익을 때는 +1 을 해서 익는 날짜를 계산한다.
# 확인할 때 벽인 부분이 발견되면 해당 visit 배열을 -1로 설정한다.
# 상자의 모든 부분을 확인한 뒤에 max 값을 구해서 익을 수 있는 토마토가 익는 날짜를 구한다.
# 이후 min 값을 구했을 때 -2가 나오면 익지 않은 토마토가 발견되었다는 뜻으로 모두 익을 수 없는 상황. 따라서 답을 -1로 도출한다.

####
# 만약
# 1 0 0
# 0 0 0
# 0 0 1
# 이라면 2가 나와야한다. 왜냐면 동시 다발적으로 일어나는 것이기 때문에. 따라서 맨 처음에 바로 1인 부분을 모두 알아내고 
# 이후에 해당 Q가 빌 때까지 진행해야 한다. 

m, n = map(int,input().split())

board = []

for _ in range(n):
    board.append([*map(int, input().split())])

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

visit = [[-2 for _ in range(m)] for _ in range(n)]

Q = deque()
for x in range(n):
    for y in range(m):
        if board[x][y] == -1: # 만약 벽이라면
            visit[x][y] = -1 # visit 부분에 벽 표시를 한다.
            continue
        if board[x][y] == 1 : # 익은 토마토라면 Q에 넣는다.
            Q.append((x,y))

while (len(Q) != 0):
    cur = Q.popleft()

    if visit[cur[0]][cur[1]] < 0 : # 만약 현재 위치가 한 번도 계산이 안 되었던 곳이라면
        visit[cur[0]][cur[1]] = 0

    for i in range(4):
        nx = cur[0] + dx[i]
        ny = cur[1] + dy[i]
        if nx < 0 or ny < 0 or nx >= n or ny >= m: # 범위 밖으로 나갔다면
            continue
        if board[nx][ny] != 0 or visit[nx][ny] >= 0: # -1 이면 벽이니깐 넘어가고, 1이면 이미 익은 토마토라서 넘어간다.
            continue

        board[nx][ny] = 1 # 토마토가 익었다고 표시한다
        visit[nx][ny] = visit[cur[0]][cur[1]] + 1 # 직전보다 하루 더 지났으니 1 더 해준다.
        Q.append((nx, ny)) # Q에 넣어서 다음을 확인할 수 있게 한다.


maxv = max(map(max, visit))
minv = min(map(min,visit))

if minv == -2:
    print(-1)
else :
    print(maxv)