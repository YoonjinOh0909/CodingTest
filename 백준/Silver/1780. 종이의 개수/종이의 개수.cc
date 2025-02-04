#include <bits/stdc++.h>

using namespace std;
int width;
int board[2200][2200] = {0,};
int cnt[3] = {0,};

bool check(int nxS, int nxE, int nyS, int nyE){
    // cout << "nxS " << nxS << " nyS " << nyS << "\n";
    int val = board[nxS][nyS];

    for(int i = nxS; i < nxE; i++){
        for(int j = nyS; j < nyE; j++){
            if(val != board[i][j]) return false;
        }   
    }

    cnt[val+1] = cnt[val+1] +1;
    return true;
}

int func1(int nxS, int nxE, int nyS, int nyE){
    
    if(check(nxS, nxE, nyS, nyE)){
        
        return 0 ;
    }

    int wid = nyE - nyS;

    for(int k =0; k < 3; k++){
        for(int j = 0; j < 3; j++){
            func1(nxS + wid*k/3, nxS + wid*(k+1)/3, nyS + wid*j/3, nyS + wid*(j+1)/3);
        }
    }

    return 0;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> width;

    for(int i = 0; i < width; i++){
        for(int j = 0; j < width; j++){
            cin >> board[i][j];
        }
    }

    func1(0, width, 0, width);

    for(auto c : cnt){
        cout << c << "\n";
    }
    return 0;
}