#include <bits/stdc++.h>

using namespace std;

int c, l; // 케이스 개수, 변 길이
int curx, cury, movx, movy;

int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> c;

    while(c--){
        cin >> l;

        int dis[l][l];

        for(int i =0; i < l; i++){
            fill(dis[i], dis[i]+l,-1);
        }

        cin >> curx >> cury >> movx >> movy;

        queue<pair<int,int>> q;

        q.push({curx, cury});
        dis[curx][cury] = 0;

        while(dis[movx][movy] == -1){
            
            auto c = q.front();
            q.pop();

            for(int i = 0; i < 8; i++){
                int nx = c.first + dx[i];
                int ny = c.second + dy[i];

                if(nx < 0 || ny < 0 || nx >= l || ny >= l) continue; // 범위 밖의 상황일 때
                if(dis[nx][ny] != -1) continue; // -1이 아니면 한 번이라도 이동한 곳.

                dis[nx][ny] = dis[c.first][c.second] + 1;
                q.push({nx, ny});
            }
        }

        cout << dis[movx][movy] << "\n";

    }
    return 0;
}