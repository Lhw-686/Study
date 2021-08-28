#include <bits/stdc++.h>

#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>

#define MAXSIZE 100

using namespace std;

int i;
scanf("%d", &i);

double d;
scanf("%d", &d);

char c;
scanf("%c", &c);

char s[MAXSIZE];
scanf("%s", s);

// 输入日期 2019-10-21
int year, month, day;
scanf("%d-%d-%d", &year, &month, &day);
printf("%d %d %d\n", &year, &month, &day);

// 输入时间 18:21:30
int hour, minute, second;
scanf("%d:%d:%d", &hour, &minute, &second);
printf("%d %d %d\n", &hour, &minute, &second);

// 读取空格结尾的字符串，遇空格自动结束
gets(s);
scanf("%s", s);

// 读取和输出单个字符
c = getchar()
putchar(c)

// 进制转换
int a = 10;
printf("%x\n", a); // 小写十六进制
printf("%X\n", a); // 大写十六进制
printf("%o\n", a); // 八进制

// 输出补0
printf("%05d\n", a);

// 保留小数，不足补0
d = 3.14;
printf("%.5lf\n", d);

// 有小数输入小数，没小数输出整数
printf("%g\n", d);

// int -1e9 - 1e9 long long -1e18 - 1e18
long long ll;
scanf("%lld", &ll);
printf("%lld\n", ll);

// 读取二维字符数组
char mpt[MAXSIZE][MAXSIZE];
int n;
for(int i = 0; i < n; i++){
    scanf("%s", mpt[i]);
    /*
    这种方式读取，回车也算一个char字符
    for(int j = 0; j < n; j++){
        scanf("%c", &mpt[i][j])''
    }*/
}
for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
        printf("%c", mpt[i][j]);
    }
    printf("\n");
}

/*时间复杂度估计
O(N)        500w
O(NlogN)    20w
O(N^2)      200
O(N^2logN)  700
O(N^3)      200
O(N^4)      50
O(2^N);     24
O(N!)       10
*/

// 排序
int arr[MAXSIZE];
int m;
sort(arr, arr+m);

// 查找(排序好的数组)
// 从小到大排序数组
int begin, end, num;
/*
从数组的begin位置到end-1位置二分查找第一个小于或等于num的数字，
找到返回该数字的地址，不存在则返回end。
通过返回的地址减去起始地址begin,得到找到数字在数组中的下标
*/
lower_bound(begin, end, num);
/*
从数组的begin位置到end-1位置二分查找第一个大于num的数字，
找到返回该数字的地址，不存在则返回end。
通过返回的地址减去起始地址begin,得到找到数字在数组中的下标
*/
upper_bound(begin, end, num);

// 从大到小排序数组
// 重载lower_bound()和upper_bound()
lower_bound(begin, end, num, greater<type>());
upper_bound(begin, end, num, greater<type>());

// 优先队列
priority_queue<int> q;

// vector
vector<int> v;
v.push_back(i);
v[i];

// queue
queue<int> q;
q.push(i);
q.front();
q.pop();

// stack
stack<int> S;
S.push(i);
S.top();
S.pop();

// map
map<string, int> dict;
dict["Tom"] = 1;
dict.count("Tom"); // 查找
dict.clear();
for(map<string, int>::iterator it = dict.begin(); it != dict.end(); it++){
    cout << it->first << it->second << endl;
}

// set
set<string> se;
se.insert("China");
set<string>::iterator if;
for(it = se.begin(); it!= se.end(); it++){
    cout << *it << endl;
}
se.erase("China");
se.count("China");
se.clear();

// 多组输入
int x, y;
while(scanf("%d %d, &x, &y") != EOF){

}
while(cin >> x >> y){
    
}