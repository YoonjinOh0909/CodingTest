#include <bits/stdc++.h>

using namespace std;

int T;
int n;
string s;
string rd;
deque<int> dq;
bool isfront = true;
bool isError = false;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--){
        cin >> rd;
        cin >> n;
        cin >> s;
        
        dq.clear();
        isfront = true;
        isError = false;

        for(char &c : s){
            if(c == '[' || c == ']'){
                c = ' ';
            }
        }
        stringstream ss(s);
        int val;
        char comma;
        while(ss >> val){
            dq.push_back(val);
            ss >> comma;
        }

        for(char &rnd : rd){
            if(rnd == 'R'){
                isfront = !isfront;
            }
            else if(rnd == 'D'){
                if(!dq.empty()){
                    if(isfront){
                        dq.pop_front();
                    }else{
                        dq.pop_back();
                    }
                }else{
                    isError = true;
                    break;
                }
            }
        }

        if(isError){
            cout << "error\n";
        }else{
            cout << '[';
            while(!dq.empty()){
                if(isfront){
                    cout << dq.front();
                    dq.pop_front();
                }else{
                    cout << dq.back();
                    dq.pop_back();
                }
                if(!dq.empty()) cout << ',';
            }
            cout << "]\n";
        }
    }
    

}