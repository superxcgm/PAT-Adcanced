#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

struct People{
	char name[10];
	int age;
	int money;
};
bool cmp(const People &a, const People &b)
{
	if(a.money != b.money)
		return a.money > b.money;
	if(a.age != b.age)
		return a.age < b.age;
	return strcmp(a.name, b.name) < 0;
}
People people[100005];

using namespace std;

int main(void)
{
	int npeople, nquery;
	int i, cnt, from, to, total, j;

	scanf("%d%d", &npeople, &nquery);
	for(i = 0; i < npeople; ++i)
		scanf("%s%d%d", people[i].name, &people[i].age, &people[i].money);
	sort(people, people + npeople, cmp);
	for(i = 0; i < nquery; ++i){
		scanf("%d %d %d", &total, &from, &to);
		printf("Case #%d:\n", i + 1);
		cnt = total;
		for(j = 0; j < npeople; ++j){
			if(cnt == 0) break;
			if(people[j].age >= from && people[j].age <= to){
				printf("%s %d %d\n", people[j].name, people[j].age,
					people[j].money);
				--cnt;
			}
		}
		if(cnt == total)
			printf("None\n");
	}

	return 0;
}