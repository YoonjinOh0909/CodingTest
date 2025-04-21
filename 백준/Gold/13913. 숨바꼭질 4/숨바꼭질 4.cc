#include <bits/stdc++.h>

using namespace std;

int board[100002] = {0,};
int preB[100002] = {0,};
int n,k;
queue<int> q;

int dx[4] = {1,0,-1,0};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    fill(board, board+100001, -1);

    q.push(n);
    board[n] = 0;

    while(!q.empty()){
        auto c = q.front();
        q.pop();
        if(c == k){
            break;
        }

        for(int nx : {c-1, c+1, 2*c}){
            if(nx < 0 || nx > 100000) continue;
            if(board[nx] != -1) continue;

            q.push(nx);
            board[nx] = board[c]+1;
            preB[nx] = c;
        }
    }

    cout << board[k] << "\n";

    int sx = k;
    int nx;
    stack<int> qi;

    while(1){
        nx = sx;
        qi.push(nx);
        if(nx == n) break;
        sx = preB[nx];
    }

    while(!qi.empty()){
        cout << qi.top() << ' ';
        qi.pop();
    }

    
    return 0;
}