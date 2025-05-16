#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int> v;
int val;
int board[10] = {0,};

void dfs(int cnt){
    if(cnt >= m){
        for(int i = 0 ; i < m; i++){
            cout << board[i] << ' ';
        }
        cout << "\n";
        return;
    }

    for(int i = 0 ; i < v.size() ; i++){
        board[cnt] = v[i];
        dfs(cnt+1);
    }
}

int main(void){
    cin >> n >> m;
    for(int i = 0 ; i < n; i++){
        cin >> val;
        auto its = find(v.begin(), v.end(), val);
        if(its == v.end()) v.push_back(val);
    }
    sort(v.begin(), v.end());
    dfs(0);
    return 0;
}