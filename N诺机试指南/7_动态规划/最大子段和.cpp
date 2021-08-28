#include <iostream>
using namespace std;
const static int N = 100;
int s[N], n;

int process(int L, int R){
    if(L == R) return s[L];
    int mid = L + ((R - L) >> 1);
    //int mid = (L + R) / 2;
    int a = process(L, mid);
    int b = process(mid + 1, R);
    int maxL = 0, maxR = 0;
    int sum = 0;
    for(int i = mid; i >= L; i--){
        sum += s[i];
        maxL = max(maxL, sum);
    }
    sum = 0;
    for(int j = mid + 1; j <= R; j++){
        sum += s[j];
        maxR = max(maxR, sum);
    }
    return max(maxL + maxR, max(a, b));
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    cout << process(0, n-1) << endl;
    return 0;
}