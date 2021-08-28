
bool check1(int mid, int target){
    return mid >= target;
}

bool check2(int mid, int target){
    return mid <= target;
}

//区间划分[l, mid]和[mid + 1, r]
int binarySearch1(int s[], int l, int r, int target){
    while(l < r){
        int mid = l + r >> 1;
        if(check1(s[mid], target)) r = mid;
        else l = mid + 1;
    }
    return s[l] == target ? l : -1;;
}

//区间划分[l, mid - 1]和[mid, r]
int binarySearch2(int s[], int l, int r, int target){
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(check2(s[mid], target)) l = mid;
        else r = mid - 1;
    }
    return s[l] == target ? l : -1;;
}