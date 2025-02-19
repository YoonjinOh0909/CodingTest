#include <bits/stdc++.h>

using namespace std;

int n;
int a[100005] = {0,};
int maxv = 0;

int main(void){
    cin >> n;

    for(int i = 0; i< n; i++){
        cin >> a[i];
    }
    sort(a,a+n);
    for(int i = 0; i< n; i++){
        maxv = max(maxv, a[i]*(n-i));
    }
    cout << maxv;
    return 0;
}