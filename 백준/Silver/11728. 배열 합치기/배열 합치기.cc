#include <bits/stdc++.h>

using namespace std;

int n,m;
int a[1000001] = {0,};
int b[1000001] = {0,};

int main(void){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    int c[n+m+1] = {0,};
    
    int aind = 0;
    int bind = 0;

    for(int i =0; i < n+m ; i++){
        if((bind >= m) || (aind < n && a[aind] <= b[bind])){
            c[i] = a[aind++];
            // cout << i << ' ' << c[i] << "\n";
        }else{
            c[i] = b[bind++];
            // cout << i << ' ' << c[i] << "\n";
        }

    }

    for(int i =0; i < n+m ; i++){
        cout << c[i] << ' ';

    }
    return 0;
}