#include <stdio.h>
#include <iostream>
#define MAXSIZE 100

using namespace std;

typedef int ElemType;

typedef struct
{
    ElemType data[MAXSIZE];
    int length;
} List;

void InitList(List &L){
    L.length = 0;
}

int Length(List L){
    return L.length;
}

int LocateElem(List L, ElemType e){
    for(int i = 1; i <= L.length; i++){
        if (L.data[i] == e) return i;
    }
    return -1;
}

int GetElem(List L, int i){
    if (i > L.length || i <= 0) return -1;
    return L.data[i];
}

bool Insert(List &L, ElemType e, int i){
    if (L.length +1 == MAXSIZE || i <= 0 || i > L.length + 1) return false;
    for(int j = L.length; j >= i; j--){
        L.data[j+1] =L.data[j];
    }
    L.data[i] = e;
    L.length++;
    return true;
    
}

bool Delete(List &L, ElemType &e, int i){
    if (i > L.length || i <= 0) return false;
    e =L.data[i];
    for(int j = i; j < L.length; j++){
        L.data[j] =L.data[j+1];
    }
    L.length--;
    return true;
}

void Print(List L){
    for(int i = 1; i <= L.length; i++){
        cout <<L.data[i] << " ";
    }
    cout << endl;
}

void Destroy(List &L){
    L.length = 0;
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
            cout << "初始化成功！" << endl;
            break;
        case 2:
            cout << Length(L) << endl;
            break;
        case 3:
            cout << "请输入您要查询的元素值:";
            cin >> e;
            i = LocateElem(L, e);
            if(i != -1){
                cout << "所查元素位于:" << i << endl;
            }else{
                cout << "您查找的元素不存在！" << endl;
            }
            break;
        case 4:
            cout << "请输入您要查询的位置:";
            cin >> i;
            e = GetElem(L, i);
            if (e != -1){
                cout << "所查位置元素值:" << e << endl;
            }else{
                cout << "您查找的元素不存在！" << endl;
            }
            break;
        case 5:
            cout << "请输入您要插入的位置:";
            cin >> i;
            cout << "请输入您要插入的元素值:";
            cin >> e;
            if(Insert(L, e, i)){
                cout << "插入成功！" << endl;
            }else{
                cout << "插入失败！" << endl;
            }
            break;
        case 6:
            cout << "请输入您要删除的元素所在位置:";
            cin >> i;
            if(Delete(L, e, i)){
                cout << "删除成功！您删除的元素值为:" << e << endl;
            }else{
                cout << "删除失败！" << endl;
            }
            break;
        case 7:
            Print(L);
            cout << "打印完毕！" << endl;
            break;
        case 8:
            Destroy(L);
            cout << "销毁成功！" << endl;
            break;
        case 0:
            run = false;
            cout << "程序退出！" << endl;
            break;
        default:
            cout << "您的输入有误，请重新输入！" << endl;
            break;
        }
    }
    return 0;
}
