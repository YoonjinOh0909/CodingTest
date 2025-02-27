#include <bits/stdc++.h>

using namespace std;

int c;
stack<pair<int,int>> s;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> c;

    int height;
    s.push({100000001,0});
    for(int i = 1; i<= c; i++){
        cin >> height;
        // cout << height << "\n";
        while(s.top().first < height){
            s.pop();
        }
        cout << s.top().second << ' ';
        s.push({height, i});
    }
    return 0;
}