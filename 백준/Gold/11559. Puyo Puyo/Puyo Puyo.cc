#include <bits/stdc++.h>

using namespace std;

string board[12];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){
   

    for(int i = 0; i < 12; i++){
        cin >> board[i];
    }

    int chainCnt = 0;
    while(1){
        bool ischain =false;
        for(int i = 11; i >=0; i--){
            for(int j = 0; j < 6; j++){
                if(board[i][j] == '.') continue;
                char nowc = board[i][j];
                bool used[12][6];
                for(int k = 0; k < 12; k++){
                    fill(used[k], used[k]+6, 0);
                }
                queue<pair<int,int>> q;
                queue<pair<int,int>> confirm;

                q.push({i,j});
                confirm.push({i,j});

                used[i][j] = 1;
                int samecnt = 1;

                while(!q.empty()){
                    auto cur = q.front();
                    q.pop();

                    for(int index = 0 ; index < 4; index++){
                        int nx = cur.first + dx[index];
                        int ny = cur.second + dy[index];

                        if(nx < 0 || ny < 0 || nx >=12 || ny >= 6) continue;
                        if(board[nx][ny] != nowc || used[nx][ny]) continue;
                        used[nx][ny] = true;
                        samecnt++;

                        q.push({nx,ny});
                        confirm.push({nx,ny});
                    }
                }

                if(samecnt >= 4){ // 뭉쳐있는게 4이상이면.
                    ischain = true;
                    while(!confirm.empty()){
                        auto cur = confirm.front();
                        confirm.pop();
                        board[cur.first][cur.second] = '.';
                    }
                }
            }
        }

        for(int i = 0; i < 6; i++){
            int idx = 11;
            for(int j = 11; j >=0; j--){
                if(board[j][i] != '.'){
                    if(idx != j){
                        board[idx][i] = board[j][i];
                        board[j][i] = '.';
                    }
                    idx--;
                }
            }
        }
    
        if(!ischain){
            break;
        }else{
            chainCnt++;
        }
    }
    
    cout << chainCnt;
    
    return 0;
}