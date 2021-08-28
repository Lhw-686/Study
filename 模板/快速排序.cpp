#include<stdlib.h>
void quickSort(int s[], int l, int r){
    if(l >= r) return;
    //随机选取一个数作为参照
    swap(s[l + rand() % (r - l + 1)], s[r]);
    //i为小于参照的边界，j为大于参照的边界，x为参照
    int i = l - 1, j = r + 1, x = s[r], cur = l;
    while(cur < j){
        if(s[cur] < x) swap(s[cur++], s[++i]); //左边界+1，cur+1
        else if(s[cur] > x) swap(s[--j], s[cur]);//右边界-1，cur不变
        else cur++;
    }
    quickSort(s, l, i), quickSort(s, j, r);
}