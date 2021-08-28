#include<iostream>
using namespace std;

int find(int L, int R, int num){
    int mid = (L + R) / 2;
    if(s[mid] == num) retrun mid;
    if(s[mid] < num) find(mid+1, R);
    else return find(L, mid-1);
}

int main(){
    int mid = -1;
    while(L <= R){
        mid = (L + R) / 2;
        if(s[mid] == num) break;
        if(s[mid] < num) L = mid+1;
        else R = mid - 1;
    }
    return 0;
}