#include <bits/stdc++.h>

using namespace std;

int n;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    unordered_set<string> us;

    cin >> n;

    while(n--){
        string name;
        string state;
        cin >> name >> state;

        if(state == "enter"){
            us.insert(name);
        }else if(state == "leave"){
            us.erase(name);
        }
    }

    vector<string> vs;
    
    for(string s : us){
        vs.push_back(s);
    }

    sort(vs.begin(), vs.end(), greater<>());

    for(string s : vs){
        cout << s << "\n";
    }
    return 0;
}