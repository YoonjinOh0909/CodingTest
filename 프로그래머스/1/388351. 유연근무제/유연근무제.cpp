#include <string>
#include <vector>
#include <iostream>
using namespace std;

void changeTimeFormat(int& temp){
    int minv = temp % 100;
    int houv = temp / 100;
    
    if(minv >= 60){
        minv -= 60;
        houv += 1;
    }
    temp = houv * 100 + minv;
}
int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    int cnt = schedules.size();
    
    for(int i = 0; i < cnt; i++){
        int curSche = schedules[i];
        int after_10Sche = curSche + 10;
        
        
        changeTimeFormat(after_10Sche);
        cout << "cursche " << curSche << " after " << after_10Sche << "\n";
        int std = startday;
        bool ispossible = true;
        for(auto c : timelogs[i]){
            std++;
            if((std-1) % 7 == 6 || (std-1) % 7 == 0){
                continue;
            }
            ispossible = (c <=after_10Sche) ? true : false;
            if(!ispossible) break;
        }
        if(ispossible) answer++;
    }
    return answer;
}