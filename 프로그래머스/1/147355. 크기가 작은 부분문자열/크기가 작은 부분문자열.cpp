#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int pl = p.length();
    
    for(int i = 0; i <= t.length() - pl; i++){
        string cs = t.substr(i, pl);
        
        bool addan = true;
        for(int j = 0; j < pl; j++){
            if(cs[j] < p[j]){ // p 더 큼
                break;
            }
            else if(cs[j] == p[j]){
                continue;
            }
            else if(cs[j] > p[j]){
                addan = false;
                break;
            }
        }
        
        if(addan){
            answer++;
        } 
    }
    return answer;
}