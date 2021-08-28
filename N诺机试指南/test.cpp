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

// �������� 2019-10-21
int year, month, day;
scanf("%d-%d-%d", &year, &month, &day);
printf("%d %d %d\n", &year, &month, &day);

// ����ʱ�� 18:21:30
int hour, minute, second;
scanf("%d:%d:%d", &hour, &minute, &second);
printf("%d %d %d\n", &hour, &minute, &second);

// ��ȡ�ո��β���ַ��������ո��Զ�����
gets(s);
scanf("%s", s);

// ��ȡ����������ַ�
c = getchar()
putchar(c)

// ����ת��
int a = 10;
printf("%x\n", a); // Сдʮ������
printf("%X\n", a); // ��дʮ������
printf("%o\n", a); // �˽���

// �����0
printf("%05d\n", a);

// ����С�������㲹0
d = 3.14;
printf("%.5lf\n", d);

// ��С������С����ûС���������
printf("%g\n", d);

// int -1e9 - 1e9 long long -1e18 - 1e18
long long ll;
scanf("%lld", &ll);
printf("%lld\n", ll);

// ��ȡ��ά�ַ�����
char mpt[MAXSIZE][MAXSIZE];
int n;
for(int i = 0; i < n; i++){
    scanf("%s", mpt[i]);
    /*
    ���ַ�ʽ��ȡ���س�Ҳ��һ��char�ַ�
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

/*ʱ�临�Ӷȹ���
O(N)        500w
O(NlogN)    20w
O(N^2)      200
O(N^2logN)  700
O(N^3)      200
O(N^4)      50
O(2^N);     24
O(N!)       10
*/

// ����
int arr[MAXSIZE];
int m;
sort(arr, arr+m);

// ����(����õ�����)
// ��С������������
int begin, end, num;
/*
�������beginλ�õ�end-1λ�ö��ֲ��ҵ�һ��С�ڻ����num�����֣�
�ҵ����ظ����ֵĵ�ַ���������򷵻�end��
ͨ�����صĵ�ַ��ȥ��ʼ��ַbegin,�õ��ҵ������������е��±�
*/
lower_bound(begin, end, num);
/*
�������beginλ�õ�end-1λ�ö��ֲ��ҵ�һ������num�����֣�
�ҵ����ظ����ֵĵ�ַ���������򷵻�end��
ͨ�����صĵ�ַ��ȥ��ʼ��ַbegin,�õ��ҵ������������е��±�
*/
upper_bound(begin, end, num);

// �Ӵ�С��������
// ����lower_bound()��upper_bound()
lower_bound(begin, end, num, greater<type>());
upper_bound(begin, end, num, greater<type>());

// ���ȶ���
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
dict.count("Tom"); // ����
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

// ��������
int x, y;
while(scanf("%d %d, &x, &y") != EOF){

}
while(cin >> x >> y){
    
}