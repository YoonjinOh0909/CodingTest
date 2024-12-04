#include <bits/stdc++.h>

using namespace std;

int len;
int a[1000005];
int sumV;
int ans;
int main(void){
    cin >> len;
    int digit[len] = {};
    for(int i = 0 ; i < len; i++){
        cin >>  digit[i];
        a[digit[i]] = 1;
    } 
    cin >> sumV;

    // cout<< digit[0] << '\n';
    // cout<< digit[len-1] << '\n';
    for(int i = 0 ; i < len; i++){
        if(sumV >= digit[i] && sumV - digit[i] <= 1000000 && a[sumV - digit[i]]){
            // cout << digit[i] << ' ' << a[sumV - digit[i]] << '\n';
            ans++;
        }
    } 
    cout<< ans/2;
    return 0;
}