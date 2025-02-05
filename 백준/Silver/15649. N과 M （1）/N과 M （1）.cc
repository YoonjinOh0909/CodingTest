#include <bits/stdc++.h>

using namespace std;

/*
    자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

    1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
*/

int N, M;
int arr[8] = {0,};
bool isused[9];

int func1(int cur){
    if(cur == M){
        for(int i = 0; i < M; i++){
            cout << arr[i] << ' ';
        }
        cout << "\n";
        return 0;
    }

    for(int i = 1; i < N+1; i++){
        if(!isused[i]){
            arr[cur] = i;
            isused[i] = 1;
            func1(cur+1);
            isused[i] = 0;
        }
    }


    return 0;
}

int main(void){
    
    cin >> N >> M;

    func1(0);

    return 0;
}