#include <bits/stdc++.h>
using namespace std;

int dp[10002][3] = {0,};
int a[10002] = {0,};
int n;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++){
        dp[i][0] = *max_element(dp[i-1], dp[i-1]+3);
        dp[i][1] = dp[i-1][0] + a[i];
        dp[i][2] = dp[i-1][1] + a[i];
    }

    cout << *max_element(dp[n], dp[n]+3);
}