#include <iostream>
#define MAXSIZE 100
using namespace std;

typedef int ElemType;

typedef struct {
    ElemType data[MAXSIZE];
    int top;
}Stack;

void InitStack(Stack &S){
    S.top = -1;
}

bool isEmpty(Stack S){
    return S.top == -1;
}

bool Push(Stack &S, ElemType e){
    if(S.top + 1 == MAXSIZE) return false;
    S.data[++S.top] = e;
    return true;
}

bool Pop(Stack &S, ElemType &e){
    if(isEmpty(S)) return false;
    e = S.data[S.top--];
    return true;
}

bool Top(Stack S, ElemType &e){
    if(S.top == -1) return false;
    e = S.data[S.top];
    return true;
}

void Destroy(Stack S){
    S.top = -1;
}


int main(){
    Stack S;
    bool run = true;
    while (run){
        cout << "====================" << endl;
        cout << "1.InitStack" << endl;
        cout << "2.isEempty" << endl;
        cout << "3.Push" << endl;
        cout << "4.Pop" << endl;
        cout << "5.GetTop" <<endl;
        cout << "6.Destroy" << endl;
        cout << "0.exit" << endl;
        cout << "====================" << endl;
        int order, i;
        ElemType e;
        bool flag;
        cin >> order;
        switch (order){
        case 1:
            InitStack(S);
            cout << "初始化成功！" << endl;
            break;
        case 2:
            cout << isEmpty(S) << endl;
            break;
        case 3:
            cout << "请输入您要入栈的元素值:";
            cin >> e;
            flag = Push(S, e);
            if(flag){
                cout << "入栈成功！" << endl;
            }else{
                cout << "入栈失败！" << endl;
            }
            break;
        case 4:
            flag = Pop(S, e);
            if (flag){
                cout << "出栈成功！出栈的元素值为：" << e << endl;
            }else{
                cout << "出栈失败！" << endl;
            }
            break;
        case 5:
            flag = Top(S, e);
            if(flag){
                cout << "栈顶元素为：" << e << endl;
            }else{
                cout << "获取栈顶元素失败！" << endl;
            }
            break;
        case 6:
            Destroy(S);
            cout << "销毁完毕！" << endl;
            break;
        case 0:
            run = false;
            cout << "程序退出！" << endl;
            break;
        default:
            cout << "您的输入有误，请重新输入！" << endl;
            break;
        }
    }
    return 0;
}