#include <bits/stdc++.h>

using namespace std;

int n,m;
int arr[100005] = {0,};

int solve(int s){
    int st = 0;
    int en = n-1;
    int mid;
    while(en >= st){
        mid = (st+en)/2;
        if(arr[mid] == s){ // target이 같다면
            return 1;
        }else{
            if(arr[mid] > s){
                en = mid -1;
            }else{
                st = mid+1;
            }
        }
    }
    return 0;
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i =0; i< n; i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    cin >> m;

    int a;
    while(m--){
        cin >> a;
        cout << solve(a) << "\n";
    }
    return 0;
}