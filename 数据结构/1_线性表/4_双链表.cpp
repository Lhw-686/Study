#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct Node{
    ElemType data;
    Node* prior;
    Node* next;
    Node() : prior(nullptr), next(nullptr) {}
    Node(ElemType e) : data(e), prior(nullptr), next(nullptr) {}
    Node(ElemType e, Node* p, Node* n) : data(e), prior(p), next(n) {}
}Node, *List;

bool Insert(List &L, ElemType e, int i){
    Node* p = L;
    while(p){
        i--;
        if(i == 0){
            p->next = new Node(e, p, nullptr);
            return true;
        }
        p = p->next;
    }
    return false;
}

bool Delete(List &L, Element &e, int i){
    Node* p = L;
    while(p){
        i--;
        if(i == 0){
            Node* q = p->next;
            p->next->next->prior = p;
            p->next = p->next->next;
            free(q);
            return true;
        }
        p = p->next;
    }
    return false;
}

int main(){
    
    return 0;
}