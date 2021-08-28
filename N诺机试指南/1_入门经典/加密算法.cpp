#include <iostream>
#include <string.h>
#define MAXSIZE 100
using namespace std;

char s[MAXSIZE];

int main(){
    cin >> s;
    for(int i = 0; i < strlen(s); i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            s[i] = (s[i] - 'a' + 3) % 26 + 'a';
        }else if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = (s[i] - 'A' + 3) % 26 + 'A';
        }
    }
    cout << s << endl;
    return 0;
}