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

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    
    print();
    return 0;
}