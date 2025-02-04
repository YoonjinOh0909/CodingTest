#include <bits/stdc++.h>

using namespace std;

int func1(int n, int r, int c){
    if(n == 1) return r*2 + c;
    int half = (1 << (n-1));

    if(r < half && c < half){ //좌측상단
        return func1(n-1, r, c);
    }
    else if(r < half && c >= half){ //우측 상단
        return half*half + func1(n-1, r, c - half);
    }
    else if(r >= half && c < half){ //좌측 하단
        return 2*half*half + func1(n-1, r - half, c);
    }
    else if(r >= half && c >= half){ //우측 하단
        return 3 * half*half + func1(n-1, r - half, c -half);
    }
    
}

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, r,c;

    cin >> N >> r >> c;

    cout << func1(N,r,c);

    return 0;
}