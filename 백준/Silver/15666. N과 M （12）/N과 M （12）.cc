#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int> v;
int board[12] = {0,};

void dfs(int ind, int cnt){
    if(cnt >= m){
        for(int i = 0 ; i < m ; i++){
            cout << board[i] << ' ';
        }
        cout << "\n";
        return;
    }

    for(int i = ind ; i < v.size() ; i++){
        board[cnt] = v[i];
        dfs(i, cnt+1);
    }
}
int main(void){
    int val;
    cin >> n >> m;

    for(int i = 0 ; i < n ; i++){
        cin >> val;
        auto its = find(v.begin(), v.end(), val);

        if(its == v.end()){ // 없으면
            v.push_back(val);
        }
    }

    sort(v.begin(), v.end());

    dfs(0,0);

    return 0;
}