#include <stdio.h>
#include <string.h>

int main(void)
{
	int a, b;
	int c;
	char buf[BUFSIZ];
	int len;
	int i;
	int idx;

	scanf("%d %d", &a, &b);
	c = a + b;

	sprintf(buf, "%d", c);
	len = strlen(buf);
	idx = 0;
	if(buf[idx] == '-'){
		putchar('-');
		++idx;
	}
	for(; idx < len; ++idx){
		putchar(buf[idx]);
		if(idx != len - 1 && (len - 1 - idx) % 3 == 0)
			putchar(',');
	}
	putchar('\n');
	return 0;
}