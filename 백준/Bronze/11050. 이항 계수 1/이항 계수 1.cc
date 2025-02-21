#include <bits/stdc++.h>

using namespace std;

int solve(int a, int b){
    if(a == b || b == 0) return 1;
    if(b == 1) return a;
    return solve(a-1, b) + solve(a-1, b-1);
}

int main(void){
    int m,n;
    cin >> m >> n;
    cout << solve(m,n);
    return 0;
}