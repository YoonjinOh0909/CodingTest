#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int> v;
int board[10] = {0,};
bool isused[10] = {0,};


void dfs(int cnt, int st){
    if(cnt >= m){
        for(int i = 0; i < m; i++){
            cout << board[i] << ' ';
        }
        cout << "\n";

        return;
    }

    int temp = -1;
    for(int i = st; i < n; i++){
        if(isused[i]) continue;
        if(temp == v[i]) continue;

        board[cnt] = v[i];
        isused[i] = true;
        temp = v[i];
        
        dfs(cnt+1, i);
        isused[i] = false;
    }

}
int main(void){
    cin >> n >> m;
    int val;
    for(int i = 0; i < n; i++){
        cin >> val;
        v.push_back(val);
    }

    sort(v.begin(), v.end());

    dfs(0,0);

    return 0;
}