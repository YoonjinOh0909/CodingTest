#include <bits/stdc++.h>

using namespace std;

int n, k;
int val[11];
int cnt = 0;

int main(void){
    cin >> n >> k;

    for(int i =0 ; i < n; i++){
        cin >> val[i];
    }

    for(int i =0 ; i < n; i++){
        cnt += k / val[n - i -1];
        k %= val[n - i -1];
    }

    cout << cnt;
    return 0;
}