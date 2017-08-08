#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

struct Record{
	int arr_t;	/* arriving time */
	int p_t;	/* process time */
};

int ncstmr, nwin;
int open_t, close_t;
Record arr_list[10005];
queue<struct Record> que[103];
int tm[103];

const int INF = 0x3f3f3f3f;

bool cmp(struct Record &ra, struct Record &rb)
{
	return ra.arr_t < rb.arr_t;
}

int t_to_second(const char *str)
{
	int hr, minu, sec;

	sscanf(str, "%d:%d:%d", &hr, &minu, &sec);
	return hr * 3600 + minu * 60 + sec;
}
double calc()
{
	int p_prcss = 0;
	int k;
	int min_t, i;
	struct Record rec_tmp;
	double ans = 0;
	int people_cnt = 0;

	for(i = 0; i < nwin; ++i){
		if(p_prcss >= ncstmr) break;
		que[i].push(arr_list[p_prcss++]);
		tm[i] = open_t;
	}

	while(1){

		min_t = INF;
		for(i = 0; i < nwin; ++i){
			int t_tmp;

			if(que[i].empty()) continue;
			rec_tmp = que[i].front();
			/* arrive later at 17:00:00, do not process */
			if(rec_tmp.arr_t > close_t) continue;

			if(rec_tmp.arr_t > tm[i])
				t_tmp = rec_tmp.arr_t + rec_tmp.p_t;
			else
				t_tmp = tm[i] + rec_tmp.p_t;

			if(t_tmp < min_t){
				min_t = t_tmp;
				k = i;
			}
		}
		if(min_t == INF) break;
		rec_tmp = que[k].front();
		que[k].pop();
		tm[k] = min_t;
		// printf("customer: arrive at %d:%d:%d, in que %d, waiting %d second.\n",
		// 	rec_tmp.arr_t / 3600, rec_tmp.arr_t / 60 % 60, rec_tmp.arr_t % 60,
		// 	k, min_t - rec_tmp.p_t - rec_tmp.arr_t);
		ans +=  min_t - rec_tmp.p_t - rec_tmp.arr_t;
		++people_cnt;
		if(p_prcss >= ncstmr) continue;
		que[k].push(arr_list[p_prcss++]);

	}
	return ans / 60 / people_cnt;
}
int main(void)
{
	char buf[BUFSIZ];
	open_t = t_to_second("08:00:00");
	close_t = t_to_second("17:00:00");

	scanf("%d%d", &ncstmr, &nwin);

	for(int i = 0; i < ncstmr; ++i){
		scanf("%s %d", buf, &arr_list[i].p_t);
		arr_list[i].arr_t = t_to_second(buf);
		arr_list[i].p_t *= 60; /* convert to second */
	}
	sort(arr_list, arr_list + ncstmr, cmp);

	// for(int i = 0; i < ncstmr; ++i)
	// 	printf("%d %d\n", arr_list[i].arr_t, arr_list[i].p_t);
	
	printf("%.1lf", calc());

	return 0;
}