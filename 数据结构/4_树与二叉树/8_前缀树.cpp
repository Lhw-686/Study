#include<iostream>
#include<algorithm>
using namespace std;

typedef struct Node{
    int cnt;
    int end;
    Node* ch[26];
    Node() : cnt(0), end(0) {
        for(int i = 0; i < 26; i++){
            ch[i] = NULL;
        }
    }
    Node(int cn) : cnt(cn) {}
}Node, *Tree;

int findMax(Tree &T){
    int res = -1;
    int maxCnt = 0;
    for(int i = 0; i < 26; i++){
        if(T->ch[i] != NULL && T->ch[i]->cnt > maxCnt){
            maxCnt = max(maxCnt, T->ch[i]->cnt);
            res = i;
        }
    }
    return res;
}

void insert(Tree &T, string s, int index){
    T->cnt++;
    //cout << T->cnt << endl;
    if(index >= s.length()){T->end++; return;}
    int child = s[index]-'a';
    if(T->ch[child] == NULL){
        T->ch[child] = new Node();
        //T = T->ch[child];
    }//else{
        //cout << child << "  " << T->ch[child]->cnt << endl;
    //}
    //cout << T->cnt << " " << child << " " << s[index] << endl;
    insert(T->ch[child], s, index+1);
}

bool find(Tree &T, string s){
    if(T->cnt == 0) return false;
    Node* p = T;
    int child;
    for(int i = 0; i < s.length(); i++){
        child = s[i]-'a';
        if(p->ch[child] != NULL){
            p = p->ch[child];
        }else{
            return false;
        }
    }
    cout << p->end << endl;
    return p->end != 0;
}

string findPre(Tree T){
    string s = "";
    int max = findMax(T);
    while(max != -1){
        
        int cnt = T->cnt;
        T = T->ch[max];
        //cout << s << " " << cnt << " "<< T->cnt << endl;
        if(T->cnt < cnt) break;s += 'a'+max;
        max = findMax(T);
    }
    return s;
}

int main(){
    Tree T = new Node();
    if(T == NULL) cout << "DAS" ;
    int n;
    string s;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        insert(T, s, 0);
    }
    cout << findPre(T) << endl;
    cout << T->ch[0]->ch[1]->ch[2]->end <<endl;
    return 0;
}