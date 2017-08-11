#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char buf[BUFSIZ];
	char space[BUFSIZ];
	int len;
	int n1, n2, n3, i;

	// freopen("1031.in", "r", stdin);
	scanf("%s", buf);
	len = strlen(buf);
	n1 = n3 = (len + 2) / 3;
	n2 = len + 2 - n1 - n3;
	--n1; --n3;
	// printf("n1: %d, n2: %d, n3: %d\n", n1, n2, n3);
	memset(space, ' ', sizeof(space));
	space[n2 - 2] = '\0';
	for(i = 0; i < n1; ++i)
		printf("%c%s%c\n", buf[i], space, buf[len - 1 - i]);
	buf[n1 + n2] = '\0';
	printf("%s\n", buf + n1);

	return 0;
}