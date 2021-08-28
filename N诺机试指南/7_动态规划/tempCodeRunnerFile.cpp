#include<iostream>
using namespace std;

typedef struct Return{
    string s;
    int len;
    Return(){}
    Return(string s, int l) : s(s), len(l) {}
    bool operator < (const Return& R) const {return len < R.len;}
    //bool operator > (const Return& R) const {return len > R.len;}
}Return;
/*bool operator > (Return &a, Return &b){
    return a.len > b.len;
}*/

string s1, s2;

Return process(int index1, int index2){
    if(index1 < 0 || index2 < 0) return Return("", 0);
    Return R;
    if(s1[index1] == s2[index2]) {
        R = process(index1 - 1, index2 - 1);
        return Return(R.s + s1[index1], 1 + R.len);
    }
    R = max(process(index1 - 1, index2), process(index1, index2 - 1));
    return R;
}

int process2(int i1, int i2){
    if(i1 < 0 || i2 < 0) return 0;
    if(s1[i1] == s2[i2])
        return 1 + process2(i1-1,i2-1);
    return max(process2(i1-1,i2), process2(i1,i2-1));
}

int main(){
    cin >> s1 >> s2;
    Return R = process(s1.length() - 1, s2.length() - 1);
    cout << R.s << " " << R.len << endl;
    cout << process2(s1.length() - 1, s2.length() - 1);
    return 0;
}
/*
abecbab
bdcbabb
*/