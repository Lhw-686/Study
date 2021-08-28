#include<iostream>
#include<queue>
using namespace std;

priority_queue<int> lessQ;
priority_queue<int, vector<int>, greater<int>> greatQ;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int j;
        cin >> j;
        greatQ.push(j);
    }
    int ans = 0;
    while(greatQ.size() > 1){
        int b = greatQ.top();greatQ.pop();
        int a = greatQ.top();greatQ.pop();
        ans = ans + a+b;
        greatQ.push(a+b);
    }
    cout << ans << endl;
     return 0;
}