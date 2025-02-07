#include <bits/stdc++.h>

using namespace std;

int N, M;
int val[8] = {0,};

int func(int a, int cnt){
    if(cnt == M){
        for(int i = 0; i< M; i++){
            cout << val[i] << ' ';
        }
        cout << "\n";
        return 0;
    }

    for(int i = a; i < N+1 ; i++){
        val[cnt] = i;
        func(i, cnt + 1);
    }

    return 0;
}

int main(void){

    cin >> N >> M;
    func(1, 0);
    return 0;
}