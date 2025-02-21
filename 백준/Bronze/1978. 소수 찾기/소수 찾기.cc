#include <bits/stdc++.h>

using namespace std;

int n;
int arr[105] = {0,};
int main(void){

    cin >> n;

    for(int i =0; i < n; i++){
        cin >> arr[i];
    }
    int cnt = 0;
    for(int i =0; i < n; i++){
        if(arr[i] == 1) continue;
        bool isdec = true;
        for(int j =2; j*j <= arr[i]; j++){
            if(arr[i] % j == 0 ){
                isdec = false;
                break; // 딱 떨어지는게 있으면 1을 제외한 약수가 있다는 것이기 때문에.
            } 
            
        }
        if(isdec) cnt++;
    }

    cout << cnt;
    return 0;
}