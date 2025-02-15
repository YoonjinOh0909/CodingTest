#include <bits/stdc++.h>

using namespace std;

int arr[1000005] = {0,};
int n = 0;
int main(void){
    arr[2] = 1;
    arr[3] = 1;

    cin >> n;

    for(int i =4; i < n+1; i++){
        if(i %3 == 0){
            if(i %2 == 0){
                arr[i] = min(arr[i/3]+1, arr[i/2]+1);
            }
            else{
                arr[i] = min(arr[i-1]+1, arr[i/3]+1);
            }
        }
        else if(i %3 == 1){ 
            if(i %2 == 0){
                arr[i] = min(arr[i/2]+1, arr[i-1]+1);
            }
            else{
                arr[i] = arr[i-1]+1;
            }
            
        }
        else if(i %3 == 2){ 
            if(i %2 == 0){
                arr[i] = min(arr[i/2]+1, arr[i-1]+1);
                arr[i] = min(arr[i], arr[i-2]+2);
            }
            else{
                arr[i] = min(arr[i-1]+1, arr[i-2] + 2);
            }
        }
    }

    // for(int i =0; i < n+1; i++){
    //     // cout << arr[i] << ' ';
    // }
    // cout << "\n";
    cout << arr[n];
    return 0;
}