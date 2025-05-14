#include <bits/stdc++.h>

using namespace std;

int n, m, h; // 문제와 다르게 변수 사용
bool board[32][12] = {0,};
int ans = 4;
bool correctState(){
    int curindex = 0;
    for(int i = 1; i <= m; i++){
        curindex = i;
        for(int j = 1; j <= n ; j++){
            if(board[j][curindex]) curindex += 1;
            else if(board[j][curindex-1]) curindex += -1;
        }
        if(curindex != i){
            return false;
        } 
    }

    return true;
}


void dfs(int ind, int cnt){
    if(cnt >= 4) return;

    if(correctState()){
        ans = min(ans, cnt);
        return;
    }
    // for(int i = ind; i <= n; i++){
    //     for(int j = 1; j < m; j++){
    //         if(board[i][j] || board[i][j-1] || board[i][j+1]) continue;

    //         board[i][j] = true;
    //         dfs(j ,cnt +1 );
    //         board[i][j] = false;
    //     }
    // }
    for(int i = ind; i < m; i++){
        for(int j = 1; j <= n; j++){
            if(board[j][i] || board[j][i-1] || board[j][i+1]) continue;

            board[j][i] = true;
            dfs(i ,cnt +1 );
            board[j][i] = false;
        }
    }
}

int main(void){

    cin >> m >> h >> n;
    int x,y;
    for(int i = 0 ; i < h; i++){
        cin >> x >> y;
        board[x][y] = true;
    }

    dfs(1,0);

    if(ans == 4) ans = -1;

    cout << ans << "\n";
    return 0;
}