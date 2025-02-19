#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int,int>> v;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second < b.second) return true;
    else return false;
}
int main(void){
    cin >> n;

    for(int i =0; i<n; i++){
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end());
    stable_sort(v.begin(), v.end(), cmp);

    int cnt = 0;
    int endT = 0;
    
    for(int i =0; i<n; i++){
        if(i == 0)    {
            endT = v[0].second; // 처음 끝나는 시간
            cnt = 1;
        }
        else{
            if(v[i].first >= endT){ // 시작시간이 이전 끝나는 시간보다 크거나 같다면
                cnt++;
                endT = v[i].second;
            }
        }
    }

    cout << cnt;
   
    return 0;
}