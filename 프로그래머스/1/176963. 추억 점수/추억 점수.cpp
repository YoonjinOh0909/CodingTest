#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    unordered_map<string,int> nm;
    for(int i = 0 ; i < name.size(); i++){
        nm[name[i]] = yearning[i];
    }
    
    for(auto c : photo){
        int ans =0;
        for(auto e : c){
            ans += nm[e];
        }
        answer.push_back(ans);
    }
    return answer;
}