#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nsig;

char *standardlize(char *str)
{
	int exp = 0;
	int cnt = 0;
	int before_point = 1;
	char *ans = (char *)malloc(110);
	char str_tmp[10];

	str_tmp[1] = '\0';
	strcpy(ans, "0.");
	/* skip leading zero */
	while(*str == '0')
		str++;
	if(*str == '.'){
		++str;
		before_point = 0;
		while(*str == '0'){
			exp--;
			str++;	
		}
	};
	if(*str == '\0'){
		strcpy(ans, "0.");
		exp = 0;
	}else{
		while(*str != '\0'){
			if(*str == '.'){
				before_point = 0;
				++str;
				continue;
			}
			if(before_point)
				exp++;
			if(cnt != nsig){
				str_tmp[0] = *str;
				strcat(ans, str_tmp);
				cnt ++;
			}
			++str;
		}
	}
	/* padding */
	while(cnt < nsig){
		str_tmp[0] = '0';
		strcat(ans, str_tmp);
		cnt ++;
	}
	sprintf(str_tmp, "*10^%d", exp);
	strcat(ans, str_tmp);
	return ans;
}

int main(void)
{
	char numa[110];
	char numb[110];
	char *stra, *strb;

	scanf("%d%s%s", &nsig, numa, numb);

	stra = standardlize(numa);
	strb = standardlize(numb);

	if(strcmp(stra, strb) == 0)
		printf("YES %s\n", stra);
	else
		printf("NO %s %s\n", stra, strb);

	return 0;
}