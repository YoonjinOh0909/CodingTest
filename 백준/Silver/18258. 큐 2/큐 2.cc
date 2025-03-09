#include <bits/stdc++.h>

using namespace std;

int n;
queue<int> q;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while(n--){
        string s;
        int val;
        cin >> s;
        if(s == "push"){
            cin >> val;
            q.push(val);
        }
        else if(s == "front"){
            if(!q.empty()){
                cout << q.front() << "\n";
            }else{
                cout << "-1" << "\n";
            }
            
        }
        else if( s== "back"){
            if(!q.empty()){
                cout << q.back() << "\n";
            }else{
                cout << "-1" << "\n";
            }
            
        }
        else if( s == "pop"){
            if(!q.empty()){
                
                cout << q.front() << "\n";
                q.pop();
            }else{
                cout << "-1" << "\n";
            }
        }else if( s== "empty"){
            if(!q.empty()){
                cout << "0" << "\n";
            }else{
                cout << "1" << "\n";
            }
        }else if(s=="size"){
            cout << q.size() << "\n";
        }
    }
    return 0;
}