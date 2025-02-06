#include <bits/stdc++.h>
using namespace std;

int N,M;
bool isused[9];
int val[9];

int func(int a, int cnt){
    if(cnt == M){
        for(int i = 0; i < M; i++){
            cout << val[i] << ' ';
        }
        cout << "\n";
        return 0;
    }
    for(int i = a; i < N+1; i++){
        if(!isused[i]){
            isused[i] = true;
            val[cnt] = i;
            func(i+1,cnt+1);
            isused[i] = false;
        }
    }
    return 0;
}
int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    func(1,0);

    return 0;
}