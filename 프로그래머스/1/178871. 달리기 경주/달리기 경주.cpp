#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
   unordered_map<string,int> playermap;
    
    for(int i = 0; i < players.size(); i++){
        playermap[players[i]] = i;
    }
    
    for(auto c : callings){
        int ind = playermap[c];
        swap(players[ind], players[ind-1]);
        playermap[c]= ind-1;
        playermap[players[ind]] = ind;
    }

    return players;
}