#include <bits/stdc++.h>

using namespace std;

int n = 0;
stack<int> s;
int ind = 0;
vector<bool> v = {};
bool finalV = true;
int main(void){
    cin >> n;
    int temp = 0;
    while(n--){
        cin >> temp;
        if(!s.empty() && s.top() > temp){
            finalV = false;
            continue;
        }
        
        while(ind < temp){ // 만약 ind 가 temp
            ind++;
            s.push(ind);
            v.push_back(true);
        }
        
        if(!s.empty() && s.top() == temp){
            s.pop();
            v.push_back(false);
            continue;
        }
        
    }
    if(finalV){
        for(bool a : v){
            if(a) cout << '+' << "\n";
            else cout << '-' << "\n";
        }
    }else{
        cout << "NO";
    }
    
    return 0;
}