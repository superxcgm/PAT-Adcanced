#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mp[100005];
int find_first(int from, int to)
{
	int i;

	for(i = from; i < to; ++i)	
		if(mp[i] != i)
			return i;
	return -1;
}
int main(void)
{
	int nnum;
	int tmp, i, j;
	int cnt = 0;
	int first;

	scanf("%d", &nnum);
	for(i = 0; i < nnum; ++i){
		scanf("%d", &tmp);
		mp[tmp] = i;
	}
	/* 找第一个乱序数 */
	first = find_first(0, nnum);
	while(first != -1){
		if(mp[0] == 0){
			mp[0] = mp[first];
			mp[first] = 0;
			++cnt;
		}
		while(mp[0] != 0){
			tmp = mp[0];
			mp[0] = mp[tmp];
			mp[tmp] = tmp;
			++cnt;	
		}
		first = find_first(first, nnum);
	}
	printf("%d\n", cnt);
	return 0;
}