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

void heapInsert(int i){
    while(s[i] > s[(i - 1) / 2]){
        swap(s[i], s[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapify(int i, int heapSize){
    int L = 2 * i + 1;
    while (L < heapSize){
        int bigLoc = L + 1 < heapSize && s[L+1] > s[L] ? L + 1 : L;
        if(s[i] < s[bigLoc]){
            swap(s[i], s[bigLoc]);
            i = bigLoc;
            L = 2 * i + 1;
        } else {
            break;
        }
    }
}

void heapSort(){
    for(int i = 0; i < n; i++){
        heapInsert(i);
    }
    int heapSize = n;
    do{
        swap(s[0], s[--heapSize]);
        heapify(0, heapSize);
    }while (heapSize);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    heapSort();
    print();
    return 0;
}