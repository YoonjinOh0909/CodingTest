#include <bits/stdc++.h>

using namespace std;
int n =0;
int arr[80005] = {0,}; // 맨 처음 정보를 받을 때
stack<pair<int,int>> sp; // 정보 받은 이후 계산할 때 필요한 stack
int main(void){
    cin >> n;

    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i =0; i < n; i++){
        cin >> arr[i];    
    }

    sp.push({1000000005, 0});
    int ind = 1;
    long long val = 0;
    while(n--){ // 들어갔던 것들 거꾸로 확인하기 위해 s -> sp로 이동하며 계산
        while(arr[n] > sp.top().first){
            
            sp.pop();
        }

        if(arr[n] <= sp.top().first){
            val += (ind - sp.top().second-1);
            sp.push({arr[n], ind});    
            ind++;
            
        }

    }

    cout << val;
    return 0;
}