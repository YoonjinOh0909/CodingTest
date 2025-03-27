#include <bits/stdc++.h>

using namespace std;

int n, k;

int main(void){
    cin >> n >> k;
    multimap<int, int> mm;
    while(n--){
        int m;
        int price;
        cin >> m >> price;

        mm.insert(pair<int,int>(price, m));
    }

    multiset<int> ms;

    while(k--){
        int val;
        cin >> val;

        ms.insert(val);
    }
    long long sum = 0;

    for(auto itm = mm.rbegin(); itm != mm.rend(); itm++){
        auto it = ms.lower_bound(itm->second);
        if(it == ms.end()) continue;
        ms.erase(it);
        sum += itm->first;
        if(ms.empty()) break;
    }    
    

    cout << sum;
    
    return 0;
}