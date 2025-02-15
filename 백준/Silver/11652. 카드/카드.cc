#include <bits/stdc++.h>

using namespace std;

int n;
// vector<pair<long long, int>> arr;
// vector<pair<long long, int>> arr2;

long long arr[100005];
long long max_val = -1 * (1ll<<62)-1;
long long max_Cnt = 0;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i =0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr, arr+n);
    
    //처음 시작 전 세팅.
    int cnt = 1;

    for(int i =1; i < n; i++){
        if(arr[i-1] == arr[i]){
            cnt++;
            
        }else{

            if(max_Cnt < cnt){
                max_val = arr[i-1];
                max_Cnt = cnt;
            }

            cnt = 1;
            
        }
    }

    if(max_Cnt < cnt){
        max_val = arr[n-1];
    }    
    
    cout << max_val;
    return  0;
}