#include <iostream>
#define MAXSIZE 100
using namespace std;

int s[MAXSIZE], help[MAXSIZE], n;

void print(){
    for(int i = 0; i < n; i++){
        cout << s[i] << " ";
    }
    cout << endl;
}

void merge(int L, int R){
    int mid = (L + R) >> 1;
    int i = L, j = mid + 1, k = 0;
    while(i <= mid && j <= R){
        if(s[i] < s[j]){
            help[k++] = s[i++];
        }else{
            help[k++] = s[j++];
        }
    }
    while(i <= mid){
        help[k++] = s[i++];
    }
    while(j <= R){
        help[k++] = s[j++];
    }
    for(i = 0; i < k; i++){
        s[L++] = help[i];
    }
}

void mergeSort(int L, int R){
    if(L >= R) return;
    int mid = (L + R) >> 1;
    mergeSort(L, mid);
    mergeSort(mid + 1, R);
    merge(L, R);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    mergeSort(0, n-1);
    print();
    return 0;
}