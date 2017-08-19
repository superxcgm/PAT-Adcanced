#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vt[2503];

int name_to_id(const char *name)
{
	return (name[0] - 'A') * 26 * 26 * 26 +
	(name[1] - 'A') * 26 * 26 +
	(name[2] - 'A') * 26 +
	(name[3] - '0');
}
char *id_to_name(int id)
{
	static char name[5];
	name[4] = '\0';
	name[3] = id % 26 + '0';
	name[2] = (id / 26) % 26 + 'A';
	name[1] = (id / 26 / 26) % 26 + 'A';
	name[0] = id / 26 / 26 / 26 + 'A';
	return name;
}
bool cmp(const int &a, const int &b)
{
	char name_a[5];

	strcpy(name_a, id_to_name(a));
	return strcmp(name_a, id_to_name(b)) < 0;
}

int main(void)
{
	int nstudent, ncourse;
	int i, j, tmp_ncourse, course;
	char name[5];

	scanf("%d%d", &nstudent, &ncourse);
	for(i = 0; i < nstudent; ++i){
		int id;

		scanf("%s %d", name, &tmp_ncourse);
		id = name_to_id(name);
		for(j = 0; j < tmp_ncourse; ++j){
			scanf("%d", &course);
			vt[course].push_back(id);
		}
	}
	for(i = 1; i <= ncourse; ++i){
		printf("%d %d\n", i, vt[i].size());
		sort(vt[i].begin(), vt[i].end(), cmp);
		for(vector<int>::iterator it = vt[i].begin(); it != vt[i].end();
			++it)
			printf("%s\n", id_to_name(*it));
	}
	return 0;
}