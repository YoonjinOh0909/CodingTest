#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int len[102][102] = {0, };
int n =0, m=0;
string board[102];

int main(void){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> board[i];
    }

    for(int i = 0; i < n; i++){
        //fill 사용 법 알아두세요.
        fill(len[i], len[i]+m, -1);
    }

    queue<pair<int,int>> Q;
    Q.push({0,0});
    len[0][0] = 0;

    while(!Q.empty()){
        pair<int, int> cur = Q.front();

        Q.pop();

        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(board[nx][ny] != '1' || len[nx][ny] >= 0) continue;

            Q.push({nx,ny});
            len[nx][ny] = len[cur.X][cur.Y]+1;
        }
    }
    

    cout << len[n-1][m-1] +1;
    return 0;
}