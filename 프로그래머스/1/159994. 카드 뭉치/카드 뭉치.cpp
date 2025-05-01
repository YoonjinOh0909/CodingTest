#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    queue<string> c1q;
    queue<string> c2q;
    queue<string> gq;
    
    for(auto c : cards1){
        c1q.push(c);
    }
    
    for(auto c : cards2){
        c2q.push(c);
    }
    
    for(auto c : goal){
        gq.push(c);
    }
    answer = "Yes";
    while(!gq.empty()){
        auto cur = gq.front();
        if(c1q.front() == cur){
            c1q.pop();
            gq.pop();
            continue;
        }
        else if(c2q.front() == cur){
            c2q.pop();
            gq.pop();
            continue;
        }
        answer = "No";
        break;
    }
    return answer;
}