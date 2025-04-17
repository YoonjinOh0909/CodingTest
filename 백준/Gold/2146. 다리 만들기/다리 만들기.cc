#include <bits/stdc++.h>

using namespace std;

int n;
int board[100][100] = {0,};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0,1,0,-1};

#define X first
#define Y second

int islandT = 1;
int minV = 10000;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i =0 ; i<n;i++){
        for(int j = 0; j < n ; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < n ; j++){
            if(board[i][j] == 1){
                islandT++; // 처음 시작이 1이라서 한번 들린 섬은 2부터 체크가 된다.

                queue<pair<int,int>> q;
                q.push({i,j});
                board[i][j] = islandT;

                while(!q.empty()){
                    auto cur = q.front();
                    q.pop();

                    for(int k =0 ; k < 4; k++){
                        int nx = cur.X + dx[k];
                        int ny = cur.Y + dy[k];

                        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue; // 범위 벗어났을 때
                        if(board[nx][ny] == 0) continue; // 바다 부분
                        if(board[nx][ny] > 1) continue; // 이미 한 번 들린 곳일 경우

                        board[nx][ny] = islandT;
                        q.push({nx,ny});
                    }
                }

            }
        }
    }

    //최소 다리 길이 구하기
    for(int i = 0 ; i < n ;i++){
        for(int j = 0 ; j < n ; j++){
            if(board[i][j] > 1){ // 섬에서 시작
                vector<vector<int>> vis(n, vector<int>(n,-1));
                
                int itype = board[i][j];
                queue<pair<int,int>> q;
                q.push({i,j});
                vis[i][j] = 0;

                while(!q.empty()){
                    auto cur = q.front();
                    q.pop();

                    for(int k = 0 ; k < 4; k++){
                        int nx = cur.X + dx[k];
                        int ny = cur.Y + dy[k];

                        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue; // 범위 벗어났을 때
                        if(board[nx][ny] == itype) continue; // 자기 섬은 이동 못하도록
                        if(board[nx][ny] > 1 && board[nx][ny] != itype){ // 다른 섬에 닿았을 때
                            minV = min(minV, vis[cur.X][cur.Y]);
                            continue;
                        }
                        if(vis[nx][ny] >= 0) continue; // 이미 한 번 들린 곳일 경우

                        vis[nx][ny] = vis[cur.X][cur.Y]+1;
                        q.push({nx,ny});
                    }
                }
            }
        }
    }

    cout << minV << "\n";
    return 0;

}