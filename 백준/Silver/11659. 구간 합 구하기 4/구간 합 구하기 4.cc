#include <bits/stdc++.h>

using namespace std;

int arr[100005] = {0,};
int d[100005] = {0,};

int n,m = 0;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    d[0] = 0;
    for(int i = 1; i < n+1; i++){
        cin >> arr[i];
        d[i] = d[i-1]+ arr[i];
    }

    while(m--){
        int i,j;
        cin >> i >> j;
        cout << d[j] - d[i-1] << "\n";
    }

    return 0;
}