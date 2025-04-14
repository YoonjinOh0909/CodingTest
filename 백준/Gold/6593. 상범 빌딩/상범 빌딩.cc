#include <bits/stdc++.h>

using namespace std;

//북, 동, 남, 서, 하, 상
int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,-1,1};



tuple<int, int, int> startT;
tuple<int, int, int> endT;



int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int L, R, C = 0;

    while(1){
        cin >> L >> R >> C;
        if(L == 0) break;
        bool checkStart, checkEnd = false;
        queue<tuple<int,int,int>> qt;
        char board[31][31][31];
        int checkB[31][31][31] = {0,};
        bool isEscape = false;

        for(int h = 0; h < L; h++){
            for(int i = 0; i < R; i++){
                fill(checkB[h][i], checkB[h][i]+C, -1);
            }
        }

        for(int h =0; h < L; h++){
            for(int i = 0; i< R; i++){
                for (int j = 0 ; j < C;j++){
                    cin >> board[h][i][j];

                    if(board[h][i][j] == 'S'){
                        qt.push({h,i,j});
                        checkB[h][i][j] =  0;
                    }
                }
            }
        }
      
        while(!qt.empty()){
            int cx,cy,cz = 0;
            auto cur = qt.front();
            tie(cz,cx,cy) = cur;
            qt.pop();
            if(board[cz][cx][cy] == 'E'){
                isEscape = true;
                cout << "Escaped in " << checkB[cz][cx][cy] <<" minute(s).\n";
                break;
            }  
            
            for(int i=0; i < 6; i++){
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                int nz = cz + dz[i];

                if(nx < 0 || ny < 0|| nz < 0 || nx >= R || ny >= C || nz >=L) continue; // 범위 벗어났을 때
                if(board[nz][nx][ny] == '#') continue; // 벽일 때
                if(checkB[nz][nx][ny] != -1) continue; // 이미 들린 곳일 때

                checkB[nz][nx][ny] = checkB[cz][cx][cy] + 1;
                qt.push({nz,nx,ny});
            }
        }


        if(!isEscape){
            cout << "Trapped!\n";
        }
    }

    
    return 0; 
}