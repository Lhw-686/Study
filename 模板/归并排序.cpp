
void mergeSort(int s[], int l, int r){
    if(l >= r) return;
    int mid = l + r >> 1;
    mergeSort(s, l, mid);
    mergeSort(s, mid + 1, r);
    int i = l, j = mid + 1, help[10010], cur = 0;;
    while(i <= mid && j <= r){
        if(s[i] <= s[j]) help[cur++] = s[i++];
        else help[cur++] = s[j++];
    }
    while(i <= mid) help[cur++] = s[i++];
    while(j <= r) help[cur++] = s[j++];
    for(i = 0, j = l; i < cur; i++, j++) s[j] = help[i];
}