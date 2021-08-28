#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct Node{
    ElemType data;
    Node* prior;
    Node* next;
    Node() : next(nullptr) {}
    Node(ElemType e) : data(e), next(nullptr), prior(nullptr) {}
    Node(ElemType e, Node* n, Node* p) : data(e), next(n), prior(p) {}
}Node;

typedef struct Queue{
    Node* front;
    Node* back;
}Queue;

void InitQueue(Queue &Q){
    Q.front = new Node();
    Q.back = Q.front;
}

bool isEmpty(Queue Q){
    return Q.front == Q.back;
}

bool PushBack(Queue &Q, ElemType e){
    Q.back->next = new Node(e, nullptr, Q.back);
    Q.back = Q.back->next;
    return true;
}

bool PushFront(Queue &Q, ElemType e){
    Node* temp = new Node(e, Q.front->next, Q.front);
    if(isEmpty(Q)){
        Q.back = temp;
    }
    else{
        Q.front->next->prior = temp;
    }
    Q.front->next = temp;
    return true;
}

bool PopBack(Queue &Q, ElemType &e){
    if(isEmpty(Q)) return false;
    Node* p = Q.back;
    e = p->data;
    Q.back = p->prior;
    Q.back->next = nullptr;
    free(p);
    return true;
}

bool PopFront(Queue &Q, ElemType &e){
    if(isEmpty(Q)) return false;
    Node* p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if(Q.back == p){
        Q.back = Q.front;
    }else{
        p->next->prior = Q.front;
    }
    free(p);
    return true;
}

bool GetFront(Queue Q, ElemType &e){
    if(isEmpty(Q)) return false;
    e = Q.front->next->data;
    return true;
}

bool GetBack(Queue Q, ElemType &e){
    if(isEmpty(Q)) return false;
    e = Q.back->data;
    return true;
}

void Print(Queue Q){
    Node* p = Q.front->next;
    while (p){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void PrintReverse(Queue Q){
    Node* p = Q.back;
    while(p && p != Q.front){
        cout << p->data << " ";
        p = p->prior;
    }
    cout << endl;
}

int main(){
    Queue Q;
    bool run = true;
    while (run){
        cout << "====================" << endl;
        cout << "1.InitQueue" << endl;
        cout << "2.isEempty" << endl;
        cout << "3.PushBack" << endl;
        cout << "4.PushFront" << endl;
        cout << "5.PopBack" << endl;
        cout << "6.PopFront" << endl;
        cout << "7.GetBack" <<endl;
        cout << "8.GetFront" <<endl;
        cout << "9.Print" << endl;
        cout << "10.PrintReverse" << endl;
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
            flag = PushBack(Q, e);
            if(flag){
                cout << "��ӳɹ���" << endl;
            }else{
                cout << "���ʧ�ܣ�" << endl;
            }
            break;
        case 4:
            cout << "��������Ҫ��ӵ�Ԫ��ֵ:";
            cin >> e;
            flag = PushFront(Q, e);
            if(flag){
                cout << "��ӳɹ���" << endl;
            }else{
                cout << "���ʧ�ܣ�" << endl;
            }
            break;
        case 5:
            flag = PopBack(Q, e);
            if (flag){
                cout << "���ӳɹ�����β��Ԫ��ֵΪ��" << e << endl;
            }else{
                cout << "����ʧ�ܣ�" << endl;
            }
            break;
        case 6:
            flag = PopFront(Q, e);
            if (flag){
                cout << "���ӳɹ�����ͷ��Ԫ��ֵΪ��" << e << endl;
            }else{
                cout << "����ʧ�ܣ�" << endl;
            }
            break;
        case 7:
            flag = GetBack(Q, e);
            if(flag){
                cout << "��βԪ��Ϊ��" << e << endl;
            }else{
                cout << "��ȡ��βԪ��ʧ�ܣ�" << endl;
            }
            break;
        case 8:
            flag = GetFront(Q, e);
            if(flag){
                cout << "��ͷԪ��Ϊ��" << e << endl;
            }else{
                cout << "��ȡ��ͷԪ��ʧ�ܣ�" << endl;
            }
            break;
        case 9:
            Print(Q);
            break;
        case 10:
            PrintReverse(Q);
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