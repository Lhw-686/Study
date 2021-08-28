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

void selectSort(){
    for(int i = 0; i < n; i++){
        int loc = i;
        for(int j = i + 1; j < n; j++){
            loc = s[j] < s[loc] ? j : loc;
        }
        swap(s[loc], s[i]);
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    selectSort();
    print();
    return 0;
}