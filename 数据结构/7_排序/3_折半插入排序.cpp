#include <iostream>
#define MAXSIZE 100
using namespace std;

int s[MAXSIZE], n;

void print(){
    for(int i = 0; i < n; i++){
        cout << s[i] << " ";
    }
    cout << endl;
}

int search(int L, int R, int e){
    int mid;
    while (L <= R){
        mid = (L + R) >> 1;
        if(e < s[mid]) R = mid - 1;
        else L = mid;
    }
    return L;
}

int search2(int L, int R, int e){
    int mid;
    while (L <= R){
        mid = (L + R + 1) >> 1;
        if(e > s[mid]) L = mid + 1;
        else R = mid - 1;
    }
    return L;
}

void insertSort(){
    for(int i = 1; i < n; i++){
        int temp = s[i];
        int loc = search2(0, i - 1, temp);
        for(int j = i - 1; j >= loc; j--){
            s[j+1] = s[j];
        }
        s[loc] = temp;
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    insertSort();
    print();
    return 0;
}