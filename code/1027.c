#include <stdio.h>

char *format_13(int x)
{
	static char ans[3];
	int i;
	ans[2] = '\0';
	ans[0] = x / 13;
	ans[1] = x % 13;
	for(i = 0; i < 2; ++i)
		ans[i] = ans[i] >= 10 ? ans[i] - 10 + 'A' : ans[i] + '0';
	return ans;
}

int main(void)
{
	int r, g, b;

	scanf("%d %d %d", &r, &g, &b);
	printf("#%s", format_13(r));
	printf("%s", format_13(g));
	printf("%s", format_13(b));
	
	return 0;
}