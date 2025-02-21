#include <bits/stdc++.h>

using namespace std;

int n;
int main(void){
    cin >> n;
    
    for(int i =2; i<= n; i++){
        if(n == 1) break;
        while(n % i == 0){ //나눠떨어지면 다시 한 번.
            cout << i << "\n";
            n /= i;
        }
    }
    return 0;
}