#include <iostream>
#define MAXSIZE 100
using namespace std;

// x < 10
void tox(int n, int x){
    int s[MAXSIZE];
    int i;
    for(i = 0; n > 0; i++){
        s[i] = n % x;
        n /= x;
    }
    while (i--){
        cout << s[i];
    }
    cout << endl;
}

// x > 10
void tox2(int n, int x){
    char s[MAXSIZE];
    int i;
    for(i = 0; n > 0; i++){
        int t = n % x;
        if(t < 10) s[i] = t + '0';
        else s[i] = (t - 10) + 'A';
        n /= x;
    }
    while (i--){
        cout << s[i];
    }
    cout << endl;
}

// x to 10
void xto(char x[], int n){
    int res = 0;
    for(int i = 0; x[i] != '\0'; i++){
        if(x[i] >= '0' && x[i] <= '9'){
            res = res * n + x[i] - '0';
        }else{
            res = res * n + x[i] - 'A' + 10;
        }
    }
    cout << res << endl;
}



int main(){
    int n, x;
    cin >> n >> x;
    //tox(n, x);
    tox2(n, x);
    char s[MAXSIZE];
    cin >> s;
    xto(s, 16); 
    return 0;
}