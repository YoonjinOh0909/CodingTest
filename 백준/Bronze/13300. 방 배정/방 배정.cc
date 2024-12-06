#include <bits/stdc++.h>

using namespace std;

int totalStudent;
int maxS;
int student[12];
int main(void){
    cin >> totalStudent >> maxS;
    int gender = 0;
    int grade = 0;
    //여학생 0, 남학생 1
    for(int i = 0; i < totalStudent; i++){
        cin >> gender >> grade;
        student[2*(grade-1) + gender]++;
        /*
            1학년 여 0
            1학년 남 1
            2학년 여 2
            2학년 남 3 ...
        */
    }
    int needRoom = 0;
    for(int c : student){
        needRoom = needRoom + (c+1)/2;
    }
    cout<< needRoom;
    return 0;
}