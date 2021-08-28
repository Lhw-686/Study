#include<iostream>
using namespace std;

int s[5000][13][32];
int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int offset;

typedef struct Date{
    int y, m, d;
    int isYeap(){
        if(m != 2) return 0;
        return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0 ? 1 : 0;
    }
    void nextDay(){
        d++;
        if(d > day[m] + isYeap()){
            d = 1;
            m++;
            if(m > 12){
                m = 1;
                y++;
            }
        }
    }
    Date() {}
    Date(int y, int m, int d) : y(y), m(m), d(d) {}
}Date;

int main(){
    int cnt = 0;
    Date t = Date(0,0,1);
    while(t.y != 5001){
        s[t.y][t.m][t.d] = cnt++;
        t.nextDay();
    }
    int y1,m1,d1;
    scanf("%4d %2d %2d", &y1, &m1, &d1);
    int y2,m2,d2;
    scanf("%4d %2d %2d", &y2, &m2, &d2);
    printf("%d\n", abs(s[y1][m1][d1] - s[y2][m2][d2])  + 1);
    return 0;
}