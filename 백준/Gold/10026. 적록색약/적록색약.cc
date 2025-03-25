#include <bits/stdc++.h>

using namespace std;

int n;
string board[101];

int cnt = 0;
queue<pair<int,int>> q;

int dx[4] = {1,0,-1,0};
int dy[4] = {0, 1, 0,-1};

void CheckBFS(){
    bool vis[101][101] = {0,};
    cnt = 0;
    for(int i =0; i < n; i++){
        for(int j =0; j < n; j++){
            if(vis[i][j]){
                continue;
            }
            q.push({i,j});
            vis[i][j] = true;
            cnt++;
            while(!q.empty()){
                auto cur = q.front();
                q.pop();

                for(int k =0; k< 4; k++){
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];

                    if(nx < 0 || ny < 0 || nx >=n || ny > n) continue; // 범위 벗어났을 때
                    if(vis[nx][ny]) continue; // 이미 들렸을 때
                    if(board[nx][ny] != board[cur.first][cur.second]) continue;

                    q.push({nx,ny});
                    vis[nx][ny] = true;
                }

            }
        }   
    }
    cout << cnt << "\n";
}
int main(void){
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    cin >> n;

    for(int i =0; i < n; i++){
        cin >> board[i];
    }

    CheckBFS();
    for(int i =0; i < n; i++){
        for(int j =0; j < n; j++){
            if(board[i][j] == 'R')
                board[i][j] = 'G';
            
        }
    }
    CheckBFS();
    return 0;
}