/*
    세 개의 장대가 있고 첫 번째 장대에는 반경이 서로 다른 n개의 원판이 쌓여 있다. 각 원판은 반경이 큰 순서대로 쌓여있다. 이제 수도승들이 다음 규칙에 따라 첫 번째 장대에서 세 번째 장대로 옮기려 한다.

    한 번에 한 개의 원판만을 다른 탑으로 옮길 수 있다.
    쌓아 놓은 원판은 항상 위의 것이 아래의 것보다 작아야 한다.
    이 작업을 수행하는데 필요한 이동 순서를 출력하는 프로그램을 작성하라. 단, 이동 횟수는 최소가 되어야 한다.

    아래 그림은 원판이 5개인 경우의 예시이다.
 */

#include <bits/stdc++.h>

using namespace std;

queue<pair<int,int>> Q;

int func1(int a, int b, int n){
    if(n==0) return 0;
    int x = func1(a, 6-a-b, n-1);
    // cout << a << ' ' << b << "\n";
    Q.push({a,b});
    int y = func1(6-a-b, b, n-1);

    return x + y + 1;
}

int main(void){
    int N;

    cin >> N;
    cout << func1(1,3,N) << "\n";
    while(!Q.empty()){
        pair<int, int> cur = Q.front();
        Q.pop();
        cout << cur.first << ' ' << cur.second <<"\n";
    }
    // cout << "total " << func1(1,3,N) << "\n";
    return 0;
}