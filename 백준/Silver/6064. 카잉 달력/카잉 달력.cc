#include <bits/stdc++.h>

using namespace std;

int t;

int gcd(int a, int b){
    if(a == 0) return b;
    return gcd(b%a, a);
}

int lcm(int a, int b){
    return (a / gcd(a,b)) * b;
}

int solve(int a, int b, int c, int d){
    int l = lcm(a,b);
    if(a == c) c= 0;
    if( b == d) d =0;
    for(int i = c; i <= l; i += a){ // m으로 나눴을 때, 나머지가 x
        if(i == 0) continue;
        if(i % b ==  d){ //n으로 나눴을 때 나머지가  y
            return i;
        }
    }

    return -1;
}
int main(void){
    cin >> t;
    int m,n,x,y = 0;
    while(t--){
        cin >> m >>n >> x >> y;
        
        cout << solve(m,n,x,y) << "\n";
        
    }
    return 0;
}