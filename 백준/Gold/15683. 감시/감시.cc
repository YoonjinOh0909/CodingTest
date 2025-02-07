#include <bits/stdc++.h>

using namespace std;

int N, M;
int board[9][9] = {0,};
int cctvCnt;
int minC = 101;
int func(int x, int y, int cnt, int temp[][9]){
    if(cnt == cctvCnt){
        int noCnt= 0;
        for(int i = 0 ; i < N; i++){
            for(int j = 0 ; j < M; j++){
                if(temp[i][j] == 0 ){
                    noCnt++;
                }
            }
        }
        // cout << "minc " << minC << " noCnt " << noCnt << "\n";
        minC = minC < noCnt ? minC : noCnt;

        
        // if(minC == noCnt){
        //     cout << "-----------\n";
        //     for(int i = 0 ; i < N; i++){
        //         for(int j = 0 ; j < M; j++){
        //             cout << temp[i][j] << ' ';
        //         }
        //         cout << "\n";
        //     }   
        //     cout << "-----------\n";
        // }
        return 0;
    }

    

    for(int i = 0 ; i < N; i++){
        if(i < x) continue;
        for(int j = 0 ; j < M; j++){
            if(i == x && j <= y) continue;
            if(temp[i][j] == 1){
                //좌
                int nextTemp1[9][9] = {0,};
                for(int ia = 0 ; ia < N; ia++){
                    for(int ja = 0 ; ja < M; ja++){
                        nextTemp1[ia][ja] = temp[ia][ja];
                    }
                }
                
                
                for(int k = j-1; k >= 0; k--){
                    if(nextTemp1[i][k] == 6) break;
                    if(nextTemp1[i][k] == 0) nextTemp1[i][k] = 7;
                } 

                func(i, j, cnt+1, nextTemp1);

                //우
                int nextTemp2[9][9] = {0,};
                for(int ia = 0 ; ia < N; ia++){
                    for(int ja = 0 ; ja < M; ja++){
                        nextTemp2[ia][ja] = temp[ia][ja];
                    }
                }
                
                
                for(int k = j+1; k < M; k++){
                    if(nextTemp2[i][k] == 6) break;
                    if(nextTemp2[i][k] == 0) nextTemp2[i][k] = 7;
                } 

                func(i, j, cnt+1, nextTemp2);

                //상
                int nextTemp3[9][9] = {0,};
                for(int ia = 0 ; ia < N; ia++){
                    for(int ja = 0 ; ja < M; ja++){
                        nextTemp3[ia][ja] = temp[ia][ja];
                    }
                }
                
                
                for(int k = i-1; k >= 0; k--){
                    if(nextTemp3[k][j] == 6) break;
                    if(nextTemp3[k][j] == 0) nextTemp3[k][j] = 7;
                } 

                func(i, j, cnt+1, nextTemp3);

                //하
                int nextTemp4[9][9] = {0,};
                for(int ia = 0 ; ia < N; ia++){
                    for(int ja = 0 ; ja < M; ja++){
                        nextTemp4[ia][ja] = temp[ia][ja];
                    }
                }
                
                
                for(int k = i+1; k < N; k++){
                    if(nextTemp4[k][j] == 6) break;
                    if(nextTemp4[k][j] == 0) nextTemp4[k][j] = 7;
                } 

                func(i, j, cnt+1, nextTemp4);

            }
            if(temp[i][j] == 2){
                //좌 우
                int nextTemp1[9][9] = {0,};
                for(int ia = 0 ; ia < N; ia++){
                    for(int ja = 0 ; ja < M; ja++){
                        nextTemp1[ia][ja] = temp[ia][ja];
                    }
                }
                
                
                for(int k = j-1; k >= 0; k--){
                    if(nextTemp1[i][k] == 6) break;
                    if(nextTemp1[i][k] == 0) nextTemp1[i][k] = 7;
                } 
                
                for(int k = j+1; k < M; k++){
                    if(nextTemp1[i][k] == 6) break;
                    if(nextTemp1[i][k] == 0) nextTemp1[i][k] = 7;
                } 

                func(i, j, cnt+1, nextTemp1);

                //상 하
                int nextTemp3[9][9] = {0,};
                for(int ia = 0 ; ia < N; ia++){
                    for(int ja = 0 ; ja < M; ja++){
                        nextTemp3[ia][ja] = temp[ia][ja];
                    }
                }
                
                
                for(int k = i-1; k >= 0; k--){
                    if(nextTemp3[k][j] == 6) break;
                    if(nextTemp3[k][j] == 0) nextTemp3[k][j] = 7;
                } 
               
                
                for(int k = i+1; k < N; k++){
                    if(nextTemp3[k][j] == 6) break;
                    if(nextTemp3[k][j] == 0) nextTemp3[k][j] = 7;
                } 

                func(i, j, cnt+1, nextTemp3);

            }
            if(temp[i][j] == 3){
                //상우
                int nextTemp1[9][9] = {0,};
                for(int ia = 0 ; ia < N; ia++){
                    for(int ja = 0 ; ja < M; ja++){
                        nextTemp1[ia][ja] = temp[ia][ja];
                    }
                }
                
               
                //우
                for(int k = j+1; k < M; k++){
                    if(nextTemp1[i][k] == 6) break;
                    if(nextTemp1[i][k] == 0) nextTemp1[i][k] = 7;
                }
                //상
                for(int k = i-1; k >= 0; k--){
                    if(nextTemp1[k][j] == 6) break;
                    if(nextTemp1[k][j] == 0) nextTemp1[k][j] = 7;
                } 

                func(i, j, cnt+1, nextTemp1);

                //우하
                int nextTemp2[9][9] = {0,};
                for(int ia = 0 ; ia < N; ia++){
                    for(int ja = 0 ; ja < M; ja++){
                        nextTemp2[ia][ja] = temp[ia][ja];
                    }
                }
                
                //우
                for(int k = j+1; k < M; k++){
                    if(nextTemp2[i][k] == 6) break;
                    if(nextTemp2[i][k] == 0) nextTemp2[i][k] = 7;
                } 
                //하
                for(int k = i+1; k < N; k++){
                    if(nextTemp2[k][j] == 6) break;
                    if(nextTemp2[k][j] == 0) nextTemp2[k][j] = 7;
                }  

                func(i, j, cnt+1, nextTemp2);

                //하좌
                int nextTemp3[9][9] = {0,};
                for(int ia = 0 ; ia < N; ia++){
                    for(int ja = 0 ; ja < M; ja++){
                        nextTemp3[ia][ja] = temp[ia][ja];
                    }
                }
                
                
                //좌
                for(int k = j-1; k >= 0; k--){
                    if(nextTemp3[i][k] == 6) break;
                    if(nextTemp3[i][k] == 0) nextTemp3[i][k] = 7;
                } 
 
                //하
                for(int k = i+1; k < N; k++){
                    if(nextTemp3[k][j] == 6) break;
                    if(nextTemp3[k][j] == 0) nextTemp3[k][j] = 7;
                }  

                func(i, j, cnt+1, nextTemp3);

                //좌상
                int nextTemp4[9][9] = {0,};
                for(int ia = 0 ; ia < N; ia++){
                    for(int ja = 0 ; ja < M; ja++){
                        nextTemp4[ia][ja] = temp[ia][ja];
                    }
                }
                
                
                //좌
                for(int k = j-1; k >= 0; k--){
                    if(nextTemp4[i][k] == 6) break;
                    if(nextTemp4[i][k] == 0) nextTemp4[i][k] = 7;
                } 
                //상
                for(int k = i-1; k >= 0; k--){
                    if(nextTemp4[k][j] == 6) break;
                    if(nextTemp4[k][j] == 0) nextTemp4[k][j] = 7;
                }   

                func(i, j, cnt+1, nextTemp4);

            }
            if(temp[i][j] == 4){
                //좌상우
                int nextTemp1[9][9] = {0,};
                for(int ia = 0 ; ia < N; ia++){
                    for(int ja = 0 ; ja < M; ja++){
                        nextTemp1[ia][ja] = temp[ia][ja];
                    }
                }
                
                
                 //좌
                for(int k = j-1; k >= 0; k--){
                    if(nextTemp1[i][k] == 6) break;
                    if(nextTemp1[i][k] == 0) nextTemp1[i][k] = 7;
                } 
                //우
                for(int k = j+1; k < M; k++){
                    if(nextTemp1[i][k] == 6) break;
                    if(nextTemp1[i][k] == 0) nextTemp1[i][k] = 7;
                }
                //상
                for(int k = i-1; k >= 0; k--){
                    if(nextTemp1[k][j] == 6) break;
                    if(nextTemp1[k][j] == 0) nextTemp1[k][j] = 7;
                } 
                  

                func(i, j, cnt+1, nextTemp1);

                //상우하
                int nextTemp2[9][9] = {0,};
                for(int ia = 0 ; ia < N; ia++){
                    for(int ja = 0 ; ja < M; ja++){
                        nextTemp2[ia][ja] = temp[ia][ja];
                    }
                }
                
                 
                //우
                for(int k = j+1; k < M; k++){
                    if(nextTemp2[i][k] == 6) break;
                    if(nextTemp2[i][k] == 0) nextTemp2[i][k] = 7;
                }
                //상
                for(int k = i-1; k >= 0; k--){
                    if(nextTemp2[k][j] == 6) break;
                    if(nextTemp2[k][j] == 0) nextTemp2[k][j] = 7;
                } 
                //하
                for(int k = i+1; k < N; k++){
                    if(nextTemp2[k][j] == 6) break;
                    if(nextTemp2[k][j] == 0) nextTemp2[k][j] = 7;
                }  

                func(i, j, cnt+1, nextTemp2);

                //우하좌
                int nextTemp3[9][9] = {0,};
                for(int ia = 0 ; ia < N; ia++){
                    for(int ja = 0 ; ja < M; ja++){
                        nextTemp3[ia][ja] = temp[ia][ja];
                    }
                }
                
                
                 //좌
                for(int k = j-1; k >= 0; k--){
                    if(nextTemp3[i][k] == 6) break;
                    if(nextTemp3[i][k] == 0) nextTemp3[i][k] = 7;
                } 
                //우
                for(int k = j+1; k < M; k++){
                    if(nextTemp3[i][k] == 6) break;
                    if(nextTemp3[i][k] == 0) nextTemp3[i][k] = 7;
                }
                //하
                for(int k = i+1; k < N; k++){
                    if(nextTemp3[k][j] == 6) break;
                    if(nextTemp3[k][j] == 0) nextTemp3[k][j] = 7;
                }  

                func(i, j, cnt+1, nextTemp3);

                //하좌상
                int nextTemp4[9][9] = {0,};
                for(int ia = 0 ; ia < N; ia++){
                    for(int ja = 0 ; ja < M; ja++){
                        nextTemp4[ia][ja] = temp[ia][ja];
                    }
                }
                
                
                 //좌
                for(int k = j-1; k >= 0; k--){
                    if(nextTemp4[i][k] == 6) break;
                    if(nextTemp4[i][k] == 0) nextTemp4[i][k] = 7;
                }
                //상
                for(int k = i-1; k >= 0; k--){
                    if(nextTemp4[k][j] == 6) break;
                    if(nextTemp4[k][j] == 0) nextTemp4[k][j] = 7;
                } 
                //하
                for(int k = i+1; k < N; k++){
                    if(nextTemp4[k][j] == 6) break;
                    if(nextTemp4[k][j] == 0) nextTemp4[k][j] = 7;
                }  

                func(i, j, cnt+1, nextTemp4);

            }
            if(temp[i][j] == 5){
                //좌우상하
                int nextTemp1[9][9] = {0,};
                for(int ia = 0 ; ia < N; ia++){
                    for(int ja = 0 ; ja < M; ja++){
                        nextTemp1[ia][ja] = temp[ia][ja];
                    }
                }
                
                
                //좌
                for(int k = j-1; k >= 0; k--){
                    if(nextTemp1[i][k] == 6) break;
                    if(nextTemp1[i][k] == 0) nextTemp1[i][k] = 7;
                } 
                //우
                for(int k = j+1; k < M; k++){
                    if(nextTemp1[i][k] == 6) break;
                    if(nextTemp1[i][k] == 0) nextTemp1[i][k] = 7;
                }
                //상
                for(int k = i-1; k >= 0; k--){
                    if(nextTemp1[k][j] == 6) break;
                    if(nextTemp1[k][j] == 0) nextTemp1[k][j] = 7;
                } 
                //하
                for(int k = i+1; k < N; k++){
                    if(nextTemp1[k][j] == 6) break;
                    if(nextTemp1[k][j] == 0) nextTemp1[k][j] = 7;
                } 

                func(i, j, cnt+1, nextTemp1);


            }
        }
    }
    return 0 ;
}


int main(void){

    cin >> N >> M;
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < M; j++){
            cin >> board[i][j];
            if(board[i][j] > 0 && board[i][j] < 6){
                cctvCnt++;
            }
        }
    }

    func(0,-1, 0,board);

    cout << minC;
    return 0;

}