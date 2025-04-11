#include <bits/stdc++.h>

using namespace std;

int n,m;
string board[1000];
int checkBoard[1000][1000][2] = {0,};
queue<tuple<int,int,int>> q;

int dx[4] = {1,0,-1,0};
int dy[4] = {0, 1, 0,-1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0 ; i < n; i++){
        cin >> board[i];
    }

    

    q.push({0,0,0}); // 시작점은 무조건 0이라는 문제의 조건
    checkBoard[0][0][0] = 1;
    checkBoard[0][0][1] = 1;
    
    while(!q.empty()){
        int cx, cy, cbw;
        tie(cx,cy,cbw) = q.front();
        q.pop();

        for(int i = 0; i< 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            int nbw = cbw;

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue; // 범위 벗어났을 때 
            if(nbw == 0 && board[nx][ny] == '1' && checkBoard[nx][ny][1] == 0){ // 현재 벽을 만났을 때
                checkBoard[nx][ny][1] = checkBoard[cx][cy][0]+1;
                q.push({nx,ny,nbw+1});
            }
            if(checkBoard[nx][ny][nbw] == 0 && board[nx][ny] == '0'){
                checkBoard[nx][ny][nbw] = checkBoard[cx][cy][cbw]+1;
                q.push({nx,ny,nbw});
            }
        }
    }


    if(checkBoard[n-1][m-1][0] == 0 && checkBoard[n-1][m-1][1] == 0){
        cout << -1 << "\n";
    }else if(checkBoard[n-1][m-1][0] != 0 && checkBoard[n-1][m-1][1] != 0){
        cout << min(checkBoard[n-1][m-1][0], checkBoard[n-1][m-1][1]) << "\n";
    }else{
        cout << max(checkBoard[n-1][m-1][0], checkBoard[n-1][m-1][1]) << "\n";
    }

    return 0;
}