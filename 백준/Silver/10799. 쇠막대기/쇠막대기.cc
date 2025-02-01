#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;

    cin >> s;

    stack<char> st;
    int cnt = 0;
    bool prevOpen = false;
    for(char c : s){
        if( c == '('){
            st.push(c); 
            prevOpen = true;
        }
        else if(!st.empty() && c == ')'){
            st.pop();
            if(prevOpen){ // 직전에 열었고 지금 닫았으면 레이저를 뜻한다.
                cnt += st.size(); // 방금 자른 막대기 기준 왼쪽
            }else{ //prevOpen이 아닐때 막대기의 끝을 이야기한다.
                cnt += 1;
            }
            prevOpen = false;
        }
    }

    cout << cnt;

    return 0;
}