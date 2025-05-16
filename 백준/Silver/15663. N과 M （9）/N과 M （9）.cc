#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> v;
int board[10] = {0,};
bool isuse[10] = {0,};

void dfs(int cnt){
    if(cnt >= m){
        for(int i = 0 ; i < m; i++){
            cout << board[i] << ' ';
        }
        cout << "\n";
        return;
    }

    int temp = -1;

    for(int i = 0 ; i < n; i++){
        if(isuse[i]) continue;
        if(temp == v[i]) continue;
        board[cnt] = v[i];
        isuse[i] = true;
        temp = v[i];
        dfs(cnt+1);
        isuse[i] = false;
    }
}

int main(void){
    cin >> n >> m;
    int val;
    for(int i = 0; i<n; i++){
        cin >> val;
        v.push_back(val);
    }

    sort(v.begin(), v.end());

    dfs(0);
    return 0;
}