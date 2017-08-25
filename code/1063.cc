#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>

using namespace std;

set<int> st[52], tmp_st;

int main(void)
{
	int nset;
	int i, j, k;
	int nnum, nquery;
	int st_a, st_b;
	int num;
	set<int>::iterator it1, it2;

	scanf("%d", &nset);
	for(i = 1; i <= nset; ++i){
		scanf("%d", &nnum);
		while(nnum--){
			scanf("%d", &num);
			st[i].insert(num);
		}
	}
	scanf("%d", &nquery);
	while(nquery--){
		int cnt = 0;
		scanf("%d%d", &st_a, &st_b);
		for(it1 = st[st_a].begin(), it2 = st[st_b].begin();
			it1 != st[st_a].end() && it2 != st[st_b].end();)
			if(*it1 == *it2){
				cnt++;
				++it1;
				++it2;
			}else if(*it1 > *it2)
				++it2;
			else
				++it1;
		printf("%.1f%%\n", 100.0*cnt/(st[st_a].size() + st[st_b].size() - cnt));
	}
	return 0;
}