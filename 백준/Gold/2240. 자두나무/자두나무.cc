#include <bits/stdc++.h>

using namespace std;

int d[1002][32][3] = {0,}; // i초에 j번 이동했을 때 x 위치 나무에 있을 때 받은 자두 최대 개수
int a[1002] = {0,};

int t,w;
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> t >> w;
    for(int i = 1; i <= t; i++){
        cin >> a[i];
    }

    for(int i = 1; i <= t; i++){
        d[i][0][1] = d[i-1][0][1] + (a[i] == 1 ? 1 : 0); // 한 번도 이동하지 않았을 경우
        for(int j = 1; j <= w; j++){
            if( i < j) continue;
            if(a[i] == 1){
                d[i][j][1] = max(d[i-1][j-1][2], d[i-1][j][1]) +1;
                d[i][j][2] = max(d[i-1][j-1][1], d[i-1][j][2]);
            }else{
                d[i][j][1] = max(d[i-1][j-1][2], d[i-1][j][1]);
                d[i][j][2] = max(d[i-1][j-1][1], d[i-1][j][2])+1;
            }
        }
    }

    int ans =0;
    for(int i = 1; i <= w; i++){
        ans = max({ans, d[t][i][1], d[t][i][2]});
    }

    cout << ans;
    return 0;
}