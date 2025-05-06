#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    int height = wallpaper.size();
    int width = wallpaper[0].length();
    
    int maxX = -1;
    int maxY = -1;
    int minX = 51;
    int minY = 51;
    
    for(int i = 0; i< height; i++){
        for(int j = 0; j< width; j++){
            if(wallpaper[i][j] == '#'){
                maxX = max(i,maxX);
                maxY = max(j, maxY);
                minX = min(i,minX);
                minY = min(j, minY);
            }
        }
    }
    answer = {minX, minY, maxX+1, maxY+1};
    return answer;
}