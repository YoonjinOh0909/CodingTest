#include <bits/stdc++.h>

using namespace std;

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true){
        string a;
        getline(cin, a);
        if(a == "."){
            break;
        }
        stack<char> s;
        bool inValid = true;

        for(auto c : a){
            
            if(c == '(' || c == '['){
                s.push(c);
            }
            else if(c == ')'){
                if(s.empty() || s.top() != '('){
                    inValid = false;
                    break;
                }
                s.pop(); //어차피 아닌거는 위에서 break 될거라서

            }
            else if(c == ']'){
                if(s.empty() || s.top() != '['){
                    inValid = false;
                    break;
                }
                s.pop();
            }
        }
        if(!s.empty()) inValid = false;
        if(inValid){
            cout << "yes\n";
        }else{
            cout << "no\n";
        }
        
    }

    return 0;
}