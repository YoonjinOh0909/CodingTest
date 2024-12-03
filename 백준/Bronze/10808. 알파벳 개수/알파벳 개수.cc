#include <iostream>

using namespace std;

string x;
int a[26];
int main(void){
    cin >> x;
    for(int i=0; i < x.length(); i++){
        // cout << x[i]-97 << '\n';
        a[x[i]-97]++;
    }
    // int a = 0;
    for(int j =0; j < 26; j++) cout << a[j] << ' ';
    return 0;
}