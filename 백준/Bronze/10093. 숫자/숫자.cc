#include <bits/stdc++.h>

using namespace std;

long long a,b;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;
    if(a > b){
        swap(a,b);
    }
    if(abs(a-b) < 2){
        cout << 0 << '\n' << '\n';
    }else{
        cout << b - a - 1 << '\n';
        for(long long i = a+1; i < b; i++) cout << i << ' ';
    }

    return 0;
}