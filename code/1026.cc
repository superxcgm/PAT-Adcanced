#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

struct Record{
	int arr_t;
	int p_t;
}vip_records[10003], ordi_records[10003];

int vip_table[103];
bool cmp(Record a, Record b)
{
	return a.arr_t < b.arr_t;
}

const int INF = 0x3f3f3f3f;
int time_round(int sec)
{
	int ans;
	ans = sec / 60;
	if(sec % 60) ++ans;
	return ans;
}
void print_time(int sec)
{
	printf("%.2d:%.2d:%.2d ", sec / 3600, (sec / 60) % 60, sec % 60);
}

int main(void)
{
	int nplayer;
	int ntable, nviptable, table;
	int i, j, k;
	int hh, mm, ss, p_t, isvip;
	int p, q;
	struct Record tmp_record;
	int tm[103];
	int table_serve[103];
	int open_time, close_time;

	// freopen("1026.in", "r", stdin);
	scanf("%d", &nplayer);
	p = q = 0;
	open_time = 8 * 3600;
	close_time = 21 * 3600;
	for(i = 0; i < nplayer; ++i){
		scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &p_t, &isvip);
		if(p_t > 120) p_t = 120;
		p_t *= 60;
		tmp_record.arr_t = hh * 3600 + mm * 60 + ss;
		if(tmp_record.arr_t >= close_time) continue;
		tmp_record.p_t = p_t;
		if(isvip)
			vip_records[p++] = tmp_record;
		else
			ordi_records[q++] = tmp_record;
	}
	scanf("%d%d", &ntable, &nviptable);
	memset(vip_table, 0, sizeof(vip_table));
	memset(table_serve, 0, sizeof(table_serve));
	for(i = 0; i < nviptable; ++i){
		scanf("%d", &table);
		vip_table[table - 1] = 1;
	}
	sort(vip_records, vip_records + p, cmp);
	sort(ordi_records, ordi_records + q, cmp);
	for(i = 0; i <= ntable; ++i)
		tm[i] = open_time;
	i = j = 0;
	while(i < p || j < q){
		int min_t = INF;
		int idx;
		int ordi_time = INF, vip_time = INF;
		int vip_serve = 0;
		/* find first can serve table */
		for(k = 0; k < ntable; ++k){
			if(tm[k] < min_t){
				min_t = tm[k];
				idx = k;
			}
		}
		if(min_t >= close_time) break;
		if(i < p) vip_time = max(vip_records[i].arr_t, min_t);
		if(j < q) ordi_time = max(ordi_records[j].arr_t, min_t);
		if(vip_time < ordi_time)/* ordi come after min_t */
			vip_serve = 1;
		else if(vip_time == ordi_time)
			if(vip_table[idx] || vip_records[i].arr_t < ordi_records[j].arr_t)
				vip_serve = 1;
		if(vip_serve){
			if(!vip_table[idx])
				for(k = 0; k < ntable; ++k)
					if(vip_table[k] && tm[k] == min_t){
						idx = k;
						break;
					}
			print_time(vip_records[i].arr_t);
			print_time(vip_time);
			printf("%d\n", time_round(vip_time - vip_records[i].arr_t));
			tm[idx] = vip_time + vip_records[i].p_t;
			++i;
			++table_serve[idx];
		}else{
			print_time(ordi_records[j].arr_t);
			print_time(ordi_time);
			printf("%d\n", time_round(ordi_time - ordi_records[j].arr_t));
			tm[idx] = ordi_time + ordi_records[j].p_t;
			++j;
			++table_serve[idx];
		}
	}
	printf("%d", table_serve[0]);
	for(i = 1; i < ntable; ++i)
		printf(" %d", table_serve[i]);
	return 0;
}