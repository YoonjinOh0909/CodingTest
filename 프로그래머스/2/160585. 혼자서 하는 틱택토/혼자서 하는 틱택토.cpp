#include <string>
#include <vector>

using namespace std;

int ibd[3][3] = {0,};
int solution(vector<string> board) {
    int answer = -1;
    int ocnt = 0;
    int xcnt = 0;
    bool owin = false;
    bool xwin = false;
    
    for(int i = 0 ; i <3 ; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == 'O'){
                ibd[i][j] = 1;
                ocnt++;
            }else if(board[i][j] == 'X'){
                ibd[i][j] = -1;
                xcnt++;
            }
        }
    }
    if(ocnt - xcnt != 1 && ocnt - xcnt != 0) return 0;
    
    int xdval = 0;
    int xuval = 0;
    
    for(int i = 0 ; i < 3; i++){
        int wval = 0;
        int hval = 0;
        
        
        for(int j = 0; j <3; j++){
            wval += ibd[i][j];
            hval += ibd[j][i];
        }
        
        xdval += ibd[i][i];
        xuval += ibd[i][2-i];
        
        if(wval == 3 || hval == 3 || xdval == 3 || xuval == 3) owin = true;
        if(wval == -3 || hval == -3 || xdval == -3 || xuval == -3) xwin = true;
    }
    
    if(owin && xwin) return 0;
    if(owin && ocnt == xcnt) return 0;
    if(xwin && ocnt > xcnt) return 0;
    return 1;
}