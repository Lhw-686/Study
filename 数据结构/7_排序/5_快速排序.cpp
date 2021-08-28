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

void quickSort(int L, int R){
    if(L >= R) return;
    int i = L - 1, j = R + 1, temp = s[R];
    for(int k = L; k <= R - 1;){
        if(s[k] < temp) swap(s[k], s[i+1]), i++, k++;
        else if(s[k] > temp) swap(s[k], s[j-1]), j--;
        else k++;
    }
    quickSort(L, i);
    quickSort(j, R);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    quickSort(0, n-1);
    print();
    return 0;
}