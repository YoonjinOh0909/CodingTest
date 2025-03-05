#include <bits/stdc++.h>

using namespace std;

int n = 0;
stack<pair<int,int>> p;
long long ans = 0;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int val = 0;
    while(n--){
        cin >> val;

        int cnt = 1;

        while(!p.empty() && p.top().first <= val){
            ans += p.top().second;
            if(val == p.top().first) cnt += p.top().second;
            p.pop();
        }

        if(!p.empty()) ans++;
        p.push({val, cnt});
    }

    cout << ans;
    return 0;
}