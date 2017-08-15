#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char buf[BUFSIZ];
	int len;
	int i, p, q;
	int cnt;
	int max_len = 0;

	gets(buf);
	len = strlen(buf);
	for(i = 0; i < len; ++i){
		p = i - 1;
		q = i + 1;
		cnt = 1;
		while(p >= 0 && q < len && buf[p--] == buf[q++])
			cnt += 2;
		if(cnt > max_len) max_len = cnt;
		p = i;
		q = i + 1;
		cnt = 0;
		while(p >= 0 && q < len && buf[p--] == buf[q++])
			cnt += 2;
		if(cnt > max_len) max_len = cnt;
	}
	printf("%d\n", max_len);

	return 0;
}