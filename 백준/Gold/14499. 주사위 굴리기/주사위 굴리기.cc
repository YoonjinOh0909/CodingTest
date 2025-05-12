#include <bits/stdc++.h>

using namespace std;

int diceboard[6] = {0,};
/*
      1 
    5 2 6
      3 
      4 

    2가 윗면, 4가 아랫면.
*/

int board[21][21] = {0,};
int n,m,x,y,k;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void moveDice(int tind){ // 동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4로
    int temp[6];

    for(int i =0; i < 6; i++){
        temp[i] = diceboard[i];
    }

    if(tind == 1){
        diceboard[1] = temp[4];
        diceboard[5] = temp[1];
        diceboard[4] = temp[3];
        diceboard[3] = temp[5];
    }else if(tind == 2){
        diceboard[4] = temp[1];
        diceboard[3] = temp[4];
        diceboard[5] = temp[3];
        diceboard[1] = temp[5];
    }
    else if(tind == 3){
        diceboard[0] = temp[1];
        diceboard[1] = temp[2];
        diceboard[2] = temp[3];
        diceboard[3] = temp[0];
    }
    else if(tind == 4){
        diceboard[0] = temp[3];
        diceboard[1] = temp[0];
        diceboard[2] = temp[1];
        diceboard[3] = temp[2];
    }

}

int main(void){
    cin >> n >> m >> x >> y >> k;
    
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < m; j++){
            cin >> board[i][j];
        }
    }

    while(k--){
        int val;
        cin >> val;
        int curx = x + dx[val-1];
        int cury = y + dy[val-1];

        if(curx < 0 || curx >= n || cury < 0 || cury >= m) continue; //만약 범위를 벗어나면 무시한다.

        // 만약 아니라면 주사위를 이동한다.
        x = curx;
        y = cury;

        moveDice(val); // 움직였을 때 주사위의 상태를 표현.

        if(board[x][y] == 0){ // 만약 지도 칸에 0 이면 주사위 바닥면에 있는 것을 복사한다.
            board[x][y] = diceboard[3];
        }else{ // 만약 0이 아니라면
            diceboard[3] = board[x][y];
            board[x][y] = 0;
        }
        cout << diceboard[1] << "\n";
    }
    return 0;
}