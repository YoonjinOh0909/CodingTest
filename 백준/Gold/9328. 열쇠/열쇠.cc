#include <bits/stdc++.h>

using namespace std;

char board[102][102];
bool vis[102][102] = {0,};

int testc;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

#define X first
#define Y second

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> testc;
    int h,w;
    while(testc--){
        int ans = 0;
        cin >> h >> w;
        
        for(int i = 0; i < h+2; i++){
            fill(vis[i], vis[i]+w+2,0);
            fill(board[i], board[i]+w+2,'.');
        }

        queue<pair<int,int>> doorq[26];

        for(int i = 1; i <= h; i++){
            for(int j = 1; j <= w; j++){
                cin >> board[i][j];
                if(isalpha(board[i][j])){
                    int alphaI = board[i][j] - 'a';
                    if(alphaI < 0){ // 소문자 0 ~ 25, 대문자 -32 ~ -7
                        doorq[alphaI+32].push({i,j});
                    }
                }
            }
        }

        string keys;
        cin >> keys;
        if(keys != "0" ){
            for(auto c : keys){
                int valc = c -'a';
                while(!doorq[valc].empty()){
                    auto cur = doorq[valc].front();
                    doorq[valc].pop();

                    board[cur.X][cur.Y] = '.'; //문을 다 열어둔다.
                }
            }
        }
        

        queue<pair<int,int>> q;

        for(int i = 0; i < h+2; i++){
            for(int j = 0 ; j < w+2; j++){
                if(vis[i][j]) continue;

                if(i ==0 || i == h+1 || j == 0 || j == w+1){ //테두리에서만 시작 가능.
                    q.push({i,j});
                    vis[i][j] = true;

                    while(!q.empty()){
                        auto cur = q.front();
                        q.pop();

                        for(int k = 0; k < 4; k++){
                            int nx = cur.X + dx[k];
                            int ny = cur.Y + dy[k];

                            if(nx < 0 || ny < 0 || nx > h+1 || ny > w+1) continue; // 범위 벗어나면
                            if(vis[nx][ny]) continue; // 이미 들린 곳이라면
                            if(board[nx][ny] == '*') continue; //벽이라면
                            if(isalpha(board[nx][ny]) && (board[nx][ny] - 'a' < 0)) continue; // 대문자(문)이라면
                            if(board[nx][ny] == '$'){ // 달러(문서)라면
                                ans++;
                            }
                            if(isalpha(board[nx][ny])){ // 소문자(key)라면
                                int keyv = board[nx][ny] - 'a';

                                while(!doorq[keyv].empty()){
                                    auto doorc = doorq[keyv].front();
                                    doorq[keyv].pop();

                                    bool cango = false;

                                    for(int f = 0; f < 4; f++){
                                        int dnx = doorc.X + dx[f];
                                        int dny = doorc.Y + dy[f];

                                        if(vis[dnx][dny]) cango = true;
                                    }

                                    if(cango){ // 주변에 접근했던 적이 있다면
                                        q.push({doorc.X, doorc.Y});
                                        board[doorc.X][doorc.Y] = '.'; //열어만 둔다.
                                        vis[doorc.X][doorc.Y] = true;
                                    }else{ // 주변에 접근한 적이 없다면
                                        board[doorc.X][doorc.Y] = '.'; //열어만 둔다.
                                    }
                                }
                            } 

                            q.push({nx,ny});
                            vis[nx][ny] =true;

                            
                        }
                    }
                    
                }
            }
        }
        cout << ans << "\n";

    }

    return 0;
}