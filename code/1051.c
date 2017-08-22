#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack[1003];
int max_len;
int push_p;
int sp;

int main(void)
{
	int nchar, nquery;
	int i;
	int x;

	scanf("%d%d%d", &max_len, &nchar, &nquery);

	while(nquery--){
		int flag = 1;
		sp = 0;
		push_p = 0;
		for(i = 0; i < nchar; ++i){
			scanf("%d", &x);
			if(!flag) continue;
			while(x > push_p){
				if(sp >= max_len){
					break;
					flag = 0; /* impossible, stack full */
				}
				stack[sp++] = ++push_p;
			}
			if(x != stack[sp - 1])
				flag = 0;
			else
				sp--;
		}
		printf("%s\n", flag ? "YES" : "NO");
	}

	return 0;
}