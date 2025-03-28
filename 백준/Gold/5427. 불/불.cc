#include <bits/stdc++.h>

using namespace std;

int n;
string board[1000];
int fire[1000][1000];
int human[1000][1000];

int w, h;

int dx[4] = {1, 0 , -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--){
        queue<pair<int, int>> qf;
        queue<pair<int, int>> qh;

        cin >> w >> h;
        for(int i = 0; i < h ; i++){
            fill(fire[i], fire[i]+w,-1);
            fill(human[i], human[i]+w,-1);
            cin >> board[i];
            int index = 0;
            for(char c : board[i]){
                if(c == '*'){ // fire
                    qf.push({i, index});
                    fire[i][index] = 0;
                }else if( c == '@'){ // human;
                    qh.push({i, index});
                    human[i][index] = 0 ;
                }
                index++;
            }
        }

        while(!qf.empty()){
            auto cur = qf.front();
            qf.pop();

            for(int i = 0 ; i < 4 ; i++){
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];

                if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
                if(board[nx][ny] == '#' || fire[nx][ny] != -1) continue;

                board[nx][ny] = '*';
                fire[nx][ny] = fire[cur.first][cur.second]+1;
                qf.push({nx, ny});
            }
        }
        bool canout = false;
        while(!qh.empty() && !canout){
            auto cur = qh.front();
            qh.pop();

            for(int i = 0 ; i < 4 ; i++){
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];

                if(nx < 0 || ny < 0 || nx >= h || ny >= w){ // 끝까지 나올 수 있다는 뜻
                    canout = true;
                    cout << human[cur.first][cur.second] + 1 << "\n";
                    break;
                } 
                if(board[nx][ny] == '#' || human[nx][ny] != -1) continue;
                // #이 벽이라서 이동하지 못한다. fire의 distance 보다 크거나 같다면 이미 불이 있어서 이동할 수 없는 곳.

                if(fire[nx][ny] != -1 && fire[nx][ny] <= human[cur.first][cur.second] + 1) continue;

                human[nx][ny] = human[cur.first][cur.second]+1;
                qh.push({nx, ny});
            }
        }
        if(!canout){
            cout << "IMPOSSIBLE\n";
        }

    }

    
    return 0;
}