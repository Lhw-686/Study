#include<iostream>
#include<vector>
#include<stdio.h>
#include<string>
using namespace std;
typedef struct BigInt{
    vector<int> digit;
    BigInt operator + (const BigInt& b) const{
        BigInt res;
        int i = 0, j = 0, t = 0, offset = 0;
        while(i < digit.size() && j < b.digit.size()){
            t = digit[i++] + b.digit[j++] + offset;
            res.digit.push_back(t % 10);
            offset = t / 10;
        }
        while(i < digit.size()){
            t = digit[i++] + offset;
            res.digit.push_back(t % 10);
            offset = t / 10;
        }
        while(j < b.digit.size()){
            t = b.digit[j++] + offset;
            res.digit.push_back(t % 10);
            offset = t / 10;
        }
        if(offset) res.digit.push_back(offset);
        return res;
    }
}BigInt;
string s;
int main(){
    BigInt a, b;
    cin >> s;
    int len = s.length();
    for(int i = len - 1; i >= 0; i--){
        a.digit.push_back(s[i]-'0');
    }
    cin >> s;
    len = s.length();
    for(int i = len - 1; i >= 0; i--){
        b.digit.push_back(s[i]-'0');
    }
    BigInt c = a + b;
    for(int i = c.digit.size() - 1; i >= 0; i--){
        printf("%d", c.digit[i]);
    }
    printf("\n");
    return 0;
}