#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> board(301, vector<int>(301,0));
vector<vector<int>> tempv(301, vector<int>(301,0));


int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int n,m;
int cnt = 0;
int timev = 0;
bool CheckIce(){
    
    for(int i = 1 ; i < n-1; i++){
        for(int j = 1; j < m-1; j++){
            if(board[i][j] > 0){
                // cout << "CheckIce "<< cnt << "\n";
                return true;
            }
                
        }
    }
    // cout << "CheckIce false" << cnt << "\n";
    return false;
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }

    
    
    while(CheckIce() && cnt < 2){
        timev++;
        for(int i =0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] <= 0){
                    tempv[i][j] = 0;
                    continue;
                }

                int watercnt = 0;
                for(int index = 0; index < 4; index++){
                    int nx = i + dx[index];
                    int ny = j + dy[index];

                    if(board[nx][ny] == 0) watercnt++;
                }
                int height = board[i][j] - watercnt;
                tempv[i][j] = height > 0 ? height : 0;
            }
        }

        //계산된 tempv 값을 board에 다시 옮긴다.
        for(int i =0; i< n; i++){
            board[i].assign(tempv[i].begin(), tempv[i].begin()+m);
        }

        vector<vector<bool>> vis(n, vector<bool>(m,false));
        cnt = 0;
        for(int i =0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] <= 0) continue;
                if(vis[i][j]) continue;

                queue<pair<int,int>> q;
                q.push({i,j});
                vis[i][j] = true;
                cnt++;
                while(!q.empty()){
                    auto cur = q.front();
                    q.pop();

                    for(int k = 0; k < 4; k++){
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];

                        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        if(board[nx][ny] <= 0) continue;
                        if(vis[nx][ny]) continue;

                        q.push({nx,ny});
                        vis[nx][ny] = true;
                    }
                }
            }
        }
    }
    

    if(cnt < 2){
        timev = 0;
    }

    cout << timev << "\n";
    return 0;
}