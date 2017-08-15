#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

map<int, vector<int> > mp;

bool cmp(const int &a, const int &b)
{
	return a < b;
}
int hashName(const char str[6])
{
	return (str[0] - 'A') * 26*26*26 + (str[1] - 'A') * 26 * 26 + 
	(str[2] - 'A') * 26 +  str[3] - '0';
}
int main(void)
{
	int nquery, ncourse;
	int i, j, nstudent;
	int course_no;
	char tmp_name[6];

	scanf("%d%d", &nquery, &ncourse);
	for(i = 0; i < ncourse; ++i){
		scanf("%d%d", &course_no, &nstudent);
		for(j = 0; j < nstudent; ++j){
			scanf("%s", tmp_name);
			mp[hashName(tmp_name)].push_back(course_no);
		}
	}
	for(i = 0; i < nquery; ++i){
		scanf("%s", tmp_name);
		printf("%s ", tmp_name);
		int v = hashName(tmp_name);
		if(mp.find(v) == mp.end()){
			printf("0");
		}else{
			if(mp[v][0] != -1){
				mp[v].push_back(-1);
				sort(mp[v].begin(), mp[v].end(), cmp);
			}
			int len = mp[v].size();
			printf("%d", len - 1);
			for(j = 1; j < len; ++j)
				printf(" %d", mp[v][j]);
		}
		printf("\n");
	}


	return 0;
}