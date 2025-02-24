#include <bits/stdc++.h>

using namespace std;

int n,m;
int arr[100005] = {0,};
int minV = 0x7f7f7f7f;

void solve(int a){
    int st = a+1;
    int en = n-1;
    int mid = (st+en)/2;

    while(st < en){
        if(arr[mid] >= arr[a]+m){
            en = mid;
        }else{
            st = mid+1;
        }
    }
    if(abs(arr[st]-arr[a]) >= m)
        minV = min(minV, abs(arr[st]-arr[a]));
}
int main(void){
    cin >> n >> m;

    for(int i =0; i < n; i++){
        cin>> arr[i];
    }
    sort(arr, arr+n);

    int st = 0;
    int en = 0;

    while(st < n){
        if(arr[en] - arr[st] >= m){
            minV = min(minV, arr[en] - arr[st]);
            st++;
        }else{
            if(en < n-1)
                en++;
            else
                st++;
        }
    }


    cout << minV;
    return 0;
}