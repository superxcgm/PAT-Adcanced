#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char str1[10003];
char str2[10003];
char ascii[260];

int main(void)
{
	int i, len, j;
	char *p;

	gets(str1);
	gets(str2);
	memset(ascii, 0, sizeof(ascii));
	p = str2;
	while(*p){
		ascii[*p] = 1;
		++p;
	}
	j = 0;
	for(i = 1; i < 260; ++i)
		if(ascii[i])
			str2[j++] = i;
	p = str1;
	len = j;
	while(*p){
		int flag = 0;
		for(i = 0; i < len; ++i)
			if(str2[i] == *p)
				flag = 1;
		if(!flag)
			putchar(*p);
		++p;
	}
	return 0;
}