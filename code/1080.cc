#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;
struct Student{
    int ge;// the national entrance exam grade
    int gi;//  the interview grade
    int final;
    int choise[8];
    int id;
} student[40005];
int quota[105];
set<int> admit[105];
bool cmp(const Student &a, const Student &b)
{
    if(a.final != b.final)
        return a.final > b.final;
    return a.ge > b.ge;
}
int main()
{
    int nstudent, nschool, max_choise;
    int i, j, last_final, last_ge, last_one;
    
    //freopen("1080.txt", "r", stdin);
    //freopen("1080.out.txt", "w", stdout);
    scanf("%d%d%d", &nstudent, &nschool, &max_choise);
    for(i = 0; i < nschool; ++i)
        scanf("%d", &quota[i]);
    for(i = 0; i < nstudent; ++i){
        scanf("%d%d", &student[i].ge, &student[i].gi);
        student[i].final = (student[i].ge + student[i].gi) / 2;
        student[i].id = i;
        for(j = 0; j < max_choise; ++j)
            scanf("%d", &student[i].choise[j]);
    }
    sort(student, student + nstudent, cmp);
    last_final = last_ge = -1;
    last_one = -1;
    for(i = 0; i < nstudent; ++i){
        //printf("%d %d %d", student[i].final, student[i].ge, student[i].gi);
        for(j = 0; j < max_choise; ++j){
            int k = student[i].choise[j];
            //printf(" %d", k);
            if(quota[k] > 0 || (last_final == student[i].final &&
                     last_ge == student[i].ge &&
                     admit[k].find(last_one) != admit[k].end())){
                quota[k]--;
                admit[k].insert(i);
                last_final = student[i].final;
                last_ge = student[i].ge;
                last_one = i;
                break;
            }
        }
        //putchar('\n');
    }
    for(i = 0; i < nschool; ++i){
        vector<int> vt_tmp;
        int len;
        for(set<int>::iterator it = admit[i].begin(); it != admit[i].end();
            ++it)
            vt_tmp.push_back(student[*it].id);        
        len = vt_tmp.size();
        sort(vt_tmp.begin(), vt_tmp.end());
        for(j = 0; j < len; ++j){
            if(j != 0)
                putchar(' ');
            printf("%d", vt_tmp[j]);
        }
        putchar('\n');
    }

    return 0;
}