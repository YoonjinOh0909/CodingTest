#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    vector<int> v;

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int val;
        cin >> val;
        v.push_back(val);
    }

    sort(v.begin(), v.end());

    int total = 0;

    for(int i = 0 ; i < n ; i++){
        total += v[i] * (n-i);
    }

    cout << total;
    return 0;
}