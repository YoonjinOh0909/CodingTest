#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    sort(book_time.begin(), book_time.end());
    vector<int> roomend;
    
    for(auto b : book_time){
        int startT = stoi(b[0].substr(0,2)) * 100 + stoi(b[0].substr(3,2));
        int prevM = stoi(b[1].substr(3,2)) + 10;
        int tempH = 0;
        
        tempH = prevM / 60;
        prevM = prevM % 60;
        
        
        int endT = (stoi(b[1].substr(0,2)) + tempH) * 100 + prevM;
        
        cout << "starT " << startT << " endT " << endT << "\n";
        bool ischange = false;
        
        if(roomend.size() == 0){
            roomend.push_back(endT);
        }else{
            for(int i = 0; i < roomend.size(); i++){
                if(startT >= roomend[i]){
                    roomend[i] = endT;
                    ischange = true;
                    break;
                }
            }
            if(!ischange) roomend.push_back(endT);
            sort(roomend.begin(), roomend.end());
        }
        
    }
    
    return roomend.size();
}