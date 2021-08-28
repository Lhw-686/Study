#include <iostream>
using namespace std;

typedef struct dat{
    int year;
    int month;
    int day;
    dat(int y, int m, int d) : year(y), month(m), day(d) {}
}dat;

int mo[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isleap(dat d){
    return (d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0;
}

bool isLegal(dat d){
    if(d.year < 0 || d.month < 1 || d.month > 12) return false;
    int offset = isleap(d) ? 1 : 0;
    mo[2] += offset;
    if(d.day < 1 || d.day > mo[d.month]) return false;
    return true;
}

int main(){
    int y, m ,d;
    cin >> y >> m >> d;
    dat* de = new dat(y, m, d);
    if(isLegal(*de)){
        int res = 0;
        for(int i = 1; i < de->month; i++){
            res += mo[i];
        }
        res += de->day;
        cout << res << endl;
    }else{
        cout << "Inputerror!" << endl;
    }
    return 0;
}