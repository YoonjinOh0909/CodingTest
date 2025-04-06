#include <bits/stdc++.h>

using namespace std;

int arr[10001] = {0,};
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    arr[0] = 1;
    arr[1] = 3;

    for(int i = 2; i <n; i++){
        arr[i] = (arr[i-2] * 2 + arr[i-1])% 10007;
    }

    cout << arr[n-1];
    return 0;
}