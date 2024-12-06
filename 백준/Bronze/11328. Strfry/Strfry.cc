#include <bits/stdc++.h>

using namespace std;

int caseCnt;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //strfry가 되는지 확인해라. 그니깐 앞에 있는거랑 뒤에 있는거랑 문자 종류와 개수가 같니?
    cin >> caseCnt;
    string first = "";
    string second = "";

    // int a= 0;
    // cin >> a;
    // cout << a << caseCnt;
    while (caseCnt--)
    {
        bool isPossible = false;
        int alphabet[26] = {};
        first = "";
        second = "";

        cin >> first >> second;

        if(first.length() == second.length()){
            for(auto c : first){
                alphabet[c-'a']++;
            }
            for(auto c : second){
                alphabet[c-'a']--;
                if(alphabet[c-'a'] < 0){
                    isPossible = false;
                    break;                
                }else{
                    isPossible = true;
                }
            }
        }else{
            isPossible = false;
        }
        
        isPossible ? cout << "Possible\n" : cout << "Impossible\n";
    }
    
    return 0 ;
}