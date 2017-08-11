#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <map>

using namespace std;

map<int, int> nex; /* next */

int count_len(int str)
{
	int cnt = 0;
	while(str != -1){
		++cnt;
		str = nex[str];
	}
	return cnt;
}

int main(void)
{
	int start1, start2;
	int tmp1, tmp2;
	int nline, i;
	int len1, len2;
	char ch;
	int flag = 0;

	scanf("%d%d%d", &start1, &start2, &nline);
	for(i = 0; i < nline; ++i){
		scanf("%d %c %d", &tmp1, &ch, &tmp2);
		nex[tmp1] = tmp2;
	}
	len1 = count_len(start1);
	len2 = count_len(start2);

	while(1){
		if(len1 > len2){
			start1 = nex[start1];
			len1--;
		}else if(len1 < len2){
			start2 = nex[start2];
			len2--;
		}else{
			if(start1 == start2){
				flag = 1;
				break;
			}
			start1 = nex[start1]; len1--;
			start2 = nex[start2]; len2--;
		}
		if(start1 == -1 || start2 == -1) break;
	}
	if(flag)
		printf("%.5d\n", start1);
	else
		printf("-1\n");

	return 0;
}