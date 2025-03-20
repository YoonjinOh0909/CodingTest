#include <bits/stdc++.h>

using namespace std;

int arr[40] = {0,};
stack<pair<char,int>> sp;
string s;
int val = 0;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    int index = 0;
    for(char c : s){
        if(sp.empty()){
            sp.push({c,index});
        }else{
            if(sp.top().first == '(' && c == ')'){
                int midSum = 0;
                for(int i = sp.top().second+1; i < index; i++){
                    midSum += arr[i];
                    arr[i] = 0;
                }
                if(midSum == 0) arr[index] = 2;
                else{
                    arr[index] = 2*midSum;                    
                }
                sp.pop();
            }
            else if(sp.top().first == '[' && c == ']'){
                int midSum = 0;
                for(int i = sp.top().second+1; i < index; i++){
                    midSum += arr[i];
                    arr[i] = 0;
                }
                if(midSum == 0) arr[index] = 3;
                else{
                    arr[index] = 3*midSum;                    
                }
                sp.pop();
            }else{
                sp.push({c,index});
            }
        }

        index++;
    }

    for(int i =0; i< 31; i++){
        val += arr[i];
    }
    cout << (sp.empty() ? val : 0);
    return 0;
}