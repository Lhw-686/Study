#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct Node{
    ElemType data;
    Node* next;
    Node() : next(nullptr) {}
    Node(ElemType e) : data(e), next(nullptr) {}
    Node(ElemType e, Node* n) : data(e), next(n) {}
}Ndoe, *Stack;

void InitStack(Stack &S){

}

bool isEmpty(Stack S){

}

bool Push(Stcak &S, ElemType e){

}

bool Pop(Stcak &S, ElemType &e){

}

bool Top(Stack S, ElemType &e){

}

void Destroy(Stack S){
    
}

int main(){

    return 0;
}