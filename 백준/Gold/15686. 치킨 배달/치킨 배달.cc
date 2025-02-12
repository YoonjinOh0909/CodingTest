#include <bits/stdc++.h>

using namespace std;

// N(2 ≤ N ≤ 50)과 M(1 ≤ M ≤ 13)

/*
    ******제발 문제를 잘 읽자. 잘 읽고 분석하자*******
*/

int n,m; //n개의 줄과 m개의 최대 치킨 가게 수 (m의 개수를 구하는 것이 아니라 m이 주어지고 거기에 맞게 계산하는 것.)

//house의 정보를 받기 (x,y의 위치로 받을 것이기 때문에)
vector<pair<int,int>> house;

//치킨집의 정보를 받기
vector<pair<int,int>> chicken;

int board[51][51];

int main(void){
    cin >> n >> m; 

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
            if(board[i][j] == 1) house.push_back({i,j});
            if(board[i][j] == 2) chicken.push_back({i,j});
        }   
    }

    //chicken 집 개수만큼 vector 값 생성
    vector<int> chicken_per(chicken.size(),1);
    fill(chicken_per.begin(), chicken_per.end()-m,0); // 남길 치킨집 제외하고 나머지는 0으로 바꾼다.

    int mn = 0x7f7f7f7f;
    do{
        int totaldist = 0;

        //0일 때는 제거된 치킨집, 1일 때는 남은 치킨집이라 가정.
        for(int j = 0; j < house.size(); j++){
            int house_to_chicken = 0x7f7f7f7f;
            for(int i = 0; i< chicken_per.size(); i++){
                if(chicken_per[i] == 0) continue;
                int temp = 0;
                temp = abs(house[j].first - chicken[i].first) + abs(house[j].second - chicken[i].second);
                house_to_chicken = min(temp, house_to_chicken);
            }
            totaldist += house_to_chicken; 
        }
        
        //각 집에서 최솟값만 나왔을 때 합쳐준 것을 다시 최솟값을 뽑아낸다.

        mn = min(totaldist, mn);
    }while(next_permutation(chicken_per.begin(), chicken_per.end()));

    cout << mn;
    return 0;
}