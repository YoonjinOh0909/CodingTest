#include <bits/stdc++.h>

using namespace std;

int n;
#define X first
#define Y second

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while(n--){
        int val;
        cin >> val;

        pair<int,int> arr[41]; //X : 0이 출력되는 횟수, Y : 1이 출력되는 횟수

        arr[0] = {1, 0}; 
        arr[1] = {0, 1};

        for(int i = 2; i <= val; i++){
            arr[i].X = arr[i-1].X + arr[i-2].X;
            arr[i].Y = arr[i-1].Y + arr[i-2].Y;
        }

        cout << arr[val].X << ' ' << arr[val].Y << "\n";
        
    }

    return 0;
}