#include <bits/stdc++.h>

using namespace std;
#define MAXV 1000005
int n;
int arr[MAXV] = {0,};
stack<pair<int,int>> sp;
int ans[MAXV] = {0,};
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i =0; i < n; i++){
        cin >> arr[i];
    }

    sp.push({MAXV, -1});
    int k = n;
    while(n--){
        while(sp.top().first <= arr[n]){
            sp.pop();
        }

        if(sp.top().first == MAXV) sp.push({arr[n], -1});
        else sp.push({arr[n], sp.top().first});
        
        ans[n] = sp.top().second;
    }
    for(int i = 0; i < k; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}