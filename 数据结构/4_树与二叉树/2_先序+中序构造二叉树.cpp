#include <iostream>
using namespace std;

typedef char ElemType;

typedef struct Node{
    ElemType data;
    Node* left, *right;
    Node() : left(nullptr), right(nullptr) {}
    Node(ElemType e) : data(e), left(nullptr), right(nullptr) {}
    Node(ElemType e, Node* l, Node* r) : data(e), left(l), right(r) {}
}Node, *Tree;

char preOrder[100], inOrder[100];
int n;

void bulid(Tree &T, int L1, int R1, int L2, int R2){
    if(L1 > R1 || L2 > R2 || R1 >= n || R2 >= n) return;
    T = new Node(preOrder[L1]);
    for(int i = L2; i <= R2; i++){
        if(preOrder[L1] == inOrder[i]){
            bulid(T->left, L1+1, L1+i-L2, L2, i-1);
            bulid(T->right, L1+i-L2+1, R1, i+1, R2);
            break;
        }
    }
}

void postOrder(Tree T){
    if(T == nullptr) return;
    postOrder(T->left);
    postOrder(T->right);
    cout << T->data << " ";
}

int main(){
    Tree T;
    cin >> n;
    scanf("%s", preOrder);
    cout << preOrder << endl;
    scanf("%s", inOrder);
    cout << inOrder << endl;
    cout << "n:" << n << endl;
    bulid(T, 0, n-1, 0, n-1);
    postOrder(T);
    return 0;
}
/*FCA##DB###EH##GM###
F C A D B E H G M 
F C A D B E H G M
A B D C H M G E F
A B D C H M G E F
A C B D F H E M G
A C B D F H E M G
F C E A D H G B M*/
/*
9
FCADBEHGM
ACBDFHEMG
*/