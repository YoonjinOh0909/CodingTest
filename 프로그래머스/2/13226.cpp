#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;

    vector<int> roadVec[n+1];
    
    for(auto c : roads){
        roadVec[c[0]].push_back(c[1]);
        roadVec[c[1]].push_back(c[0]); // 왕복이기 때문에 1 -> 2, 2 -> 1을 모두 진행
    }
    
    for(auto st : sources){
        vector<int> isvisited(n+1, -1);
        int startInd = st; // 시작 지점.
        queue<int> q;
        isvisited[startInd] = 0;
        q.push(startInd);
        
        while(!q.empty() && isvisited[destination] == -1){
            auto cur = q.front();
            q.pop();
            
            for(auto nxtInd : roadVec[cur]){
                if(isvisited[nxtInd] > -1) continue; // 이미 들린 곳
                
                isvisited[nxtInd] = isvisited[cur]+1;
                q.push(nxtInd);
            }
            
        }
        // cout << "isvisited ";
        // for(auto cc : isvisited){
        //     cout << cc << ' ';
        // }
        answer.push_back(isvisited[destination]);
    }
    return answer;
}
