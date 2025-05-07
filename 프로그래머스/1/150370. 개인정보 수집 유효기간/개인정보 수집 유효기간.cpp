#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void changeFormat(int& cy, int& cm, int& cd){
    if(cd <= 0){
        cd += 28;
        cm -= 1;
    }
    while(cm <= 0){
        cm += 12;
        cy -= 1;
    }
    while(cm > 12){
        cm -= 12;
        cy += 1;
    }
}
    
vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    unordered_map<char,int> um;
    
    for(auto t : terms){
        char ty = t[0];
        int m = stoi(t.substr(2, t.length()-2));
        
        um.insert({ty, m});
    }
    
    int index = 0;
    for(auto p : privacies){
        index++;
        char pty = p[p.length()-1];
        int m = um[pty];
        
        int year = stoi(p.substr(0,4));
        int month = stoi(p.substr(5,2));
        int date = stoi(p.substr(8,2));
        
        month += m;
        date -= 1;
        
        changeFormat(year, month, date);
        
        string strm = (month < 10) ? '0'+to_string(month) : to_string(month);
        string strd = (date < 10) ? '0'+to_string(date) : to_string(date);
        
        string posD = to_string(year) + '.' + strm + '.' + strd;
        cout << "posd " << posD << " today " << today << "\n";
        if(posD < today) answer.push_back(index);
    }
    
    return answer;
}