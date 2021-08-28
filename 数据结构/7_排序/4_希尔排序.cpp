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

void shellSort(){
    int d = n / 2;
    while(d){
        int i, j;
        for(i = d; i < n; i += d){
            for(j = i - d; j >= 0 && s[j] > s[j+d]; j -= d){
                    swap(s[j], s[j+d]);
            }
        }
        d /= 2;
        //print();
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    shellSort();
    print();
    return 0;
}