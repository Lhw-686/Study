#include <iostream>
using namespace std;

int main(){
    int s[100][100];
    int n;
    cin >> n;
    s[1][1] = 1;
    cout << s[1][1] << endl;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            s[i][j] = s[i-1][j] + s[i-1][j-1];
            cout << s[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}