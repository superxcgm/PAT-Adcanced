#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

struct Cstmr{
	int no;
	int pro_time;
};

queue<struct Cstmr> que[22];
int tm[22];
queue<struct Cstmr> que_cstmr;
map<int, char *> mp;	/* recorad each customer's finish time */

const int INF = 0x3f3f3f3f;

int nwin, nmax;
char *tm_to_std_time(int t, int flag)
{
	int h, m;
	char *ans;

	ans = (char *)malloc(sizeof("17:00") + 2);
	if(flag == 1)
		sprintf(ans, "Sorry");
	else{
		h = t / 60;
		m = t % 60;
		sprintf(ans, "%.2d:%.2d", 8 + h, m);		
	}
	
	
	return ans;
}
void process()
{
	int i, j;
	int t_min;
	int t;
	struct Cstmr tmp_cstmr;
	int win;

	memset(tm, 0, sizeof(tm));
	for(i = 0; i < nmax; ++i)
		for(j = 0; j < nwin; ++j){
			if(que_cstmr.size() == 0){
				i = nmax;
				break;
			}
			que[j].push(que_cstmr.front());
			que_cstmr.pop();
		}
	while(1){
		t_min = INF;
		win = -1;
		for(i = 0; i < nwin; ++i){
			if(que[i].size() == 0) continue;
			tmp_cstmr = que[i].front();
			t = tm[i] + tmp_cstmr.pro_time;
			if(t < t_min){
				t_min = t;
				win = i;
			}
		}
		if(win == -1) break;
		tmp_cstmr = que[win].front();
		que[win].pop();
		if(tm[win] >= 540)
			mp[tmp_cstmr.no] = tm_to_std_time(0, 1);
		else
			mp[tmp_cstmr.no] = tm_to_std_time(tm[win]
				+= tmp_cstmr.pro_time, 0);
		if(que_cstmr.size()){
			que[win].push(que_cstmr.front());
			que_cstmr.pop();
		}
	}
	
}

int main(void)
{
	int ncstmr, nquery;
	int pro_time;
	int i;
	struct Cstmr tmp_cstmr;
	int cstmr_no;

	scanf("%d%d%d%d", &nwin, &nmax, &ncstmr, &nquery);
	for(i = 0; i < ncstmr; ++i){
		scanf("%d", &tmp_cstmr.pro_time);
		tmp_cstmr.no = i + 1;
		que_cstmr.push(tmp_cstmr);
	}
	process();

	for(i = 0; i < nquery; ++i){
		scanf("%d", &cstmr_no);
		printf("%s\n", mp[cstmr_no]);
	}

	return 0;
}