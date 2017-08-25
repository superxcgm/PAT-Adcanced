#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

struct Person{
	int id;
	int v;
	int t;
};

vector<Person> vt;
int low, high;
int get_identity(const Person *p)
{
	if(p->v >= high && p->t >= high) return 4;/* sege */
	if(p->v >= high && p->t < high) return 3;/* nobleman */
	if(p->v >= p->t) return 2; /* fool man */
	return 1; /* small man */
}
bool cmp(const Person &a, const Person &b)
{
	int identity_a, identity_b;

	identity_a = get_identity(&a);
	identity_b = get_identity(&b);
	if(identity_a != identity_b)
		return identity_a > identity_b;
	if(a.t + a.v != b.t + b.v)
		return a.t + a.v > b.t + b.v;
	if(a.v != b.v)
		return a.v > b.v;
	return a.id < b.id;
}

int main(void)
{
	int nperson;
	int i;
	Person tmp_person;

	scanf("%d%d%d", &nperson, &low, &high);
	for(i = 0; i < nperson; ++i){
		scanf("%d%d%d", &tmp_person.id, &tmp_person.v, &tmp_person.t);
		if(tmp_person.v < low || tmp_person.t < low)
			continue;
		vt.push_back(tmp_person);
	}
	sort(vt.begin(), vt.end(), cmp);
	printf("%d\n", vt.size());
	for(i = 0; i < vt.size(); ++i)
		printf("%.8d %d %d\n", vt[i].id, vt[i].v, vt[i].t);

	return 0;
}
