#include <bits/stdc++.h>

using namespace std;

int n;
long long arr[100] ={1,1,1,2,2,};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--){
        int val;
        cin >> val;
        for(int i = 5 ; i < val; i++){
            arr[i] = arr[i-2] + arr[i-3];
        }

        cout << arr[val-1] << "\n";
    }
    

    return 0;
}