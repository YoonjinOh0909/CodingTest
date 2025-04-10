#include <bits/stdc++.h>

using namespace std;

int n;
string board[25];
bool checkBoard[25][25] = {0,};
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

#define X first
#define Y second

vector<int> v;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0 ; i< n; i++){
        cin >> board[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j]-'0' == 1 && !checkBoard[i][j]){ //아직 안들린 곳 중 1인 칸일 때
                queue<pair<int,int>> q;
                checkBoard[i][j] = true;
                q.push({i,j});
                int cnt = 1;

                while(!q.empty()){
                    auto cur = q.front();
                    q.pop();
                    for(int ind = 0; ind < 4; ind++){    
                        int nx = cur.X + dx[ind];
                        int ny = cur.Y + dy[ind];
    
                        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue; // 범위를 벗어났을 때
                        if(checkBoard[nx][ny]) continue; // 이전에 들린 곳일 때
                        if(board[nx][ny] == '0') continue; // 집이 없는 곳일 때
                        cnt++;
                        checkBoard[nx][ny] = true;
                        q.push({nx,ny});
                    }
                }

                v.push_back(cnt);
                
            }
        }
    }

    sort(v.begin(), v.end());

    cout << v.size() << "\n";
    for(auto c : v){
        cout << c << "\n";
    }

    return 0;
}