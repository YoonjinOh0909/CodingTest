#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> num;
vector<int> oper;

int maxv = -1000000000;
int minv = 1000000000;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    int val;
    while(n--){
        cin >> val;
        num.push_back(val);
    }

    for(int i = 0; i < 4; i++){
        cin >> val;
        for(int j = 0 ; j < val ; j++){
            oper.push_back(i);
        }
    }

    do{
        int curval = 0;
        int nextval = 0;

        curval = num[0];

        for(int i = 0 ; i < num.size()-1; i++){
            nextval = num[i+1];
            if(oper[i] == 0){ // 덧셈
                curval += nextval;
            }else if(oper[i] == 1){ // 뺄셈
                curval -= nextval;
            }else if(oper[i] == 2){ // 곱셈
                curval *= nextval;
            }else{ //나눗셈
                curval /= nextval;
            }
        }

        minv = min(minv, curval);
        maxv = max(maxv, curval);
    }while(next_permutation(oper.begin(), oper.end()));

    cout << maxv << "\n";
    cout << minv << "\n";
    return 0;
}