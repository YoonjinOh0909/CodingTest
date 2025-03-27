#include <bits/stdc++.h>
using namespace std;

int n;
int board[2188][2188] = {0};
int cnt[3] = {0,};

bool checkPaper(int x, int y, int nn){
    int initVal = board[x][y];

    for(int i = x; i < x+ nn; i++){
        for(int j = y; j < y +nn; j++){
            if(initVal != board[i][j]){
                return false;
            }
        }
    }
    
    cnt[initVal+1]++;
    return true;
}

void rePaper(int x, int y, int nn){
    if(checkPaper(x,y,nn)){
        return;
    }

    int nextN = nn/3;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            rePaper(x + i*(nextN), y + j*(nextN), nextN);
        }    
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }    
    }

    rePaper(0,0,n);
    
    for(int c : cnt){
        cout << c << "\n";
    }

    return 0;
}