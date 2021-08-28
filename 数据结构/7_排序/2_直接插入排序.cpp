#include <iostream>
#include <time.h>
#define MAXSIZE 100
using namespace std;

int s[MAXSIZE], n;

void print(){
    for(int i = 0; i < n; i++){
        cout << s[i] << " ";
    }
    cout << endl;
}

void insertSort(){
    int i, j;
    for(i = 1; i < n; i++){
        for(j = i - 1; j >= 0 && s[j] > s[j+1]; j--){
            swap(s[j], s[j+1]);
        }
        //print();
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