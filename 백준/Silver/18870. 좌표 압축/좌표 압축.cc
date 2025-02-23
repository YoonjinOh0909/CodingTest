#include <bits/stdc++.h>

using namespace std;
int n;
int arr[1000005] = {0,};
vector<int> tmp, uni;
int main(void){
  
    cin >> n;
    for(int i =0; i<n; i++){
        cin >> arr[i];
        tmp.push_back(arr[i]);
    }

    sort(tmp.begin(), tmp.end());

    for(int i =0; i < n; i++){
        if(i == 0 || tmp[i-1] != tmp[i]){
            uni.push_back(tmp[i]);
        }
    }
    

    for(int i =0; i<n; i++){
        cout << lower_bound(uni.begin(), uni.end(), arr[i]) - uni.begin() << ' ';
    }


    return 0;
}