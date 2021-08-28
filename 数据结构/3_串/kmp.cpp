#include <iostream>
using namespace std;

int* getNextArr(char arr[], int n){
    int* nextArr = new int[n];
    nextArr[0] = -1;
    if(n == 1) return nextArr;
    nextArr[1] = 0;
    int cur = 0, i = 2;
    while(i < n){
        if(arr[i-1] == arr[cur]){
            cur++;
            if(arr[i] == arr[cur]) nextArr[i++] = nextArr[cur]; //ÓÅ»¯
            else nextArr[i++] = cur;
            //nextArr[i++] = ++cur;
        }else if(cur == 0){
            nextArr[i++] = 0;
        }else{
            cur = nextArr[cur];
        }
    }
    return nextArr;
}


int getIndexOf(char str1[], int n, char str2[], int m){
    if(n < m || m < 1) return -1;
    int i = 0, j = 0, *next = getNextArr(str2, m);
    while(i < n && j < m){
        if(str1[i] == str2[j]){
            i++, j++;
        }else if(j == 0){
            i++;
        }else{
            j = next[j];
        }
    }
    return j == m ? i - j : -1;
}

int main(){
    char str1[100], str2[100];
    int n, m;
    cin >> n;
    //getchar();
    for(int i = 0; i < n; i++) cin >> str1[i];
    getchar();
    //cout << str1 << endl;
    cin >> m;
    //getchar();
    for(int j = 0; j < m; j++) cin >> str2[j];
    cout << getIndexOf(str1, n, str2, m) << endl;
    return 0;
}