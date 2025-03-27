#include <bits/stdc++.h>

using namespace std;

int n;
using ll = long long;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while(n--){
        int cnt;
        cin >> cnt;

        multiset<ll> ms;
        char c;
        ll val;
        while(cnt--){
            cin >> c >> val;

            if(c == 'I'){
                ms.insert(val);
            }else if(c == 'D'){
                if(!ms.empty()){
                    if(val == -1){ // 최솟값 삭제
                        ms.erase(ms.begin());
                    }
                    else if(val == 1){ // 최댓값 삭제
                        ms.erase(prev(ms.end()));
                    }
                }
            }
        }

        if(!ms.empty()){
            cout << *prev((ms.end()) ) << 
            ' ' << *ms.begin() << 
            "\n";
        }else{
            cout << "EMPTY\n";
        }
    }

    return 0;
}