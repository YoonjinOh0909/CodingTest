#include <bits/stdc++.h>

using namespace std;

int n;
int arr[1005][4] ={0,}; //[i][0~3] 0,1,2 순서대로 빨,초,파를 뜻한다.
int ans[1005][4] = {0,};
int main(void){
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> arr[i][0];
        cin >> arr[i][1];
        cin >> arr[i][2];
    }

    ans[0][0] = arr[0][0];
    ans[0][1] = arr[0][1];
    ans[0][2] = arr[0][2];

    for(int i = 1; i<n; i++){
        ans[i][0] = min(ans[i-1][1],ans[i-1][2]) + arr[i][0];
        ans[i][1] = min(ans[i-1][0],ans[i-1][2]) + arr[i][1];
        ans[i][2] = min(ans[i-1][1],ans[i-1][0]) + arr[i][2];
    }

    cout << min(min(ans[n-1][1],ans[n-1][0]), ans[n-1][2]);

    return 0;
}