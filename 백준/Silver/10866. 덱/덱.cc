#include <bits/stdc++.h>

using namespace std;

int n = 0;
deque<int> d;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--){
        string s;
        int val;
        cin >> s;
        if(s == "push_front"){
            cin >> val;
            d.push_front(val);
        }
        else if(s == "push_back"){
            cin >> val;
            d.push_back(val);
        }
        if(s == "pop_front"){
            cout << (d.empty() ? -1 : d.front());
            cout << "\n";
            if(!d.empty()) d.pop_front();
        }
        else if(s == "pop_back"){
            cout << (d.empty() ? -1 : d.back());
            cout << "\n";
            if(!d.empty()) d.pop_back();
        }
        else if( s == "size"){
            cout << d.size() << "\n";
        }
        else if ( s == "empty"){
            cout << d.empty() ? 1 : 0;
            cout << "\n";
        }
        else if(s == "front"){
            cout << (d.empty() ? -1 : d.front());
            cout << "\n";
        }
        else if(s == "back"){
            cout << (d.empty() ? -1 : d.back());
            cout << "\n";
        }
    }

    return 0;
}