#include <bits/stdc++.h>

using namespace std;

int n;
int arr[10005] = {0,};

int main(void){
    cin >> n;
    arr[1] = 1;
    arr[2] = 2;
    for(int i =3; i< n+1; i++){
        arr[i] = (arr[i-1] + arr[i-2])% 10007;
    }

    cout << arr[n] ;

    return 0;
}