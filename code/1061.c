#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *day[] = {
	"MON",
	"TUE",
	"WED",
	"THU",
	"FRI",
	"SAT",
	"SUN"
};
int main(void)
{
	int d, h, m;
	int i, len, tmp_len;
	char str1[BUFSIZ];
	char str2[BUFSIZ];
	char str3[BUFSIZ];
	char str4[BUFSIZ];

	scanf("%s%s%s%s", str1, str2, str3, str4);
	len = strlen(str1);
	tmp_len = strlen(str2);
	if(tmp_len < len) len = tmp_len;
	d = -1;
	h = -1;
	for(i = 0; i < len; ++i){
		if(d != -1 && str1[i] == str2[i]){
			if(str1[i] >= '0' && str1[i] <= '9')
				h = str1[i] - '0';
			else if(str1[i] >= 'A' && str1[i] <= 'N')
				h = str1[i] - 'A' + 10;
			if(h != -1) break;
		}
		if(str1[i] == str2[i] && d == -1 &&
			str1[i] >= 'A' && str1[i] <= 'G')
			d = str1[i] - 'A';
	}
	len = strlen(str3);
	tmp_len = strlen(str4);
	if(tmp_len < len) len = tmp_len;
	for(i = 0; i < len; ++i)
		if(str3[i] == str4[i] && ((str3[i] >= 'a' && str3[i] <= 'z') ||
			(str3[i] >= 'A' && str3[i] <= 'Z')))
			break;
	m = i;
	printf("%s %.2d:%.2d\n", day[d], h, m);

	return 0;
}
