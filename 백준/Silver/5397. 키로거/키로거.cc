#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase = 0;
    cin >> testCase;

    while(testCase--){
        string password = "";
        list<char> passwordList = {};
        list<char>::iterator c = passwordList.begin();

        cin >> password;

        for(char p : password){
            if(p == '<'){
                if(c != passwordList.begin()){
                    c--;
                }
                
            }else if(p == '>'){
                if(c != passwordList.end()){
                    c++;
                }
                
            }else if(p == '-'){
                if(c != passwordList.begin()){
                    c--;
                    c = passwordList.erase(c);
                }
                
            }else{
                passwordList.insert(c, p);
            }
        }

        for(auto L : passwordList){
            cout << L;
        }
        cout << '\n';
    }
    return 0;
}