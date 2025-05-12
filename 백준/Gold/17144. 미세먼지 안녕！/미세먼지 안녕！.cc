#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

vector<vector<int>> board;
vector<pair<int,int>> air;
int n,m,t;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){
    cin >> n >> m >> t;

    board = vector<vector<int>>(n, vector<int>(m,0));

    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] == -1){
                air.push_back({i,j});
            }
        }
    }

    while(t--){
        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0 ; j < m; j++){
                if(board[i][j] != -1 || board[i][j] != 0){
                    q.push({i,j});
                }
            }
        }

        vector<vector<int>> tempboard(n, vector<int>(m,0));

        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            int spread = board[cur.X][cur.Y] / 5;
            for(int i = 0 ; i < 4; i++){
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];

                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if(board[nx][ny] == -1) continue;

                board[cur.X][cur.Y] -= spread;
                tempboard[nx][ny] += spread;
            }

        }

        for(int i = 0; i < n; i++){
            for(int j = 0 ; j < m; j++){
                board[i][j] += tempboard[i][j];
            }
        }

        //  cout << "----\n";
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         cout << board[i][j] << ' ';
        //     }
        //     cout << "\n";
        // }
        
        //위쪽
        for(int i = air[0].X-1; i > 0; i--){
            board[i][0] = board[i-1][0];
        }

        for(int j = 0; j < m-1; j++){
            board[0][j] = board[0][j+1];
        }

        for(int i = 0; i < air[0].X ; i++){
            board[i][m-1] = board[i+1][m-1];
        }

        for(int j = m-1; j > 1; j--){
            board[air[0].X][j] = board[air[0].X][j-1];
        }

        board[air[0].X][1] = 0;

        //아래쪽
        for(int i = air[1].X+1; i < n-1; i++){
            board[i][0] = board[i+1][0];
        }

        for(int j = 0; j < m-1; j++){
            board[n-1][j] = board[n-1][j+1];
        }

        for(int i = n-1; i > air[1].X ; i--){
            board[i][m-1] = board[i-1][m-1];
        }

        for(int j = m-1; j > 1; j--){
            board[air[1].X][j] = board[air[1].X][j-1];
        }

        board[air[1].X][1] = 0;
    }

    int sum = 0;

    // cout << "----\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            // cout << board[i][j] << ' ';
            if(board[i][j] != -1) sum += board[i][j];
        }
        // cout << "\n";
    }

    cout << sum <<"\n";
    return 0;
}