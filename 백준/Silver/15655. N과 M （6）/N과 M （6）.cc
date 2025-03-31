#include <bits/stdc++.h>

using namespace std;

int n,m;
int arr[8] = {0,};
int val[8] = {0,};

int main(void){
    cin >> n >> m;

    for(int i = 0; i<n; i++){
        cin >> val[i];
        arr[i] = (i < m) ? 0 : 1;
    }

    sort(val, val+n);
    do{
        for(int i = 0; i < n; i++){
            if(arr[i] == 0){
                cout << val[i] << ' ';
            }
        }
        cout << "\n";
    }while(next_permutation(arr,arr+n));

}