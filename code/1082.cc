#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
int flag = 0;
int pre_zero = 0;
int first_print = 0;
int lead_zero = 1;
int have_print = 0;
char *digits[10] = {
    "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"
};
char *weights[10] = {
    " Qian", " Bai", " Shi", ""
};
void trans(char *str)
{
    char *p;
    for(p = str; p != str + 4; ++p){
        if(*p > '0'){
            if(first_print == 0)
                first_print = 1;
            else
                putchar(' ');
            if(lead_zero == 1){
                pre_zero = 0;
                lead_zero = 0;
            }
            if(pre_zero){
                printf("%s ", digits[0]);
                pre_zero = 0;
            }
            printf("%s%s", digits[*p - '0'], weights[p - str]);
            have_print = 1;
        }else{
            pre_zero = 1;
        }
    }
}
int main()
{
    int num;
    char snum[15];
    
    //freopen("1082.txt", "r", stdin);
    //freopen("1082.out.txt", "w", stdout);
    scanf("%d", &num);
    if(num < 0){
        printf("Fu ");
        num = -num;
    }
    if(num == 0){
        printf("ling");
        return 0;
    }
    sprintf(snum, "%.12d", num);
    trans(snum);
    if(have_print)
        printf(" Yi");
    have_print = 0;
    trans(snum + 4);
    if(have_print)
        printf(" Wan");
    trans(snum + 8);
    return 0;
}