#include <bits/stdc++.h>

using namespace std;

bool board[102][102] = {0,};
int n,x,y,d,g;
vector<pair<int,int>> v;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

#define X first
#define Y second

int ans = 0;

int main(void){

    cin >> n;
    while(n--){
        cin >> x >> y >> d >> g;
        v.clear();

        //0세대 드래곤 커브
        v.push_back({x,y});
        v.push_back({x+dx[d], y+dy[d]});

        while(g--){
            int size = v.size();
            auto mid = v[size-1]; // 기준점
            for(int i = size-2; i >=0; i--){
                int dx = mid.X - v[i].X;
                int dy = mid.Y - v[i].Y;

                int cx = mid.X +dy;
                int cy = mid.Y - dx;

                if(cx < 0 || cy < 0 || cx > 100 || cy > 100) continue;
                v.push_back({cx,cy});
            }
        }

        for(auto c : v){
            board[c.X][c.Y] = true;
        }
    }

    for(int i = 0 ; i < 100 ; i++){
        for(int j = 0 ; j < 100 ; j++){
            if(board[i][j] && board[i][j+1] && board[i+1][j] && board[i+1][j+1])
                ans++;
        }    

    }

    cout << ans << "\n";
    return 0;
}