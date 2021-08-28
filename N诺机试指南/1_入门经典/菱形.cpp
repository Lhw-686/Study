#include <iostream>
using namespace std;

int main(){
    int n, offset = -1;
    cin >> n;
    for(int i = n - 1; i != n; i += offset){
        for(int j = 0; j < i; j++){
            cout << " ";
        }
        for(int j = 0; j < 2 * (n-i) - 1; j++){
            cout << "*"; 
        }
        cout << endl;
        offset = i == 0 ? 1 : offset;
    }
    return 0;
}