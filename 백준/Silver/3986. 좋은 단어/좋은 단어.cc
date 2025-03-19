#include <bits/stdc++.h>

using namespace std;

int n;

int cnt=0;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    while(n--){
        stack<char> s;
        string val = "";
        cin >> val;

        for(char a : val){
            
            if(s.empty()){
                s.push(a);
            }else{
                if(a == s.top()){
                    s.pop();
                }else{
                    s.push(a);
                }
            }
        }

        if(s.empty()){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}