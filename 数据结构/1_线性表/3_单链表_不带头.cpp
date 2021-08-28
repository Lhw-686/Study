#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct Node{
    ElemType data;
    Node* next;
    Node() : next(nullptr) {}
    Node(ElemType e) : data(e), next(nullptr) {}
    Node(ElemType e, Node* n) : data(e), next(n) {}
}Node, *List;

void InitList(List &L){
    L = NULL;
}

int Length(List L){
    int length = 0;
    while(L){
        length++;
        L = L->next;
    }
    return length;
}

int LocateElem(List L, ElemType e){
    int loc = 0;
    while(L){
        loc++;
        if(L->data == e){
            return loc; 
        }
        L = L->next;
    }
    return -1;
}

int GetElem(List L, int i){
    int cur = 1;
    while(L){
        if(cur == i){
            return L->data;
        }
        cur++;
        L = L->next;
    }
    return -1;
}

bool Insert(List &L, ElemType e, int i){
    if(i == 1){
        L = new Node(e, L);
        return true;
    }
    int cur = 1;
    Node* p = L;
    while(p){
        if(cur + 1 == i){
            p->next = new Node(e, p->next);
            return true;
        }
        cur++;
        p = p->next;
    }
    return false;
}

bool Delete(List &L, ElemType &e, int i){
    if(i == 1){
        e = L->data;
        L = L->next;
        return true;
    }
    int cur = 1;
    Node* p = L;
    while(p && p->next){
        if(cur + 1 == i){
            e = p->next->data;
            p->next = p->next->next;
            return true;
        }
        cur++;
        p = p->next;
    }
    return false;
}

void Print(List L){
    while(L){
        cout << L->data << " ";
        L = L->next;
    }
    cout << endl;
}

void Destroy(List &L){
    while(L){
        Node* temp = L->next;
        free(L);
        L = temp;
    }
}

int main(){
    List L;
    bool run = true;
    while (run){
        cout << "====================" << endl;
        cout << "1.InitList" << endl;
        cout << "2.Length" << endl;
        cout << "3.LocateElem" << endl;
        cout << "4.GetElem" << endl;
        cout << "5.Insert" <<endl;
        cout << "6.Delete" << endl;
        cout << "7.Print" << endl;
        cout << "8.Destory" << endl;
        cout << "0.exit" << endl;
        cout << "====================" << endl;
        int order, i;
        ElemType e;
        cin >> order;
        switch (order){
        case 1:
            InitList(L);
            cout << "��ʼ���ɹ���" << endl;
            break;
        case 2:
            cout << Length(L) << endl;
            break;
        case 3:
            cout << "��������Ҫ��ѯ��Ԫ��ֵ:";
            cin >> e;
            i = LocateElem(L, e);
            if(i != -1){
                cout << "����Ԫ��λ��:" << i << endl;
            }else{
                cout << "�����ҵ�Ԫ�ز����ڣ�" << endl;
            }
            break;
        case 4:
            cout << "��������Ҫ��ѯ��λ��:";
            cin >> i;
            e = GetElem(L, i);
            if (e != -1){
                cout << "����λ��Ԫ��ֵ:" << e << endl;
            }else{
                cout << "�����ҵ�Ԫ�ز����ڣ�" << endl;
            }
            break;
        case 5:
            cout << "��������Ҫ�����λ��:";
            cin >> i;
            cout << "��������Ҫ�����Ԫ��ֵ:";
            cin >> e;
            if(Insert(L, e, i)){
                cout << "����ɹ���" << endl;
            }else{
                cout << "����ʧ�ܣ�" << endl;
            }
            break;
        case 6:
            cout << "��������Ҫɾ����Ԫ������λ��:";
            cin >> i;
            if(Delete(L, e, i)){
                cout << "ɾ���ɹ�����ɾ����Ԫ��ֵΪ:" << e << endl;
            }else{
                cout << "ɾ��ʧ�ܣ�" << endl;
            }
            break;
        case 7:
            Print(L);
            cout << "��ӡ��ϣ�" << endl;
            break;
        case 8:
            Destroy(L);
            cout << "���ٳɹ���" << endl;
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