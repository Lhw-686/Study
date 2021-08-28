bool check(double mid, double target){
    return mid <= target;
}

double binarySearch(double l, double r, double target){
    const double eps = 1e-7;
    while(r - l > eps){
        double mid = (l + r) / 2;
        if(check(mid, target)) l = mid;
        else r = mid;
    }
    return l;
}