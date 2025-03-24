#include <bits/stdc++.h>

using namespace std;

int t, m, n, k;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t; //케이스 개수

    while(t--){
        cin >> m >> n >> k;
        int board[m][n] = {0,};
        bool vis[m][n] = {0,};
        int cnt = 0;
        for(int i = 0; i< m; i++){
            fill(board[i],board[i]+n,0);
            fill(vis[i],vis[i]+n,0);
        }
        while(k--){
            int x,y;
            cin >> x >> y;
            board[x][y] = 1;
        }

        queue<pair<int,int>> q;

        for(int i =0; i < m; i++){
            for(int j =0; j < n; j++){
                if(board[i][j] == 0 || vis[i][j]){ //아무것도 없는 땅이거나 이미 들린 배추있는 땅
                    continue;
                }
                cnt++;
                q.push({i,j});
                while(!q.empty()){
                    auto cur = q.front();
                    q.pop();

                    for(int z = 0; z < 4; z++){
                        int nx = cur.first +dx[z];
                        int ny = cur.second + dy[z];

                        if(nx < 0 || ny < 0 || nx >= m || ny >=n) continue;
                        if(board[nx][ny] == 0 || vis[nx][ny]) continue;

                        vis[nx][ny] = true;
                        q.push({nx,ny});
                    }
                }
            }
        }
        cout << cnt << "\n";
    }
    
    return 0;
}