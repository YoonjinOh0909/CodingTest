#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
ll d[1500002] = {0,};
ll t[1500002] = {0,};
ll p[1500002] = {0,};

int main(void){
    cin >> n;
    for(int i =1; i <= n; i++){
        cin >> t[i];
        cin >> p[i];
    }

    for(int i =n; i>0; i--){
        if(i + t[i] <= n+1){
            d[i] = max(d[i+t[i]] + p[i], d[i+1]);
        }else{
            d[i] = d[i+1];
        }
    }

    cout << *max_element(d+1, d +n +1) << "\n";
    return 0;
}