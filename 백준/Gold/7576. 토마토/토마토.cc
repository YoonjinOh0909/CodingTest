#include <bits/stdc++.h>

using namespace std;

int board[1002][1002] = {0,};
int dist[1002][1002] = {0,};

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int m,n;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    queue<pair<int,int>> q;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] == 1){
                q.push({i,j});
            }
            if(board[i][j] == 0){
                dist[i][j] = -1;
            }
        }
    }

    while(!q.empty()){
        auto cur = q.front(); q.pop();

        for(int i = 0; i < 4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m){
                continue;
            }
            if(board[nx][ny] == -1 || dist[nx][ny] != -1){
                continue;
            }
            
            q.push({nx, ny});
            board[nx][ny] = 1;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        }
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(dist[i][j] == -1){
                cout << "-1";
                return 0;
            }
            ans = max(ans, dist[i][j]);
        }   
    }

    cout << ans;
    return 0;
}