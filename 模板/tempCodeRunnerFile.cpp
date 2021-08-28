#include<iostream>
#include<vector>
#include<stdio.h>
#include<string>
using namespace std;
typedef struct BigInt{
    vector<int> digit;
    BigInt operator - (const BigInt& b) const{
        BigInt res;
        int i = 0, j = 0, t = 0, offset = 0;
        while(i < digit.size() && j < b.digit.size()){
            t = digit[i++] - offset - b.digit[j++];
            res.digit.push_back((t + 10) % 10);
            offset = t < 0 ? 1 : 0;
        }
        while(i < digit.size()){
            t = digit[i++] - offset;
            res.digit.push_back((t + 10) % 10);
            offset = t < 0 ? 1 : 0;
        }
        while(res.digit.back() == 0){
            res.digit.pop_back();
        }
        if(res.digit.size() == 0) res.digit.push_back(0);
        return res;
    };
    bool operator > (const BigInt& b) const{
        if(digit.size() > b.digit.size()) return true;
        if(digit.size() < b.digit.size()) return false;
        if(digit.size() == b.digit.size()){
            for(int i = digit.size() - 1; i >= 0 ; i--){
                if(digit[i] > b.digit[i]) return true;
                else if(digit[i] < b.digit[i]) return false;
            }
        }
        return false;
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
    if(b > a){
        swap(a, b);
        printf("-");
    }
    BigInt c = a - b;
    for(int i = c.digit.size() - 1; i >= 0; i--){
        printf("%d", c.digit[i]);
    }
    printf("\n");
    return 0;
}