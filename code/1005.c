#include <stdio.h>

char *eng[] ={
	"zero",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine"
};

int main()
{
	int ch;
	int sum = 0;
	char *p;
	char buf[BUFSIZ];

	while((ch = getchar()) != EOF && ch != '\n')
		sum += ch - '0';
	
	sprintf(buf, "%d", sum);
	p = buf;
	printf("%s", eng[*p - '0']);
	p++;
	while(*p)
	{
		printf(" %s", eng[*p - '0']);
		p++;
	}

	return 0;
}