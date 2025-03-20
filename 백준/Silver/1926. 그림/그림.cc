#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int board[501][501] = {0,};
bool vis[501][501] = {0,};

int num, maxv = 0;
int n,m;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i =0; i < n; i++){
        for(int j=0; j <m; j++){
            cin >> board[i][j];
        }
    }

    for(int i =0; i < n; i++){
        for(int j=0; j <m; j++){
            //하나씩 빈 곳을 확인하면서 이동할 예정.
            if(board[i][j] == 0 || vis[i][j]) continue; // 벽이거나 먼저 방문했던 곳이면 넘어간다.

            num++; // 만약 위 코드에 의해서 continue가 되지 않았다면 새로운 영역을 발견한 것이라 보면 됨.
            queue<pair<int,int>> q; // 시작점을 넣을 queue 초기화.
            vis[i][j] = true;
            q.push({i,j});
            int area = 0;
            
            while(!q.empty()){
                pair<int,int> cur = q.front();
                q.pop();
                area++; // 해당 타일부터 체크를 하니깐 그 부분을 area+1 해주면 된다?
                for(int k =0; k < 4; k++){
                    int curX = cur.first + dx[k];
                    int curY = cur.second + dy[k];
                    if(curX >= n || curY >= m || curX < 0 || curY < 0){
                        continue; // 범위를 벗어났을 때
                    }
                    if(board[curX][curY] == 0 || vis[curX][curY]){
                        continue; // 벽이거나 미리 방문했을 때
                    }
                    
                    q.push({curX, curY}); // 다음에 들릴 곳 체크
                    vis[curX][curY] = true;
                    
                }
            }

            maxv = max(maxv, area);
        }
    }

    cout << num << "\n";
    cout << maxv << "\n";

    return 0;
}