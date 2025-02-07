#include <bits/stdc++.h>

using namespace std;

int N,M;
int cinval[9];
int funcval[9];
int isused[9];

int func(int cnt){
    if(cnt == M){

        for(int i = 0; i < M; i++){
            cout << cinval[funcval[i]] << ' ';
        }

        cout << "\n";
        return 0 ;
    }

    for(int i = 1; i< N+1; i++){
        if(!isused[i]){
            isused[i] = 1;
            funcval[cnt] = i;
            func(cnt+1);
            isused[i] = 0;
        }
    }

    return 0;
}

int main(void){

    cin >> N >> M;

    for(int i = 1; i < N+1; i++){
        cin >> cinval[i];
    }

    sort(cinval, cinval + N +1);

    func(0);

    return 0;
}