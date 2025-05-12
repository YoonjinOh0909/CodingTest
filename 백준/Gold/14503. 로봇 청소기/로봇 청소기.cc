#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int dir; // 방향

int board[52][52] = {0,};
bool vis[52][52] = {0,};

int n,m;

pair<int,int> st;

int sumv = 0;

int main(void){
    cin >> n >> m;
    cin >> st.X >> st.Y >> dir;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> board[i][j];
        }
    }

    while(1){
        auto cur = st;
        
        if(!vis[cur.X][cur.Y]){
            vis[cur.X][cur.Y] = true;
            sumv += 1;
        }

        bool notclean = false;


        for(int i = 1; i < 5; i++){
            int tempdir = (dir+ 4 - i) % 4;
            int nx = cur.X + dx[tempdir];
            int ny = cur.Y + dy[tempdir];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(board[nx][ny] == 1) continue;
            if(vis[nx][ny]) continue;
            
            dir = tempdir;
            notclean = true;
            
            st.X = nx;
            st.Y = ny;
            break;

        }
        if(!notclean){
            int nx = cur.X + dx[(dir+2)%4];
            int ny = cur.Y + dy[(dir+2)%4];

            st.X = nx;
            st.Y = ny;

            if(board[nx][ny] == 1){ // 벽이면
                break;
            }
        }
    }

    cout << sumv << "\n";

    return 0;
}