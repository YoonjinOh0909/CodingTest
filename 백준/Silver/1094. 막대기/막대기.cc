#include <bits/stdc++.h>

using namespace std;

int n;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int cnt = 0;
    while(n != 0){
        if(n % 2 == 1) cnt++;
        n /= 2;
    }

    cout << cnt;

    return 0;
}