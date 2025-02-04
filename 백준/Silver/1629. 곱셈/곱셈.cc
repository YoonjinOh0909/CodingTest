//자연수 A를 B번 곱한 수를 알고 싶다. 단 구하려는 수가 매우 커질 수 있으므로 이를 C로 나눈 나머지를 구하는 프로그램을 작성하시오.

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll func1(ll a, ll b, ll c){
    if(b == 1) return a % c;
    ll prev = func1(a, b/2, c);
    ll val = prev * prev % c;

    if(b%2 == 0) return val;
    return val * a % c;
}



int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    ll x,y,z = 0;

    cin >> x >> y>> z;

    cout << func1(x,y,z);


    return 0;
}