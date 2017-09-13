#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;
struct Student{
    char name[15];
    char ID[15];
    int grade;
} student[100005];
bool cmp(const Student &a, const Student &b)
{
    return a.grade > b.grade;
}
int main()
{
    int nstudent;
    int flag = 0, l, r, i;
    
    //freopen("1083_1.txt", "r", stdin);
    //freopen("1083.out.txt", "w", stdout);
    
    scanf("%d", &nstudent);
    for(i = 0; i < nstudent; ++i)
        scanf("%s %s %d", student[i].name, student[i].ID, &student[i].grade);
    sort(student, student + nstudent, cmp);
    scanf("%d%d", &l, &r);
//    if(l > r)
//        swap(l, r);
    for(i = 0; i < nstudent; ++i){
        if(student[i].grade >= l && student[i].grade <= r){
            printf("%s %s\n", student[i].name, student[i].ID);
            flag = 1;
        }
    }
    if(flag == 0){
        printf("NONE\n");
    }
    return 0;
}