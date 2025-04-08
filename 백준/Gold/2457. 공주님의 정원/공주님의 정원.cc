#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int n;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    vector<pair<int,int>> flower;

    for(int i = 0 ; i < n ; i++){
        int stm, stda, enm, enda;
        cin >> stm >> stda >> enm >> enda;
        flower.push_back({stm*100+stda, enm*100 + enda});
    }

    int t = 301; // 3월 1일 시작이라서.
    int cnt = 0;

    while(t < 1201){
        int next_t = t;
        for(int i = 0 ; i < n; i++){
            if(flower[i].X <= t && flower[i].Y > next_t){
                next_t = flower[i].Y;
            }
        }

        if(next_t == t){ //값이 변하지 않았다는 뜻은 적절한 꽃이 없었다는 뜻
            cout << '0';
            return 0;
        }
        cnt++;
        t= next_t;
    }

    cout << cnt;
    return 0;
}