#include <bits/stdc++.h>

using namespace std;

int n;
int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i =0; i < 2*n-1; i++){
        int abs1 = abs(n-i-1);
        for(int j = 0; j < n-1; j++){
            if(j < abs1){
                cout << " ";
            }else{
                cout << "*";
            }
            
        }
        cout << "*";
        for(int j = n-2; j > -1; j--){
            if(j >= abs1){
                cout << "*";
            }
            
        }
        if(i != 2*n -2){
            cout << '\n';
        }
        
    }

    return 0;
}