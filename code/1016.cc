#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <set>
#include <algorithm>

using namespace std;

struct Record{
	char name[22];
	char t[14];
	int flag; /* 0 for on-line, 1 for off-line */
} records[1024], records_tmp[1024];

set<string> st;

int toll[26];
int cnt;
/* t1=>from, t2=>to */
double calc_fee(const char *t1, const char *t2)
{
	int mon, day1, hr1, minu1;
	int day2, hr2, minu2;
	double ans = 0;
	int i;

	sscanf(t1, "%d:%d:%d:%d", &mon, &day1, &hr1, &minu1);
	sscanf(t2, "%d:%d:%d:%d", &mon, &day2, &hr2, &minu2);

	while(day1 != day2){
		ans += (60 - minu1) * toll[hr1];
		++hr1;
		for(i = hr1; i < 24; ++i)
			ans += 60 * toll[i];
		hr1 = minu1 = 0;
		++day1;
	}
	while(hr1 != hr2){
		ans += (60 - minu1) *toll[hr1];
		minu1 = 0;
		++hr1;
	}
	ans += (minu2 - minu1) * toll[hr2];
	return ans / 100;
}
int time_to_minus(const char *t)
{
	int mon, day, hr, minu;
	sscanf(t, "%d:%d:%d:%d", &mon, &day, &hr, &minu);
	return day * 24 * 60 + hr * 60 + minu;
}

bool cmp(struct Record ra, struct Record rb)
{
	return time_to_minus(ra.t) < time_to_minus(rb.t);
}

void calc()
{
	int i, j, lasting;
	double fee, total = 0;

	for(i = 0; i < cnt; ++i){
		if(records_tmp[i].flag != 0)
			continue;
		j = i + 1;
		if(records_tmp[j].flag != 1)
			continue;

		lasting = time_to_minus(records_tmp[j].t) -
				time_to_minus(records_tmp[i].t);
		fee = calc_fee(records_tmp[i].t, records_tmp[j].t);
		printf("%s %s %d $%.2lf\n", records_tmp[i].t + 3,
			records_tmp[j].t + 3, lasting, fee);
		i++;
		total += fee;
	}
			
		
	printf("Total amount: $%.2lf\n", total);
}
bool match()
{
	int i;
	bool flag = false;;

	for(i = 0; i < cnt; ++i){
		if(records_tmp[i].flag == 0){
			flag = true;
		}else if(flag && records_tmp[i].flag == 1)
			return true;
	}
	return false;
}
int main(void)
{
	int i, nrecord;
	char buf[BUFSIZ];

	// freopen("1016.in", "r", stdin);

	for(i = 0; i < 24; ++i)
		scanf("%d", &toll[i]);
	scanf("%d", &nrecord);

	for(i = 0; i < nrecord; ++i){
		scanf("%s %s %s", records[i].name, records[i].t, buf);
		records[i].flag = buf[1] == 'f';
		st.insert(records[i].name);
	}
	for(set<string>::iterator it = st.begin(); it != st.end(); ++it){
		/* name on alph order */
		memset(records_tmp, 0, sizeof(records_tmp));
		cnt = 0;
		for(i = 0; i < nrecord; ++i)
			if(strcmp(it->c_str(), records[i].name) == 0)
				records_tmp[cnt++] = records[i];
		sort(records_tmp, records_tmp + cnt, cmp);
		// for(i = 0; i < cnt; ++i)
		// 	printf("%s %s\n", records_tmp[i].t, records_tmp[i].flag ?
		// 		"off-line" : "on-line");
		if(!match()) continue;
		printf("%s %.2s\n", it->c_str(), records_tmp[0].t);
		
		calc();
	}

	return 0;
}