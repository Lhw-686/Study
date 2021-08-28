#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct Node
{
    ElemType data;
    Node *next;
    Node(ElemType data){
        this->data = data;
        next = NULL;
    }
    Node(){
        next = NULL;
    }

}Node, *List;

void InitList(List &L){
    L = new Node();    
}

int Length(List L){

}

int LocateElem(List L, ElemType e){
    Node *p = L->next;
    int i = 0;
    while(p){
        i++;
        if(p->data == e){
            return i; 
        }
        p = p->next;
    }
    return -1;
}

int GetElem(List L, int i){
    Node *p = L->next;
    while(p){
        i--;
        if(i == 0){
            return p->data;
        }
        p = p->next;
    }
    return -1;
}

bool Insert(List &L, ElemType e, int i){
    Node *p = L;
    int j = 0;
    do{
        if(j + 1 == i){
            Node *temp = new Node(e);
            temp->next = p->next;
            p->next = temp;
            return true;
        }
        p = p->next;
        j++;
    }while(p);
    return false;
}

bool Delete(List &L, ElemType &e, int i){
    Node *p = L;
    while(p && p->next){
        i--;
        if(i == 0){
            e = p->next->data;
            p->next = p->next->next;
            //free(p->next);
            return true;
        }
        p = p->next;
    }
    return false;
}

void Print(List L){
    Node *p = L->next;
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void Destroy(List &L){
    Node *p = L->next;
    while(p){
        Node *temp = p->next;
        free(p);
        p = temp;
    }
    L->next = NULL;
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