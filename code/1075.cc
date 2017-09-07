#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;
int perfect_score[8];
int nproblem;
struct User{
    int id;
    int score[8];
    int total_score;
    int perfect_solve;
} users[10005];
bool cmp(const User &a, const User &b)
{
    if(a.total_score > b.total_score)
        return true;
    else if(a.total_score == b.total_score)
        return a.perfect_solve > b.perfect_solve;
    return false;
}
int can_print(int id)
{
    int i;
    for(i = 1; i < nproblem; ++i)
        if(users[id].score[i] >= 0)
            return 1;
    return 0;
}
int main()
{
    int nuser, nsubmit;
    int i, j;
    int id, p_id, score;
    
    //freopen("1075.txt", "r", stdin);
    //freopen("1075.out.txt", "w", stdout);
    
    scanf("%d%d%d", &nuser, &nproblem, &nsubmit);
    for(i = 1; i <= nproblem; ++i)
        scanf("%d", &perfect_score[i]);
    for(i = 1; i <= nuser; ++i){
        users[i].id = i;
        for(j = 1; j <= nproblem; ++j)
            users[i].score[j] = -2;
    }
    for(i = 0; i < nsubmit; ++i){
        scanf("%d%d%d", &id, &p_id, &score);
        users[id].score[p_id] = max(users[id].score[p_id], score);        
    }
    for(i = 1; i <= nuser; ++i){
        users[i].total_score = 0;
        users[i].perfect_solve = 0;
        for(j = 1; j <= nproblem; ++j){
            if(users[i].score[j] > 0)
                users[i].total_score += users[i].score[j];
            if(users[i].score[j] == perfect_score[j])
                users[i].perfect_solve++;
        }
    }
    sort(users + 1, users + nuser + 1, cmp);
    int pre_rank = -1, pre_score = -1;
    int real_rank = 1;
    for(i = 1; i <= nuser; ++i){
        if(can_print(i)){
            printf("%d ", pre_score == users[i].total_score ? pre_rank :
                pre_rank = real_rank);
            printf("%.5d ", users[i].id);
            printf("%d", users[i].total_score);
            for(j = 1; j <= nproblem; ++j)
                if(users[i].score[j] == -1)
                    printf(" 0");
                else if(users[i].score[j] == -2)
                    printf(" -");
                else
                    printf(" %d", users[i].score[j]);
            printf("\n");
            pre_score = users[i].total_score;
            real_rank++;
        }
    }
    return 0;
}