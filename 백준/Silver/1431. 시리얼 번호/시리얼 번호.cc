#include <bits/stdc++.h>

using namespace std;

/*
    A와 B의 길이가 다르면, 짧은 것이 먼저 온다.
    만약 서로 길이가 같다면, A의 모든 자리수의 합과 B의 모든 자리수의 합을 비교해서 작은 합을 가지는 것이 먼저온다. (숫자인 것만 더한다)
    만약 1,2번 둘 조건으로도 비교할 수 없으면, 사전순으로 비교한다. 숫자가 알파벳보다 사전순으로 작다.
*/
int n;
string arr[51];

bool cmp(const string& a, const string &b){
    if(a.size() < b.size()) return true;
    else if(a.size() > b.size()) return false;
    else{
        int a_val = 0;
        int b_val = 0;

        for (int i = 0; i < a.size(); i++){
            if(a[i] -'0' >= 0 && a[i] -'0' < 10){
                a_val += a[i] -'0';
            }
        }
        for (int i = 0; i < b.size(); i++){
            if(b[i] -'0' >= 0 && b[i] -'0' < 10){
                b_val += b[i] -'0';
            }
        }
        // cout << "a_val " << a_val << " b_val " <<b_val << "\n";
        if(a_val < b_val) return true;
        else if (a_val > b_val) return false;
        else {
            if(a<=b) return true;
            else return false;
        }
    }

    return false;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    // cin >> arr[0];

    // int d =0 ;
    // for (int i = 0; i < arr[0].size(); i++){
    //     if(arr[0][i] -'0' >= 0 && arr[0][i] -'0' < 10){
    //         // a_val += a[i] -'0';
    //         cout << arr[0][i] - '0';
    //         d += arr[0][i] - '0';
    //     }
    // }
    // cout << "\n";
    // cout << d << "\n";

    for(int i = 0; i < n ; i++){
        cin >> arr[i];
    }
    // sort(arr, arr+n);
    sort(arr, arr+n, cmp);

    for(int i = 0; i < n ; i++){
        cout <<  arr[i] << "\n";
    }
    return 0;
}