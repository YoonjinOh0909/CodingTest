#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    

    list<int> result = {};
    list<int>::iterator rc = result.begin();

    int howm = 0;
    int K = 0;
    int nowc = 0;
    int nextc = 0;
    cin >> howm >> K;

    int data[howm+1];
    int next[howm+1];
    int prev[howm+1];

    data[0] = -1;
    next[0] = 1;
    prev[0] = -1;

    for(int i = 1; i < howm + 1; i++){
        data[i] = i;
        if(i != howm){
            next[i] = i+1;
            if(i ==1){
                prev[i] = howm;
            }else{
                prev[i] = i-1;
            }
            
        }        
        else{
            next[i] = 1;
            prev[i] =i-1;
        }
        
    }

    while(result.size() != howm){
        for(int j = 0; j < K; j++){
            nextc = next[nowc];
            nowc = nextc;
        }

        result.push_back(data[nowc]);

        next[prev[nowc]] = next[nowc];
        prev[next[nowc]] = prev[nowc];

    }
    cout << '<';
    int index = 0;
    for(auto c : result){
        index++;
        cout << c;
        if(index != howm)
            cout << ", ";

    }
    cout << '>';

    return 0;
}