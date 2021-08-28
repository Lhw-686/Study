
bool check1(int mid, int target){
    return mid >= target;
}

bool check2(int mid, int target){
    return mid <= target;
}

//���仮��[l, mid]��[mid + 1, r]
int binarySearch1(int s[], int l, int r, int target){
    while(l < r){
        int mid = l + r >> 1;
        if(check1(s[mid], target)) r = mid;
        else l = mid + 1;
    }
    return s[l] == target ? l : -1;;
}

//���仮��[l, mid - 1]��[mid, r]
int binarySearch2(int s[], int l, int r, int target){
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(check2(s[mid], target)) l = mid;
        else r = mid - 1;
    }
    return s[l] == target ? l : -1;;
}