#include <bits/stdc++.h>

using namespace std;

int x;
int a[1000005] = {0,};
int prv[1000005] = {0,};
int main(void){
    cin >> x;

    a[0] = 0;
    a[1] = 0;
    
    prv[1] = 0;

    for(int i = 2; i <= x; i++){
        a[i] = a[i-1] +1;
        prv[i] = i-1;
        if(i % 2 == 0 && a[i] > a[i/2]+1){
            a[i] = a[i/2]+1;
            prv[i] = i/2;
        }
        if (i % 3 == 0 && a[i] > a[i/3]+1){
            a[i] = a[i/3]+1;
            prv[i] = i/3;
        }
    }
    
    cout << a[x] << "\n";
    int index = x;
    while(true){
        cout << index << ' ';
        if(index == 1) break;
        index = prv[index];
    }
    return 0;
}