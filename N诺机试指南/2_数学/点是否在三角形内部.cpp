#include<iostream>
using namespace std;

typedef struct Point{
    int x, y;
    Point(int x, int y) : x(x), y(y) {} 
}Point;

int main(){
    int c, n = 0;
    cin >> c;
    while(c){
        c = c & (c-1);
        n++;
    }
    cout << n << endl;
    return 0;
}