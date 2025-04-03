#include <bits/stdc++.h>

using namespace std;

int timev = 0;
int n,applecnt, ax, ay = 0;

int board[102][102] = {0,}; // 0 빈칸, 1 지렁이, 2 사과

int dir = 1; //오른쪽을 1로 둔다.
int changeCnt;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
//indexed-1
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> applecnt;

    while(applecnt--){
        cin >> ax >> ay;
        board[ax][ay] = 2;
    }

    cin >> changeCnt;
    queue<pair<int, char>> q;
    while(changeCnt--){
        int t;
        char d;
        cin >> t >> d;
        q.push({t,d});
    }

    deque<pair<int,int>> dq;
    dq.push_front({1,1});

    board[1][1] = 1;
    
    while(1){
        if(!q.empty()){
            auto change = q.front();
            if(change.first == timev){
                q.pop();
                if(change.second == 'D'){
                    dir = (dir+3) % 4 ;// 1 => 0, 2 => 1, 3 => 2, 0 => 3
                }else{
                    dir = (dir+1) % 4 ;// 1=> 2, 2 => 3, 3 => 0, 0 => 1
                }
            }
        }
        
        auto head = dq.front();
        auto tail = dq.back();

        int nx = head.first + dx[dir];
        int ny = head.second + dy[dir];

        timev++;

        if(nx < 1 || ny < 1 || nx > n || ny > n) break;; // 벽에 박았을 때
        if(board[nx][ny] == 1) break; // 자기 자신을 박았을 때
       
        if(board[nx][ny] == 0){ // 이동한 곳에 아무것도 없다면 (사과가 있을 때는 실행하지 않아도 된다.)
            //이동했으니 꼬리는 다시 없앤다.
            board[tail.first][tail.second] = 0;

            //deque에서 꼬리 없앤다.
            dq.pop_back();
        }

        //이동한 곳을 머리로 둔다.
        dq.push_front({nx,ny});

        //이동한 곳을 board에 체크한다.
        board[nx][ny] = 1;

        
    }

    cout << timev;
    return 0;
}