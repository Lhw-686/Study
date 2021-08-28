#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const static int N = 10010;
int s[N], n;

void init(){
    scanf("%d",&n);
    for(int i = 0; i < n; i++) scanf("%d",&s[i]);
}

void print(){
    for(int i = 0; i < n; i++){
        printf("%d ", s[i]);
    }
    printf("\n");
}

typedef struct Student {
    char name[101];
    int age;
    int grade;
    bool operator < (const Student &S) const{
        if(grade != S.grade) return grade < S.grade;
        int t = strcmp(name, S.name);
        if(t != 0) return t < 0;
        return age < S.age;
    }
    bool operator > (const Student &S) const{
        if(grade != S.grade) return grade > S.grade;
        int t = strcmp(name, S.name);
        if(t != 0) return t > 0;
        return age > S.age;
    }
}Student;
Student S[N];

void inputStudent(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s %d %d", S[i].name, &S[i].age, &S[i].grade);
    }
}

void outputStudent(){
    for(int i = 0; i < n; i++){
        printf("%s %d %d\n", S[i].name, S[i].age, S[i].grade);
    }
}

int main(){
    inputStudent();
    sort(S, S+n);
    outputStudent();
    sort(S, S+n, greater<Student>());
    outputStudent();
    return 0;
}
/*
3
abc 20 99
bcd 19 97
bed 20 97
*/