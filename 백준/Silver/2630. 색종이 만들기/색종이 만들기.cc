#include <bits/stdc++.h>

using namespace std;

int cnt[2] = {0,};
int board[130][130] = {0,};

bool check (int x, int y, int z){
    int val = board[x][y];
    for(int i =0; i < z ; i++){
        for(int j =0; j < z ; j++){
            if(val != board[i+x][j+y]) return false;
        }   
    }
    cnt[val] = cnt[val] + 1;
    return true;
}

int func1(int x, int y, int z){
    if(check(x,y,z)){
        return 0;
    }

    func1(x,y,z/2);
    func1(x + z/2,y,z/2);
    func1(x ,y + z/2, z/2);
    func1(x + z/2,y + z/2,z/2);

    return 0;
}

int main(void){
    int width;
    cin >> width;
    for(int i =0; i < width ; i++){
        for(int j =0; j < width ; j++){
            cin >> board[i][j];
        }   
    }

    func1(0,0,width);

    for(auto c : cnt){
        cout << c << '\n';
    }

    return 0;
}