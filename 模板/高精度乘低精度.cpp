#include<iostream>
#include<vector>
#include<stdio.h>
#include<string>
using namespace std;
// 高精度×低精度
typedef struct BigInt{
    vector<int> digit;
    BigInt operator * (const int& b) const{
        BigInt res;
        int i = 0, j = 0, t = 0, offset = 0;
        while(i < digit.size() || t){
            if(i < digit.size()) t += digit[i]*b;
            res.digit.push_back(t % 10);
            t /= 10;
        }
        for(int i = res.digit.size() - 1; i > 0; i--){
            if(res.digit[i] != 0) break;
            res.digit.pop_back();
        }
        return res;
    };
}BigInt;
string s;
int main(){
    BigInt a;
    int b;
    cin >> s;
    int len = s.length();
    for(int i = len - 1; i >= 0; i--){
        a.digit.push_back(s[i]-'0');
    }
    cin >> b;
    BigInt c = a * b;
    for(int i = c.digit.size() - 1; i >= 0; i--){
        printf("%d", c.digit[i]);
    }
    printf("\n");
    return 0;
}