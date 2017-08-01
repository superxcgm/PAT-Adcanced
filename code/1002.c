#include <stdio.h>
#include <string.h>

int const N = 13;
struct Pol{
	int exp;
	double coe;
};

int main(void)
{
	struct Pol pol_a[N];
	struct Pol pol_b[N];
	int len_a, len_b;
	int i, j;
	char buf[BUFSIZ];
	char tmp_str[15];
	int cnt = 0;

	scanf("%d", &len_a);
	for(i = 0; i < len_a; ++i)
		scanf("%d %lf", &pol_a[i].exp, &pol_a[i].coe);
	pol_a[len_a++].exp = -1;

	scanf("%d", &len_b);
	for(i = 0; i < len_b; ++i)
		scanf("%d %lf", &pol_b[i].exp, &pol_b[i].coe);	
	pol_b[len_b++].exp = -1;

	i = j = 0;
	buf[0] = '\0';
	while(1){
		if(pol_a[i].exp == -1 && pol_b[j].exp == -1)
			break;
		if(pol_a[i].exp > pol_b[j].exp){
			sprintf(tmp_str, " %d %.1f", pol_a[i].exp,
				pol_a[i].coe);
			++i;
			if(pol_a[i - 1].coe == 0)
				continue;
		}else if(pol_a[i].exp < pol_b[j].exp){
			sprintf(tmp_str, " %d %.1f", pol_b[j].exp,
				pol_b[j].coe);
			++j;
			if(pol_b[j - 1].coe == 0)
				continue;
		}else{
			sprintf(tmp_str, " %d %.1f", pol_b[j].exp,
			pol_b[j].coe + pol_a[i].coe);
			++i;
			++j;
			if(pol_b[j - 1].coe + pol_a[i - 1].coe == 0)
				continue;
		}
		strcat(buf, tmp_str);
		++cnt;
	}
	printf("%d%s", cnt, buf);

	return 0;
}