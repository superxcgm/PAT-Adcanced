#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Ans{
	char name[4];
	int cnt;
};

map<string, int> mp_to_id;
map<int, string> mp_to_name;
vector<int> vt_group;
vector<Ans> vt_ans;
int weight[2010];
int total_weight[2010];
int npeople[2010];
int f[2010];
int id;

bool sort_by_name(const Ans &a, const Ans &b)
{
	return strcmp(a.name, b.name) < 0;
}

int get_id(char *str)
{
	if(mp_to_id.find(str) == mp_to_id.end()){
		mp_to_id[str] = id;
		mp_to_name[id] = str;
		return id++;
	}else
		return mp_to_id[str];
}

int fin(int t)
{
	if(f[t] == -1) return t;
	return f[t] = fin(f[t]);
}

void merge(int a, int b, int tmp_weight)
{
	int t1 = fin(a);
	int t2 = fin(b);
	if(t1 != t2){
		f[t1] = t2;
		npeople[t2] += npeople[t1];
		total_weight[t2] += total_weight[t1];
	}
	total_weight[t2] += tmp_weight;
}
int main(void)
{
	int nrecord, threthold;
	int i, j, len, tmp_weight;
	char name1[4], name2[4];
	int id1, id2;
	Ans tmp_ans;

	// freopen("1034.in", "r", stdin);
	id = 0;
	scanf("%d%d", &nrecord, &threthold);
	memset(npeople, 0, sizeof(npeople));
	memset(f, 0xff, sizeof(f));
	memset(weight, 0, sizeof(weight));
	memset(total_weight, 0, sizeof(total_weight));

	for(i = 0; i < nrecord; ++i){
	 	scanf("%s %s %d", name1, name2, &tmp_weight);
	 	id1 = get_id(name1);
	 	id2 = get_id(name2);
	 	if(npeople[id1] == 0) npeople[id1] = 1;
	 	if(npeople[id2] == 0) npeople[id2] = 1;
	 	weight[id1] += tmp_weight;
	 	weight[id2] += tmp_weight;
	 	merge(id1, id2, tmp_weight);
	}
	for(i = 0; i < id; ++i)
		if(fin(i) == i && npeople[i] > 2 && total_weight[i] > threthold)
			vt_group.push_back(i);
	len = vt_group.size();
	printf("%d\n", len);
	for(i = 0; i < len; ++i){
		int max_weight = -1;
		int k;
		for(j = 0; j < id; ++j)
			if(fin(j) == vt_group[i] && weight[j] > max_weight){
				max_weight = weight[j];
				k = j;
			}
		strcpy(tmp_ans.name, mp_to_name[k].c_str());
		tmp_ans.cnt = npeople[vt_group[i]];
		vt_ans.push_back(tmp_ans);
	}
	sort(vt_ans.begin(), vt_ans.end(), sort_by_name);
	for(i = 0; i < len; ++i)
		printf("%s %d\n", vt_ans[i].name, vt_ans[i].cnt);
	
	return 0;
}