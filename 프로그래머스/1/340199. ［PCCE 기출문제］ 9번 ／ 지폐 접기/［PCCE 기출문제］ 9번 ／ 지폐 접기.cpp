#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    int index = 0;
    while(1){
        
        if((bill[0] <= wallet[0] && bill[1] <= wallet[1]) || (bill[0] <= wallet[1] && bill[1] <= wallet[0])){
            break;
        }
        
        answer++;
        index = bill[0] >= bill[1] ? 0 : 1;
        bill[index] /= 2;
        
    }
    
    return answer;
}