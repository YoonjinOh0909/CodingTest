#include <bits/stdc++.h>

using namespace std;

deque<int> dq;
int n;
int hm;
int totalCnt = 0;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> hm;

    for(int i =1; i<=n; i++){
        dq.push_back(i);
    }

    while(hm--){
        int val; 
        cin >> val;

        int distance = find(dq.begin(), dq.end(), val) - dq.begin();
        if(dq.size() != distance){ //만약 size와 distance가 같다면, 해당 숫자가 dq에 없다는 뜻.
            if(distance <= dq.size()/2){ // 앞에서부터 하나씩 뒤로 보내기
                while(!dq.empty() && dq.front() != val){
                    int frnt = dq.front();
                    dq.pop_front();
                    dq.push_back(frnt);
                    totalCnt++;
                }
                dq.pop_front();
            }
            else{ // 뒤에서부터 하나씩 앞으로 보내기
                while(!dq.empty() && dq.front() != val){
                    int back = dq.back();
                    dq.pop_back();
                    dq.push_front(back);
                    totalCnt++;
                }
                dq.pop_front();
            }
        }        
        
        
    }
    cout << totalCnt;
    return 0;
}