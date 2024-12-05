#include <bits/stdc++.h>

using namespace std;

int main(void){
    int cnt = 0;
    cin >> cnt;
    int digit[100] = {};
    int minus_digit[101] = {};
    for(int i = 0 ; i < cnt ; i++){
        int a = 0;
        cin >> a;
        if(a > -1){
            digit[a]++;
        }
        else if (a < 0){
            a = a * -1;
            minus_digit[a]++;
        }
    }

    int research = 0;
    cin >> research;

    int answer = research > -1 ? digit[research] : minus_digit[research * -1];
    cout << answer;

    return 0 ;
}