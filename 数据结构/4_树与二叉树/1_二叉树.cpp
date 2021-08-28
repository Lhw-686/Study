#include <iostream>
#include <stack>
#include <deque>
using namespace std;

typedef char ElemType;

typedef struct Node{
    ElemType data;
    Node* left, *right;
    Node() : left(nullptr), right(nullptr) {}
    Node(ElemType e) : data(e), left(nullptr), right(nullptr) {}
    Node(ElemType e, Node* l, Node* r) : data(e), left(l), right(r) {}
}Node, *Tree;

void bulid(Tree &T){
    char e;
    cin >> e;
    if(e == '#'){
        T = nullptr;
    }else{
        T = new Node(e);
        bulid(T->left);
        bulid(T->right);
    }
}

void perOrder(Tree T){
    if(T == nullptr) return;
    cout << T->data << " ";
    perOrder(T->left);
    perOrder(T->right);
}

void perOrder2(Tree T){
    if(T == nullptr) return;
    stack<Node*> s;
    s.push(T);
    while(!s.empty()){
        Node* top = s.top();
        cout << top->data << " ";
        s.pop();
        if(top->right != nullptr){
            s.push(top->right);
        }
        if(top->left != nullptr){
            s.push(top->left);
        }
    }
    cout << endl;
}

void inOrder(Tree T){
    if(T == nullptr) return;
    inOrder(T->left);
    cout << T->data << " ";
    inOrder(T->right);
}
// 左边界头右（左边界头）
void inOrder2(Tree T){
    if(T == nullptr) return;
    stack<Node*> s;
    while(!s.empty() || T){
        if(T){
            s.push(T);
            T = T->left;
        }else{
            cout << s.top()->data << " ";
            T = s.top()->right;
            s.pop();
        }
    }
    cout << endl;
}

void postOrder(Tree T){
    if(T == nullptr) return;
    postOrder(T->left);
    postOrder(T->right);
    cout << T->data << " ";
}

void postOrder2(Tree T){
    if(T == nullptr) return;
    stack<Node*> s, help;
    help.push(T);
    while(!help.empty()){
        Node* top = help.top();
        s.push(top);
        help.pop();
        
        if(top->left != nullptr){
            help.push(top->left);
        }
        if(top->right != nullptr){
            help.push(top->right);
        }
    }
    while(!s.empty()){
        //cout << "daw" << endl;
        cout << s.top()->data << " ";
        s.pop();
    }
    cout << endl;
}

void levelOrder(Tree T){
    if(T == nullptr) return;
    deque<Node*> q;
    q.push_back(T);
    while(!q.empty()){
        T = q.front();
        cout << T->data << " ";
        q.pop_front();
        if(T->left){
            q.push_back(T->left);
        }
        if(T->right){
            q.push_back(T->right);
        }
    }
    cout << endl;
}

int depth(Tree T){
    if(T == nullptr) return 0;
    return max(depth(T->left), depth(T->right)) + 1;
}

int main(){
    Tree T;
    bulid(T);
    perOrder(T);
    cout << endl;
    perOrder2(T);
    postOrder(T);
    cout << endl;
    postOrder2(T);
    inOrder(T);
    cout << endl;
    inOrder2(T);
    levelOrder(T);
    cout << depth(T) << endl;
    return 0;
}
//FCA##DB###EH##GM###