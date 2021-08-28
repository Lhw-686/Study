#include<iostream>
#include<cstring>
using namespace std;

typedef struct BigInt{
    int digit[1000];
    int size;
    BigInt() {memset(digit, 0, sizeof digit); size = 0;}
    BigInt operator + (const BigInt &b) const{
        BigInt res;
        int offset = 0;
        for(int i = 0; i < size || i < b.size; i++){
            int tmp = digit[i] + b.digit[i] + offset;
            offset = tmp / 10;
            res.digit[res.size++] = tmp % 10;
        }
        if(offset){
            res.digit[res.size++] = offset;
        }
        return res;
    }
}BigInt;
istream& operator >> (istream& in, BigInt& a){
    string s;
    in >> s;
    for(int i = s.length() - 1; i >= 0; i--){
        a.digit[a.size++] = s[i] - '0';
    }
    return in;
}
ostream& operator << (ostream& out, BigInt& a){
        for(int i = a.size - 1; i >= 0; i--){
            out << a.digit[i]; 
        }
        return out;
}
int main(){
    BigInt a, b;
    cin >> a >> b;
    BigInt c = a+b;
    cout << c << endl;
    return 0;
}