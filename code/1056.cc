#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Player{
	int goal;
	int rank;
	int id;
};
queue<Player> qu;
vector<Player> vt;
vector<Player> vt_ans;
Player player_r[1003];
int std_seed[1003];
int nplayer, npeople_per_group;

bool cmp(const Player &a, const Player &b)
{
	return a.id < b.id;
}

void compute()
{
	int nservive = nplayer;
	int ngroup;
	int i, j, len;
	int max_ele;
	Player player_tmp;

	while(1){
		if(nservive == 1){
			player_tmp = qu.front();
			player_tmp.rank = 1;
			vt_ans.push_back(player_tmp);
			return;
		}
		ngroup = nservive / npeople_per_group;
		if(nservive % npeople_per_group)
			++ngroup;
		vt.clear();
		while(!qu.empty()){
			vt.push_back(qu.front());
			qu.pop();
		}
		len = vt.size();
		for(i = 0; i < len; i += npeople_per_group){
			max_ele = i;
			for(j = i + 1; j < i + npeople_per_group && j < len; ++j)
				if(vt[j].goal > vt[max_ele].goal)
					max_ele = j;
			for(j = i; j < i + npeople_per_group && j < len; ++j)
				if(j != max_ele){
					vt[j].rank = ngroup + 1;
					vt_ans.push_back(vt[j]);
				}
			qu.push(vt[max_ele]);
		}
		
		nservive = qu.size();
	}
}

void standlize()
{
	int i;

	for(i = 0; i < nplayer; ++i)
		qu.push(player_r[std_seed[i]]);
}

int main(void)
{
	int len, i;

	// freopen("1056.in", "r", stdin);
	scanf("%d%d", &nplayer, &npeople_per_group);

	for(i = 0; i < nplayer; ++i){
		scanf("%d", &player_r[i].goal);
		player_r[i].id = i;
	}

	for(i = 0; i < nplayer; ++i)
		scanf("%d", &std_seed[i]);
	standlize();
	compute();
	sort(vt_ans.begin(), vt_ans.end(), cmp);
	len = vt_ans.size();
	printf("%d", vt_ans[0].rank);
	for(i = 1; i < len; ++i)
		printf(" %d", vt_ans[i].rank);
	return 0;
}