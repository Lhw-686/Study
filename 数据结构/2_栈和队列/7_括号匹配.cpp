#include <iostream>
#include <stack>
using namespace std;

stack<char> s;
char str[100];

bool process(){
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == '(' || str[i] == '[' || str[i] == '{') s.push(str[i]);
        else{
            if(s.empty() || (str[i] - s.top() != 1 && str[i] - s.top() != 2)) return false;
            else s.pop();
        }
    }
    return s.empty();
}

int main(){
    scanf("%s", str);
    if(process()) cout << "����ƥ��ɹ���" << endl;
    else cout << "����ƥ��ʧ�ܣ�" << endl;
    return 0;
}
