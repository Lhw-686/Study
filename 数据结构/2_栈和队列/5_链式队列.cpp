#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct Node{
    ElemType data;
    Node* next;
    Node() : next(nullptr) {}
    Node(ElemType e) : data(e), next(nullptr) {}
    Node(ElemType e, Node* n) : data(e), next(n) {}
}Node;

typedef struct Queue{
    Node* front;
    Node* rear;
}Queue;

void InitQueue(Queue &Q){
    Q.front = new Node();
    Q.rear = Q.front;
}

bool isEmpty(Queue Q){
    return Q.front == Q.rear;
}

bool Push(Queue &Q, ElemType e){
    //cout << "before:" << Q.front->data << endl;
    Q.rear->next = new Node(e, NULL);
    Q.rear = Q.rear->next;
    cout << "after:" << Q.front->next->data << endl;
    return true;    
}

bool Pop(Queue &Q, ElemType &e){
    if(isEmpty(Q)) return false;
    Node* p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if(Q.rear == p){
        Q.rear = Q.front;
    }
    free(p);
    return true;
}

bool GetHead(Queue Q, ElemType &e){
    if(isEmpty(Q)) return false;
    e = Q.front->next->data;
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