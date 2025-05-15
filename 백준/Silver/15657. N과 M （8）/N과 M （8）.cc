#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int> v;
int board[8] = {0,};
int allcnt = 0;
void dfs(int cnt){
    if(cnt >= m){
        for(int i = 0 ; i < m; i++){
            cout << board[i];
            if(i != m-1) cout << ' ';
        }
        cout << "\n";
        allcnt++;
        return;
    }

    for(int i = 0; i < v.size(); i++){
        if(cnt > 0 && board[cnt-1] > v[i]) continue;
        board[cnt] = v[i];
        dfs(cnt+1);
    }
}
int main(void){
    cin >> n >> m;
    int val;
    for(int i = 0 ; i < n; i++){
        cin >> val;
        v.push_back(val);
    }

    sort(v.begin(), v.end());

    dfs(0);
    return 0;
}