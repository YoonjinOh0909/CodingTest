#include <bits/stdc++.h>

using namespace std;

int m,n;
bool arr[1000005];

int IsPrimte(int a){

    return 0;
}

int main(void){
    cin >> m >>n ;
    fill(arr, arr+1000005, true); // 일단 모든 곳을 true로 만들고 시작.
    arr[0], arr[1] = 0; //0과 1은 소수가 아니기 때문에 false로 만듦.

    for(int i = 2; i * i<=n; i++){
        if(!arr[i]) continue; // 소수가 아닐 때는 굳이 계산할 필요 x;
        for(int j = i * i ; j <= n; j++){
            if(!arr[j]) continue; // 소수가 아닐 때는 굳이 계산할 필요 x;
            if(j % i == 0) arr[j] = 0; //나눠떨어지면 소수가 아님.
        }
    }
    
    
    for(int i = m; i<=n; i++){
        if(arr[i]) cout << i <<"\n";
    }
    return 0;
}