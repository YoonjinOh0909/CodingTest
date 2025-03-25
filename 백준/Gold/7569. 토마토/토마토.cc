#include <bits/stdc++.h>

using namespace std;

int m,n,h; //y,x,z
int board[101][101][101] ={0,};
int dist[101][101][101] ={0,};
queue<pair<int,pair<int,int>>> q;

int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

#define X first
#define Y second

int main(void){
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    cin >> m >> n >> h;

    for(int zi = 0; zi < h; zi++)
    {
        for(int i = 0; i < n; i++){
            fill(dist[zi][i], dist[zi][i]+m, -1);
            for(int j =0; j < m; j++){
                cin >> board[zi][i][j];
                if(board[zi][i][j] == 1){ // 토마토가 들었다면
                    q.push({zi,{i,j}});
                    dist[zi][i][j] = 0;
                }
                
            }
        }
    }

    while(!q.empty()){
        auto cur = q.front();
        q.pop();
   
        for(int i = 0 ; i < 6; i++){
            int nz = cur.X + dz[i];
            int nx = cur.Y.X + dx[i];
            int ny = cur.Y.Y +dy[i];

            if(nz < 0 || nx < 0 || ny < 0 || nz >= h || nx >= n || ny >= m) continue; // 범위 밖의 데이터
            if(dist[nz][nx][ny] != -1 || board[nz][nx][ny] != 0) continue; // dist -1이 아니라면 한 번 들린 것. board가 0이 아니면 이미 익은 토마토 or 벽

     
            board[nz][nx][ny] = 1;
            dist[nz][nx][ny] = dist[cur.X][cur.Y.X][cur.Y.Y] + 1;
            q.push({nz,{nx,ny}});
            
        }
    }

    int maxv = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                if(board[i][j][k] == 0){ // 안 익은 토마토가 있기 때문.
                    cout << -1 << "\n";
                    return 0;
                }
                maxv = max(maxv, dist[i][j][k]);
            }
        }   
    }

    cout << maxv;
    return 0;
}