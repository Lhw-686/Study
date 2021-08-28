#include <iostream>
using namespace std;

/*
    从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删元素的值。
    空出的位置由最后一个元素填补，若顺序表为空，则显示出错信息并退出运行
*/

int s[100], n;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &s[i]);
    }
    return 0;
}