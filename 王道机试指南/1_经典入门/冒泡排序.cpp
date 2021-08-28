#include<iostream>
using namespace std;
const static int N = 10010;
int s[N], n;

void init(){
    scanf("%d",&n);
    for(int i = 0; i < n; i++) scanf("%d",&s[i]);
}

void bubbleSort(){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(s[j+1] < s[j]){
                swap(s[j+1], s[j]);
            }
        }
    }
}

void print(){
    for(int i = 0; i < n; i++){
        printf("%d ", s[i]);
    }
    printf("\n");
}

int main(){
    init();
    bubbleSort();
    print();
    return 0;
}