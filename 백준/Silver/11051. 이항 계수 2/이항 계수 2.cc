#include <bits/stdc++.h>

using namespace std;

int n, k;
int mod = 10007;

int arr[1005][1005] = {0,};
int main(void){
    cin >> n >> k;

    for(int i = 1; i <=n; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0){
                arr[i][j] = 1;
                continue;
            }
            if(j == i) {
                arr[i][j] = 1;
                continue;
            }
            arr[i][j] = (arr[i-1][j-1] + arr[i-1][j]) % mod;
        }
    }

    cout << arr[n][k];
    return 0;
}