#include <bits/stdc++.h>

using namespace std;

int n;
int board[101][101] = {0,};


int maxH = 0;
int minH = 101;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int maxCnt = 1; // 비간 최소 높이보다 적게 왔을 경우 안전지대는 1개이다.

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i =0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
            maxH = max(board[i][j], maxH);
            minH = min(board[i][j], minH);
        }
    }

    for(int rain = minH; rain < maxH; rain++){ // 만약 최대 높이까지 확인하면 안전 지대가 0으로 된다.
        bool checkB[101][101] = {0,};
        queue<pair<int,int>> q;
        int cnt=0;
        for(int i =0; i < n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] > rain && !checkB[i][j]){
                    q.push({i,j});
                    checkB[i][j] = true;

                    while(!q.empty()){
                        auto cur = q.front();
                        q.pop();

                        for(int k =0; k < 4;k++){
                            int nx =cur.first + dx[k];
                            int ny = cur.second + dy[k];

                            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue; // 범위 벗어났을 때
                            if(checkB[nx][ny]) continue; //이미 들렸을 때
                            if(board[nx][ny] <= rain) continue; // 물에 잠겨 안전지대가 아닐 때
                            
                            q.push({nx,ny});
                            checkB[nx][ny] = true;
                        }
                    }

                    cnt++;
                }
            }
        }
        maxCnt = max(maxCnt, cnt);
    }

    cout << maxCnt << "\n";
    return 0;
}