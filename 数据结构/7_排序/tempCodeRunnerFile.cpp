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

void insertSort(){
    int i, j;
    for(i = 1; i < n; i++){
        int temp = s[i];
        for(j = i - 1; s[j] > temp; j--){
            s[j+1] = s[j];
        }
        s[j+1] = temp;
        print();
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