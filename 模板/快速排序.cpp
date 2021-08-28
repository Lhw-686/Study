#include<stdlib.h>
void quickSort(int s[], int l, int r){
    if(l >= r) return;
    swap(s[l + rand() % (r - l + 1)], s[r]);
    int i = l - 1, j = r + 1, x = s[r], cur = l;
    while(cur < j){
        if(s[cur] < x) swap(s[cur++], s[++i]);
        else if(s[cur] > x) swap(s[--j], s[cur]);
        else cur++;
    }
    quickSort(s, l, i), quickSort(s, j, r);
}