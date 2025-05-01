#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    
    int cur = num;
    int nextc = 0;
    bool isoddL = false;
    
    while(cur <= n){
        
        answer++;
        cout<< ((cur/w)%2) << ' ' << (cur%w) << "\n";
        if((cur%w) == 0){
            nextc = cur+1;
        }else{
           isoddL = (((cur/w)%2 == 0 && (cur%w) != 0) || ((cur/w)%2 == 1 && (cur%w) == 0)) ? true : false; 
            cout << cur << ' ' << isoddL << "\n";
            // 몫이 짝수이고 나머지가 0이 아니면 혹은 몫이 홀수이고 나머지가 0이면 홀수라인에 있는 것.

            nextc = isoddL ? 
                (cur + (w*2-(2*(cur%w)-1))) : 
                ((cur%w) == 0 ? cur+1: cur + (2*(w-cur%w)+1)); 
        }
        
        
        cur = nextc;
    }
    return answer;
}