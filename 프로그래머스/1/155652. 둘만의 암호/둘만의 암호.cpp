#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    vector<int> sv;
    
    for(auto c : skip){
        sv.push_back(c-'a');
    }
    sort(sv.begin(), sv.end());
    
    for(auto c : s){
        int val = c - 'a';
        int next = 0;
        int ri = 0;
        
        while(ri < index){
            next++;
            int confirm = (val + next) % 26;
            if(find(sv.begin(), sv.end(), confirm) == sv.end()){
                ri++;        
            }
        }
        
        char an = (val + next) % 26 + 'a';
        answer += an;
    }
    return answer;
}