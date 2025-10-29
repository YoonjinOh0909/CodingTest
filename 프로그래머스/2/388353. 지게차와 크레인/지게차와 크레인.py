def solution(storage, requests):
    
    n= len(storage) # 4
    m = len(storage[0]) # 5

    board = [[ 1 for _ in range(m)] for _ in range(n)]

    dir = [(1,0), (0, 1), (0, -1), (-1, 0)]

    from collections import deque

    for req in requests:
        if len(req) > 1 : # 크레인으로 없애기
            for x, st_row in enumerate(storage):
                for y, val in enumerate(st_row):
                    if val == req[0] :
                        board[x][y] = 0

        else : # 지게차로 없애기
            for_delete = list()
            for x, st_row in enumerate(storage):
                for y, val in enumerate(st_row):
                    if board[x][y] == 0: # board가 0이면 이미 삭제가 된 상황.
                        continue
                    if val != req[0] :
                        continue
                    finish = False
                    dq = deque()
                    dq.append((x,y))
                    vis = [[ False for _ in range(m)] for _ in range(n)]
                    
                    while(dq and not finish) : # dq 
                        qx, qy = dq.popleft()

                        for dx, dy in dir:
                            curx = qx + dx
                            cury = qy + dy

                            if curx < 0 or cury < 0 or curx >= n or cury >= m :
                                for_delete.append((x,y))
                                finish = True
                                break
                            if board[curx][cury] == 1:
                                continue
                            if vis[curx][cury] :
                                continue
                            dq.append((curx, cury))
                            vis[curx][cury] = True

            for del_x, del_y in for_delete:
                board[del_x][del_y] = 0

    ans = 0
    for b in board:
        ans = sum([ans, sum(b)])


    return ans