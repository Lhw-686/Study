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



int main(){

    return 0;
}