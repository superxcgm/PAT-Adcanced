#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>

using namespace std;

map<int, int> mp;

int main(void)
{
	int ncol, nrow;
	int i, j;
	int color;
	int ans;
	int max_count = -1;

	scanf("%d%d", &ncol, &nrow);
	for(i = 0; i < nrow; ++i)
		for(j = 0; j < ncol; ++j){
			scanf("%d", &color);
			if(mp.find(color) == mp.end())
				mp[color] = 1;
			mp[color]++;
		}
	for(map<int, int>::iterator it = mp.begin();
		it != mp.end(); ++it)
		if(it->second > max_count){
			max_count = it->second;
			ans = it->first;
		}
	printf("%d\n", ans);

	return 0;
}