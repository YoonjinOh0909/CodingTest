#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int n =0, m = 0;
int board[502][502] = {0,};
bool vis[502][502];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int maxV = 0;
int cnt = 0;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i =0 ; i < n; i++){
        for(int d = 0; d < m; d++){
            cin >> board[i][d];
        }
    }

    for(int i =0 ; i < n; i++){
        for(int d = 0; d < m; d++){
            if(board[i][d] == 1 && !vis[i][d]){ // 1로 그려져있고, 아직 방문하지 않은 곳이라면.
                cnt++;
                queue<pair<int,int>> Q;

                Q.push({i,d});
                vis[i][d] = 1; // 시작 점을 잡아주는 것.
                int val = 0; // val은 넓이로 pop 될 때 ++ 해주면 연결된 넓이가 어느정도 되는지 확인 가능.

                while(!Q.empty()){
                    pair<int,int> cur = Q.front();

                    Q.pop();

                    val++;

                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        if(board[nx][ny] != 1 || vis[nx][ny]) continue;

                        Q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }

                
                if(maxV < val) maxV = val;
                   

            }
        }
    }

    cout << cnt << "\n" << maxV;
    return 0;
}