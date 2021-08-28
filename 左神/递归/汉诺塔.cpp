#include <iostream>
using namespace std;
void process(int i, string from, string to, string other){
    if(i == 1){
        cout << i << " " << from << " -> " << to << endl; 
        return;
    }
    process(i-1, from, other, to);
    cout << i << " " << from << " -> " << to << endl; 
    process(i-1, other, to, from);

}

int main(){
    int n;
    cin >> n;
    process(n, "×ó", "ÓÒ", "ÖÐ");
    return 0;
}