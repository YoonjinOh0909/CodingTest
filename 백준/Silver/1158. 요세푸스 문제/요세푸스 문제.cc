#include <iostream>
#include <list>

using namespace std;

int main(void){
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    list<int> l = {};
    list<int>::iterator c = l.begin();
    list<int> ans = {};
    int count, many = 0;

    cin >> count >> many;

    int countA = count;
    int countB = count;
    while(countA--){
        l.push_front(countA+1);
    }

    // for(auto b : l)
    //     cout << b;

    // cout << '\n';

    c= l.begin();

    while(count--){
        
        for(int i = 0; i< many ; i++){
            if(c == l.end()) c= l.begin();
            c++;
            if(c == l.end()) c= l.begin();
        }
        if(c == l.begin()) c = l.end();
        c--;
        ans.push_back(*c);

        c= l.erase(c);
    }

    cout << '<';
    int index = 0;
    for(auto a : ans){
        if(index != 0) cout << ' ';
        cout << a ;
        index++;
        if(index != countB) cout << ',';
    }
    cout << '>';
        

    return 0;
}
