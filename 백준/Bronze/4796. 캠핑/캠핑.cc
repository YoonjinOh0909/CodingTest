#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int L, P,V;
    int index = 1;
    while(1){
        cin >> L >> P >> V;
        if(L == 0) break;
        int cnt = 0;
        cnt = (V / P) * L;
        
        int re = V % P;
        if(re > L){
            cnt += L;
        }else{
            cnt += re;
        }
        cout << "Case " << index++ << ": " << cnt << "\n";
    }
    return 0;
}