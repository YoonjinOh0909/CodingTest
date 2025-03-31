#include <bits/stdc++.h>

using namespace std;

int n,m;

int arr[10] = {0,};
bool isused[10] = {0,};
int val[10] = {0,};

void func(int a){
    if(a == m){
        for(int i = 0 ; i < m; i++){
            cout << arr[i] << ' ';
        }
        cout << "\n";
        return;
    }

    for(int i = 0 ; i < n; i++){
        if(!isused[i]){
            isused[i] = 1;
            arr[a] = val[i];
            func(a+1);
            isused[i] = 0;
        }
    }

}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0 ; i < n; i++){
        cin >> val[i];
    }
    sort(val, val+n);

    func(0);
    return 0;
}