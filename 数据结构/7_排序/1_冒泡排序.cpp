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

void bubbleSort1(){
    // 先排后
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < i; j++){
            if(s[j] > s[j+1]){
                swap(s[j], s[j+1]);
            }
        }
        print();
    }
}

void bubbleSort2(){
    // 先排前
    for(int i = 0; i < n - 1; i++){
        for(int j = n-1; j > i; j--){
            if(s[j] < s[j-1]){
                swap(s[j], s[j-1]);
            }
        }
        print();
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    bubbleSort1();
    cout << endl;
    return 0;
}