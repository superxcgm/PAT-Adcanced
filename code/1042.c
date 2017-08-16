#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 1-13 S, 14-26 H, 27-39C, 40-52D, 53, 54*/
int perm[56];
int seed[56];

void shuffling()
{
	int tmp[56];
	int i;

	for(i = 1; i <= 54; ++i)
		tmp[i] = perm[i];

	for(i = 1; i <=54; ++i)
		perm[seed[i]] = tmp[i];
}
void printf_card(int x, int first)
{
	int mod;

	if(!first) putchar(' ');
	if(x >= 53)
		putchar('J');
	else if(x >= 40)
		putchar('D');
	else if(x >= 27)
		putchar('C');
	else if(x >= 14)
		putchar('H');
	else
		putchar('S');
	mod = x % 13;
	if(mod == 0)
		mod = 13;
	printf("%d", mod);
}
int main(void)
{
	int ntime;
	int i, j;

	for(i = 1; i <= 54; ++i)
		perm[i] = i;
	scanf("%d", &ntime);
	for(i = 1; i <= 54; ++i)
		scanf("%d", &seed[i]);
	while(ntime--)
		shuffling();

	printf_card(perm[1], 1);
	for(i = 2; i <= 54; ++i)
		printf_card(perm[i], 0);

	return 0;
}