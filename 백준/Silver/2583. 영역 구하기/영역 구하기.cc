#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,cnt;
    cin >> n >> m >> cnt;
    int arr[m][n];

    for(int i = 0; i < m; i++){
        fill(arr[i],arr[i]+n,0);
    }

    while(cnt--){
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;

        for(int i = sx; i < ex; i++){
            for(int j = sy; j < ey; j++){
                arr[i][j] = -1;
            }
        }
    }
    
    vector<int> v;
    int totalcnt = 0;
    for(int i =0; i<m; i++){
        for(int j =0; j<n; j++){
            if(arr[i][j] != 0){ // 1이상일 경우 들린 곳, -1일 경우 벽, 0 일 경우에만 들리지 않은 곳
                continue;
            }

            queue<pair<int,int>> q;
            
            q.push({i,j});
            arr[i][j] = 1;
            totalcnt++;
            int maxv = 1;

            while(!q.empty()){
                auto cur = q.front();
                q.pop();

                for(int k = 0; k < 4; k++){
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];

                    if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue; // 범위 밖일 때
                    if(arr[nx][ny] != 0) continue; // 0이어야만 하는 공간 중 한 번도 안 간 곳.

                    arr[nx][ny] = arr[cur.first][cur.second]+1;
                    q.push({nx,ny});
                    maxv++;
                }
            }

            v.push_back(maxv);
        }   
    }

    sort(v.begin(), v.end());

    cout << totalcnt << "\n";
    for(auto c : v){
        cout << c << ' ';
    }
    return 0;
}