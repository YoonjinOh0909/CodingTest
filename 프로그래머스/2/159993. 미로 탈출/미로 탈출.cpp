#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int board[102][102] = {0,};
int vis[102][102] = {0,};

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

pair<int,int> s;
pair<int,int> l;
pair<int,int> e;

int solution(vector<string> maps) {
    int answer = 0;
    
    int n = maps.size();
    int m = maps[0].length();
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < m; j++){
            if(maps[i][j] == 'S'){
                s = {i,j};
            }else if(maps[i][j] == 'L'){
                l = {i,j};
            }else if(maps[i][j] == 'E'){
                e = {i,j};
            }
            
            if(maps[i][j] != 'X'){
                board[i][j] = 1;
            }
            
        }
    }
    
    queue<pair<int,int>> q;
    q.push(s);

    while(!q.empty()){
        if(vis[l.X][l.Y]){
            break;  
        } 
        auto cur = q.front();
        q.pop();
        
        for(int i = 0; i<4; i++){
            int nx = dx[i] + cur.X;
            int ny = dy[i] + cur.Y;
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(board[nx][ny] == 0 || vis[nx][ny] > 0) continue;
            
            vis[nx][ny] = vis[cur.X][cur.Y] +1;
            q.push({nx,ny});
        }
    }

    
    
    int s_l = vis[l.X][l.Y];
    if(s_l == 0){
        return -1;  
    } 
    
    for(int i = 0 ; i < n; i++){
        fill(vis[i], vis[i]+m,0);
    }
    
    queue<pair<int,int>> qe;
    qe.push(l);
    
    while(!qe.empty()){
        if(vis[e.X][e.Y] != 0) break;
        auto cur = qe.front();
        qe.pop();
        
        for(int i = 0; i<4; i++){
            int nx = dx[i] + cur.X;
            int ny = dy[i] + cur.Y;
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(board[nx][ny] == 0 || vis[nx][ny] > 0) continue;
            
            vis[nx][ny] = vis[cur.X][cur.Y] +1;
            qe.push({nx,ny});
        }
    }
    
    if(vis[e.X][e.Y] == 0){
        return -1;
    } 
    answer = s_l + vis[e.X][e.Y];
    
    return answer;
}