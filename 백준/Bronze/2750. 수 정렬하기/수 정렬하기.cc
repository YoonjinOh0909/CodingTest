#include <bits/stdc++.h>

using namespace std;

int n;
int arr[1001] = {0,};
int temp[1001] = {0,};

void merge(int st, int en){
    int mid = (st + en) / 2;

    int lind = st; // 중간 기준 왼쪽 array의 시작 index
    int rind = mid; // 중간 기준 오른쪽 array의 시작 index

    for(int i = st; i < en; i++){
        if(rind >= en) temp[i] = arr[lind++];
        else if(lind >= mid) temp[i] = arr[rind++];
        else if(arr[lind] <= arr[rind]) temp[i] = arr[lind++];
        else temp[i] = arr[rind++];
    }

    for(int i = st; i < en; i++){
        arr[i] = temp[i];
    }

}

void merge_sort(int st, int en){
    if((en - st) == 1) return;

    int mid = (st+en)/2;

    merge_sort(st, mid);
    merge_sort(mid, en);

    merge(st, en);

    return;
}

int main(void){
    cin >> n;

    for(int i =0; i < n; i++){
        cin >> arr[i];
    }
    merge_sort(0,n);

    for(int i =0; i < n; i++){
        cout << arr[i] << "\n";
    }
    return 0;
}