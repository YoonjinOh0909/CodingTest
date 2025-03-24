#include <bits/stdc++.h>

using namespace std;

int n, m;
int board[1002][1002] = {0,};
int jdis[1002][1002] = {0,};



int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

#define X first
#define Y second


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    queue<pair<int,int>> fireq;
    queue<pair<int,int>> jq;
    
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < m; j++){
            char c;
            cin >> c;

            if(c == 'F'){
                board[i][j] = 1;
                fireq.push({i,j});
            }
            if(c == 'J'){
                jdis[i][j] = 1;
                jq.push({i,j});
            }
            if(c == '#'){
                board[i][j] = -1;
                jdis[i][j] = -1;
            }
        }
    }

    while(!fireq.empty()){
        auto cur = fireq.front(); fireq.pop();

        for(int i =0; i<4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if(nx < 0 || ny < 0 || nx >=n || ny >= m){
                continue;
            }
            if(board[nx][ny] > 0|| board[nx][ny] == -1){ //지나갔거나 벽이거나
                continue;
            }

            board[nx][ny] = board[cur.X][cur.Y] + 1;
            fireq.push({nx,ny});
            
        }
    }

    while(!jq.empty()){
        auto cur = jq.front(); jq.pop();

        for(int i =0; i<4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if(nx < 0 || ny < 0 || nx >=n || ny >= m){ // 끝에 도달했을 때
                cout << jdis[cur.X][cur.Y];
                return 0;
            }
            if(jdis[nx][ny] > 0 || board[nx][ny] == -1) continue; // 들렸거나 벽이 있을 때
            if(board[nx][ny] != 0 && board[nx][ny] <= jdis[cur.X][cur.Y]+1){
                continue;
            }

            jdis[nx][ny] = jdis[cur.X][cur.Y] + 1;
            jq.push({nx,ny});
            
        }
    }

    cout << "IMPOSSIBLE";
    

    return 0;
}