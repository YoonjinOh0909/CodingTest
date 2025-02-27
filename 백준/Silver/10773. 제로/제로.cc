#include <bits/stdc++.h>

using namespace std;

int n;
stack<int> s = {};
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    int t=0;
    while(n--){
        cin >> t;
        if(t != 0) s.push(t);
        else{
            if(!s.empty()) s.pop();
        } 
    }

    int total = 0;
    while(!s.empty()){
        total += s.top();
        s.pop();
    }
    
    cout << total;
    return 0;
}