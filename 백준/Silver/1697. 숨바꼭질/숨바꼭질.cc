#include <bits/stdc++.h>
using namespace std;

int n, m;
int dist[100001] = {0,};


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(dist, dist+100001, -1);
    

    cin >> n >> m;

    dist[n] = 0;
    queue<int> q;
    q.push(n); // 수빈 위치

    while(dist[m] == -1){
        int cur = q.front(); 
        q.pop();

        for(int tempVal : {cur -1, cur + 1, cur *2}){

            if(tempVal < 0 || tempVal > 100000) continue;
            if(dist[tempVal] != -1) continue;
            
            dist[tempVal] = dist[cur]+1;
            q.push(tempVal);
        }
    }

    cout << dist[m] << "\n";
    return 0;
}