#include <bits/stdc++.h>

using namespace std;

int board[1005][1005] = {0,};
int vis[1005][1005] = {0,};

int m,n;
bool iszero = false;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dayCnt = 0;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    queue<pair<int,int>> q;
    for(int i =0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] == 0) iszero = true; // 0 있으면 true
            if(board[i][j] == 1){
                q.push({i,j});
                vis[i][j] = true;
            }
        }
    }

    if(!iszero){ //만약 0이 없는 상태였다면 모두 익어있는 상태.
        cout << 0;
        return 0;
    }

    int dayStartq = q.size();
    int checkCnt = 0;
    while(!q.empty()){
        if(dayStartq == checkCnt){ // 하루 동안 익힘이 시작되는 부분의 개수와 체크한 개수 확인.
            dayStartq = q.size();
            checkCnt = 0;
            dayCnt++;
        }

        pair<int,int> cur = q.front();
        q.pop();        

        checkCnt++;
        for(int i =0; i < 4; i++){
            int curx = cur.first + dx[i];
            int cury = cur.second + dy[i];
            
            if(curx < 0 || cury < 0 || curx >= n || cury >= m){
                continue;
            }
            if(vis[curx][cury] || board[curx][cury] == -1){ // 이미 익혀있거나 벽으로 가로 막혀 있는 경우
                continue;
            }

            q.push({curx, cury});
        
            board[curx][cury] = 1;
            vis[curx][cury] = true;
            
        }
    }

    for(int i =0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 0){
                cout << "-1";
                return 0;
            }
        }
    }

    cout << dayCnt;

    return 0;
}