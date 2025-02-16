#include <bits/stdc++.h>

using namespace std;

int n=0;
int s[10005] = {0,};
int arr[10005][3] = {0,};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i =0; i< n; i++){
        cin >> s[i];   
    }

    arr[0][1] = s[0];
    arr[0][2] = 0;
    arr[1][1] = s[1];
    arr[1][2] = s[0] + s[1];
    for(int i =2; i< n; i++){
        arr[i][1] = max(arr[i-2][1], arr[i-2][2]) +s[i];
        arr[i][2] = arr[i-1][1] +s[i];
    }

    cout << max(arr[n-1][1], arr[n-1][2]);

    return 0;
}