#include <iostream>
#define MAXSIZE 100
using namespace std;

typedef int ElemType;

typedef struct{
    ElemType data[MAXSIZE];
    int front;
    int rear;
}Queue;

void InitQueue(Queue &Q){
    Q.front = Q.rear = 0;
}

bool isEmpty(Queue Q){
    return Q.front == Q.rear;
}

bool Push(Queue &Q, ElemType e){
    if(Q.rear + 1 == MAXSIZE) return false;
    Q.data[++Q.rear] = e;
    return true;
}

bool Pop(Queue &Q, ElemType &e){
    if(isEmpty(Q)) return false;
    e = Q.data[++Q.front];
    return true;
}

bool GetHead(Queue Q, ElemType &e){
    if(isEmpty(Q)) return false;
    e = Q.data[Q.front+1];
    return true;
}

int main(){
    Queue Q;
    bool run = true;
    while (run){
        cout << "====================" << endl;
        cout << "1.InitQueue" << endl;
        cout << "2.isEempty" << endl;
        cout << "3.Push" << endl;
        cout << "4.Pop" << endl;
        cout << "5.GetHead" <<endl;
        cout << "0.exit" << endl;
        cout << "====================" << endl;
        int order, i;
        ElemType e;
        bool flag;
        cin >> order;
        switch (order){
        case 1:
            InitQueue(Q);
            cout << "初始化成功！" << endl;
            break;
        case 2:
            cout << isEmpty(Q) << endl;
            break;
        case 3:
            cout << "请输入您要入队的元素值:";
            cin >> e;
            flag = Push(Q, e);
            if(flag){
                cout << "入队成功！" << endl;
            }else{
                cout << "入队失败！" << endl;
            }
            break;
        case 4:
            flag = Pop(Q, e);
            if (flag){
                cout << "出队成功！出队的元素值为：" << e << endl;
            }else{
                cout << "出队失败！" << endl;
            }
            break;
        case 5:
            flag = GetHead(Q, e);
            if(flag){
                cout << "队头元素为：" << e << endl;
            }else{
                cout << "获取队头元素失败！" << endl;
            }
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