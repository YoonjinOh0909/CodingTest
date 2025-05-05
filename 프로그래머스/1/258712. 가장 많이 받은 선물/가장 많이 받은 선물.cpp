#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    int sz = friends.size();
    vector<vector<int>> fm(sz, vector(sz,0));
    vector<int> giftGrade(sz,0);
    
    for(auto c : gifts){
        string f_1 = c.substr(0,c.find(" "));
        string f_2 = c.substr(c.find(" ")+1, c.length());
        
        int byf = find(friends.begin(), friends.end(), f_1)- friends.begin();
        int tof = find(friends.begin(), friends.end(), f_2)- friends.begin();
        
        fm[byf][tof]+=1;
    }
    
    for(int i = 0; i < sz; i++){
        int give = 0;
        int get = 0;
        
        for(int j = 0; j <sz; j++){
            give += fm[i][j];
            get += fm[j][i];
        }
        giftGrade[i] = give - get;
    }
    
    vector<int> nextmonth(sz,0);
    for(int i = 0; i < sz; i++){
        for(int j = i+1; j < sz; j++){
            if(fm[i][j] > fm[j][i]){
                nextmonth[i] += 1;
            }else if(fm[i][j] < fm[j][i]){
                nextmonth[j] += 1;
            }else{
                if(giftGrade[i] > giftGrade[j]){
                    nextmonth[i] += 1;
                }else if(giftGrade[i] < giftGrade[j]){
                    nextmonth[j] += 1;
                }
            }
        }
  
    }
    answer = *max_element(nextmonth.begin(), nextmonth.end());
    return answer;
}