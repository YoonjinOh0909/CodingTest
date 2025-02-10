#include <bits/stdc++.h>

using namespace std;

int n,m,k; // note row, colum, paper cnt
int r,c;
int paper[12][12] = {0,};
int note[42][42] = {0,};

bool Postable(int x, int y){
    for(int i=0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(x+i >= n || y + j >= m) return false; //범위를 벗어날 때.
            if(note[x+i][y+j] == 1 && paper[i][j] == 1){
                return false;
            }
        }
    }
    
    //둘이 겹치는 부분이 없다면 붙인다.

    for(int i=0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(paper[i][j] == 1){
                note[x+i][y+j] = 1;
            }
        }
    }

    return true;
}

void Rotate(){
    int temp[12][12] = {0,};

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            temp[i][j] = paper[i][j];
        }   
    }

    for(int i = 0; i < c; i++){
        for(int j = 0; j < r; j++){
            paper[i][j] = temp[r-1-j][i];
        }   
    }

    swap(r,c);
}

int main(void){

    cin >> n >> m >> k;

    while(k--){
        cin >> r >> c;

        for(int i=0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> paper[i][j];
            }
        }
        int isPost = false;
        for(int i =0; i< 4; i++ ){
            for(int x=0; x < n; x++){
                for(int y = 0; y < m; y++){
                    isPost = Postable(x,y);
                    if(isPost) break;        
                    
                }
                if(isPost) break;
            }
            if(isPost) break;
            else Rotate();
            
        }
            

    }

    int val=0;
    // cout << "\n------\n";
    for(int i=0; i < n; i++){
        for(int j = 0; j < m; j++){
            val += (note[i][j] == 1);
            // cout << note[i][j] << ' ';
        }
        // cout << "\n";
    }

    cout << val;
    return 0;
}