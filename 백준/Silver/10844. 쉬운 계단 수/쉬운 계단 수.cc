#include <bits/stdc++.h>

using namespace std;

long long board[101][10] = {0};
int n;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i =1; i<10;i++) board[1][i] = 1; // 일의 자리는 먼저 맞춰둔다.

    for(int i = 2; i <=n; i++){
        /*
            만약 board[2][3] 을 구하려면 board[1][2]의 개수 더하기 board[1][4]의 개수를 더하면 된다.
            왜냐하면 3으로 끝나려면 직전 숫자가 2 혹은 4여야하기 때문.
        */
        for(int j = 1; j < 10; j++){
            board[i][j] = (board[i-1][j-1] % 1000000000);
        }
        for(int j = 0; j < 9; j++){
            board[i][j] += (board[i-1][j+1] % 1000000000);
        }
    }

    long long sum = 0;
    for(int i = 0; i < 10; i++){
        sum += board[n][i];
    }

    cout << sum % 1000000000 << "\n";
    return 0;
}