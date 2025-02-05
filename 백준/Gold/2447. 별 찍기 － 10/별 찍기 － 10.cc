#include <bits/stdc++.h>

using namespace std;

int board[6600][6600] = {0,};

int func(int a, int b, int z){
    if(z == 3){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(j == 1 && i == 1) board[a+i][b+j] = 0;
                else board[a+i][b+j] = 1;
            }
        }
        return 0;
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(j != 1 || i != 1) func(a + z/3*i, b + z/3 *j, z/3);
            
        }
    }

    return 0;
}

int main(void){
    int width;

    cin >> width;
    func(0,0,width);

    for(int i = 0; i< width; i++){
        for(int j = 0; j< width; j++){
            if(board[i][j] == 1) cout << '*';
            else cout << ' ';
        }
        cout <<"\n";
    }
    return 0;
}