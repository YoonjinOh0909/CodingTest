#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int howm = 0;

    cin >> howm;
    stack<int> sta;
    string type = "";
    int val = 0;
    while(howm--){
        cin >> type;
        if(type == "push"){
            cin >> val;
            sta.push(val);
        }else if(type == "pop"){
            if(sta.size() > 0){
                cout << sta.top();
                sta.pop();
            }else{
                cout << "-1";
            }
            cout << '\n';
        }else if(type == "size"){
            cout << sta.size() << '\n';
        }else if(type == "empty"){
            if(sta.empty())
                cout << '1';
            else
                cout << '0';
            cout << '\n';
        }else if(type == "top"){
            if(!sta.empty())
                cout << sta.top();
            else
                cout << "-1";
            cout << '\n';
        }
    }
    return 0;
}