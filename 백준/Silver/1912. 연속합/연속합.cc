#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100001] = {0,};
int DP[100001] = {0,}; // D[i] = i번째 항을 마지막으로 하는 최대 연속합

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0 ; i< n; i++){
        cin >> arr[i];
    }

    DP[0] = arr[0];

    for(int i = 1 ; i < n; i++){
        DP[i] = max(DP[i-1], 0) + arr[i]; // 만약 직전 DP까지 음수라면, 자기 자신부터 시작하는게 더 클테니 0과 비교를 한다.
    }

    cout << *max_element(DP, DP+n);

    return 0;
}