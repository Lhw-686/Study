#include<stdlib.h>
void quickSort(int s[], int l, int r){
    if(l >= r) return;
    //���ѡȡһ������Ϊ����
    swap(s[l + rand() % (r - l + 1)], s[r]);
    //iΪС�ڲ��յı߽磬jΪ���ڲ��յı߽磬xΪ����
    int i = l - 1, j = r + 1, x = s[r], cur = l;
    while(cur < j){
        if(s[cur] < x) swap(s[cur++], s[++i]); //��߽�+1��cur+1
        else if(s[cur] > x) swap(s[--j], s[cur]);//�ұ߽�-1��cur����
        else cur++;
    }
    quickSort(s, l, i), quickSort(s, j, r);
}