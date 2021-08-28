#include<iostream>
#include<stack>
#include <string>
using namespace std;

void add(stack<string> &s, double num){
    //cout << num << endl;
    if(s.empty() || s.top() == "+" || s.top() == "-"){
        s.push(to_string(num));
        return;
    }
    string op = s.top();s.pop();
    double a = stod(s.top());s.pop();
    num = op == "*" ? a*num : a/num;
    s.push(to_string(num));
}

double f(string s){
    stack<string> ss;
    double num = 0;
    for(int i = 0; i < s.length();i++){
        if(s[i] >= '0' && s[i] <= '9'){
            num = num * 10 + (s[i] - '0');
        }else{
            
            add(ss, num);
            num = 0;
            string sss;sss.push_back(s[i]);
            //cout << sss << endl;
            ss.push(sss);
        }
    }
    add(ss, num);
    while (ss.size() > 1){
        double b = stod(ss.top());ss.pop();
        string op = ss.top();ss.pop();
        double a = stod(ss.top());ss.pop();
        cout << a << op << b << " = ";
        a = op == "+" ? a+b : a-b;
        cout << a << endl;
        ss.push(to_string(a));
    }
    return stod(ss.top());
    
}

int main(){
    string s;
    //cout << to_string('+') << endl;
    cin >> s;
    cout << f(s) << endl;
    //stack<int>ss;
    //cout << ss.top() << endl;
    return 0;
}