#include <bits/stdc++.h>

using namespace std;

int n;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--){
        string val;
        cin >> val;
        stack<char> s;

        for(char c : val){
            if(!s.empty() && s.top() == '(' && c == ')'){
                s.pop();
            }
            else{
                s.push(c);
            }
        }

        cout << (!s.empty() ? "NO" : "YES") << "\n";

    }

    return 0;
}