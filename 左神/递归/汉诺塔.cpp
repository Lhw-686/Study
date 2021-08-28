#include <iostream>
using namespace std;
int cnt = 0;
void process(int i, string from, string to, string other){
    if(i == 1){
        cout << i << " " << from << " -> " << to << endl;
        cnt++; 
        return;
    }
    process(i-1, from, other, to);
    cout << i << " " << from << " -> " << to << endl; cnt++;
    process(i-1, other, to, from);

}

int f(int n){
    if(n == 1) return 1;
    return 2*f(n-1)+1;
}

int main(){
    int n;
    cin >> n;
    process(n, "×ó", "ÓÒ", "ÖÐ");
    cout << f(n) << " " << cnt;
    return 0;
}