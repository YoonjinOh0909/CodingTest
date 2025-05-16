#include <bits/stdc++.h>

using namespace std;

int cnt, val;
vector<int> v;
vector<int> zv;

int main(void){

    while(1){
        cin >> cnt;
        if(cnt == 0) break;
        v.clear();
        zv.clear();

        for(int i = 0 ; i < cnt; i++){
            cin >> val;
            v.push_back(val);
            if(i < 6){
                zv.push_back(1);
            }else{
                zv.push_back(0);
            }
        }

        
        do{
            for(int i = 0 ; i < cnt ; i++){
                if(zv[i] == 1){
                    cout << v[i] << ' ';
                }
            }
            cout << "\n";
        }while(prev_permutation(zv.begin(), zv.end()));

        cout << "\n";
    }
    return 0;
}