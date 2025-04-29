#include <bits/stdc++.h>

using namespace std;

long long arr[1000002] = {0,};
int n;
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;

    int maxv = 4;
    while(n--){
        int a;
        cin >> a;

        

        if(arr[a] != 0){
            cout << arr[a] << "\n";
            continue;
        }

        for(int i = maxv; i <= a; i++){
            arr[i] = (arr[i-3] + arr[i-2] + arr[i-1]) % 1000000009;
        }
        maxv = max(maxv, a);
        cout << arr[a] << "\n";


    }
    return 0;
}