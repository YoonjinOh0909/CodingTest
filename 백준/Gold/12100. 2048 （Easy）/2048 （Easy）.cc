#include <bits/stdc++.h>

using namespace std;

int width = 0;
int board[22][22] = {0,};
int board2[22][22] = {0,};

int maxVal = 0;
void Rotate(){
    int tmpb[22][22] = {0,};

    for(int x = 0 ; x < width ; x++){
        for(int y = 0 ; y < width ; y++){
            tmpb[x][y] = board2[x][y];
        }   
    }

    for(int x = 0 ; x < width ; x++){
        for(int y = 0 ; y < width ; y++){
            board2[x][y] = tmpb[width - 1 - y][x];
        }   
    }
}

void tilted(int dir){
    dir %= 4;
    while(dir--) Rotate();

    for(int z = 0; z < width ; z++){
        int tmp[22]  ={0,};
        bool merged[22] = {0,};
        int idx = 0;
        for(int i = 0; i < width ; i++){
            if(board2[z][i] == 0) continue;
            // if(tmp[idx] == 0){
            //     tmp[idx] = board2[z][i];
            // }
            // else if(tmp[idx] == board[z][i]){
            //     tmp[idx] *= 2;
            //     idx++;
            // }else if(tmp[idx] != board[z][i]){
            //     idx++;
            //     tmp[idx] = board[z][i];
            // }
            if(idx == 0){
                tmp[idx] = board2[z][i];
                idx++;
            }
            else if (tmp[idx-1] == board2[z][i]){ //이전것과 현재가 같다면
                if(merged[idx-1]){ //이미 합쳐진 것이라면
                    tmp[idx] = board2[z][i];
                    idx++;
                }else{ // 합쳐진게 아니라면
                    
                    tmp[idx-1] *= 2;
                    // cout << " \n합침" << tmp[idx-1] <<"\n";
                    merged[idx-1] = true;
                }
            }else if (tmp[idx-1] != board2[z][i]){ //이전것과 현재가 다르다면
                tmp[idx] = board2[z][i];
                idx++;
            }
            
        }

        for(int i =0 ; i < width ; i++){
            board2[z][i] = tmp[i]; //다시 복사해준다.
        }
    }
    
}

int main(void){
    cin >> width;

    for(int i = 0; i < width; i++){
        for(int j = 0; j < width; j++){
            cin >> board[i][j];
        }   
    }

    for(int i = 0; i < (1 << 2*5); i++){ // 방향이 4개 이고 최대 5번이기 때문에.
        int temp = i;

        for(int x = 0 ; x < width ; x++){
            for(int y = 0 ; y < width ; y++){
                board2[x][y] = board[x][y];
            }   
        }

        for(int j = 0; j < 5; j++){
            int dir = temp%4;
            temp /= 4;

            tilted(dir);
        }

        for(int x = 0 ; x < width ; x++){
            for(int y = 0 ; y < width ; y++){
                maxVal = max(maxVal, board2[x][y]);
            }   
        }
    }

    cout << maxVal;
    return 0;
}