#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int board[102][102] = {0,};
bool vis[102][102] = {0,};

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    int height = maps.size();
    int width = maps[0].length();
    
    for(int i = 0; i< height; i++){
        for(int j = 0; j < width; j++){
            if(maps[i][j] == 'X'){
                board[i][j] = 0;
            }else{
                board[i][j] = maps[i][j] - '0';
            }
        }
    }
    
    queue<pair<int,int>> q;
    
    for(int i = 0; i< height; i++){
        for(int j = 0; j < width; j++){
            if(board[i][j] > 0 && !vis[i][j]){
                int sol = 0;
                q.push({i,j});
                vis[i][j] = 1;
                
                while(!q.empty()){
                    
                    auto cur = q.front();
                    sol += board[cur.X][cur.Y];
                    q.pop();
                    
                    for(int k = 0; k < 4; k++){
                        int nx = dx[k] + cur.X;
                        int ny = dy[k] + cur.Y;
                        
                        if(nx < 0 || ny < 0 || nx >= height || ny >= width) continue; // 범위 벗어났을 때
                        if(board[nx][ny] <= 0 || vis[nx][ny]) continue; // 바다일 때 or 먼저 방문했을 때
                        
                        vis[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
                answer.push_back(sol);
            }
        }
    }
    
    if(answer.size() == 0) answer.push_back(-1);
    sort(answer.begin(), answer.end());
    return answer;
}