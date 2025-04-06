#include <bits/stdc++.h>

using namespace std;

int arr[501][501] = {0,};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;

    cin >> n;

    

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i+1; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = n-2; i >= 0; i--){
        for(int j = 0; j < i+1; j++){
            arr[i][j] = max(arr[i+1][j], arr[i+1][j+1]) + arr[i][j];
        }
        
    }

    cout << arr[0][0];
    return 0;
}