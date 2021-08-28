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
            cout << "��ʼ���ɹ���" << endl;
            break;
        case 2:
            cout << isEmpty(Q) << endl;
            break;
        case 3:
            cout << "��������Ҫ��ӵ�Ԫ��ֵ:";
            cin >> e;
            flag = Push(Q, e);
            if(flag){
                cout << "��ӳɹ���" << endl;
            }else{
                cout << "���ʧ�ܣ�" << endl;
            }
            break;
        case 4:
            flag = Pop(Q, e);
            if (flag){
                cout << "���ӳɹ������ӵ�Ԫ��ֵΪ��" << e << endl;
            }else{
                cout << "����ʧ�ܣ�" << endl;
            }
            break;
        case 5:
            flag = GetHead(Q, e);
            if(flag){
                cout << "��ͷԪ��Ϊ��" << e << endl;
            }else{
                cout << "��ȡ��ͷԪ��ʧ�ܣ�" << endl;
            }
            break;
        case 0:
            run = false;
            cout << "�����˳���" << endl;
            break;
        default:
            cout << "���������������������룡" << endl;
            break;
        }
    }
    return 0;
}