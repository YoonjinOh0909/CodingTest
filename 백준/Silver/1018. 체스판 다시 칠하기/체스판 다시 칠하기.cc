#include <bits/stdc++.h>

using namespace std;

int n,m;
string board[51];
char wb[2]  {'W', 'B'};
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i< n ; i++){
        cin >> board[i];
        
    }
    int minv = 0x7f7f7f7f;
    for(int i = 0; i< n ; i++){
        if(i + 8 > n) break; // 만약 시작점 기준 세로 8칸이 안나오면 
        for(int j = 0; j< m ; j++){
            if(j + 8 > m) break; // 만약 시작점 기준 가로 8칸이 안나오면

            for(auto c : wb){ //wb에는 W,B가 있음 자른 판 기준 (0,0)을 c 라고 하자.
                int changcnt = 0;
                for(int nx = i; nx < i+8; nx++){
                    for(int ny = j; ny < j+8; ny++){
                        if((nx+ny) % 2 == 0 && board[nx][ny] != c) changcnt++;
                        if((nx+ny) % 2 == 1 && board[nx][ny] == c) changcnt++;
                    }
                    if(changcnt > minv) break;
                }
                minv = min(minv, changcnt);
            }
        }
    }

    cout << minv;
    return 0;
}