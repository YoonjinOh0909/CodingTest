#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    unordered_map<char, int> m;
    
    for(int i = 0 ; i < s.length(); i++){
        char v = s[i];
        
        if(m.find(v) == m.end()){ // 아직 안 나왔다면
            m.insert({v, i});
            answer.push_back(-1);
        }else{
            int diff = i - m[v];
            m[v] = i;
            answer.push_back(diff);
        }
    }
    return answer;
}