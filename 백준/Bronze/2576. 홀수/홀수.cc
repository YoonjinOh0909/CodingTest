#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int a[7];
int minV;
int total;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    minV = -1;
    
    for(int i = 0 ; i < 7; i++){
        cin >> a[i];
        
        if(a[i] % 2 == 1){
            total += a[i];
            if(minV > a[i] || minV < 0){
                minV = a[i];
            }
        }
    }
    if(minV != -1){
        cout << total << '\n';
    }
    
    cout << minV;
    return 0;
}