#include <bits/stdc++.h>

using namespace std;

int main(void){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    
    string firstInput = "";
    int howm = 0;

    list<char> editor = {};
    list<char>::iterator cursor = editor.end();

    cin >> firstInput >> howm;

    for(char c : firstInput){
        editor.push_back(c);
    }
    char commandInput = ' ';
    char inputChar = ' ';

    while(howm--){
        cin >> commandInput;
        if(commandInput == 'L'){
            if(cursor != editor.begin()){
                
                cursor--;
            }
            // cout<< "cursor " << *cursor << '\n';
        }else if(commandInput == 'D'){
            if(cursor != editor.end()){
                cursor++;
            }
        }else if(commandInput == 'B'){
            if(cursor != editor.begin()){
                cursor--;
                cursor = editor.erase(cursor);
            }
        }else if(commandInput == 'P'){
            cin >> inputChar;
            editor.insert(cursor, inputChar);
        }
    }

    for(auto c : editor) cout << c;

    return 0;
}