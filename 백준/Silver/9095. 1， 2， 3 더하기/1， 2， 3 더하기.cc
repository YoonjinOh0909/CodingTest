#include <bits/stdc++.h>

using namespace std;

int arr[12] = {0,};
int n;
int main(void){
    /*
        테의블 정의
        D[i]= i를 1,2,3의 합으로 나타낸 방법의 수

        점화식 찾기
        D[4] = D[1]+D[2] + D[3];

        1 (+3)
        1 + 1 (+2)
        2 (+2)
        1+1+1 (+1)
        1+2 (+1)
        2+1 (+1)
        3 (+1)

        하면 4를 나타낼 수 있는 7가지의 방법이 생긴다.

        초기값 설정
        D[1] = 1
        D[2] = 2
        D[3] = 4
    */
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;

    while(n--){
        int ln = 0;
        cin >> ln;

        if(arr[ln] != 0){
            cout << arr[ln] << "\n";
            continue;
        }

        for(int i = 4; i <= ln; i++){
            arr[i] = arr[i-3] + arr[i-2] + arr[i-1];
        }

        cout << arr[ln] << "\n";
    }
    
    return 0;    
}