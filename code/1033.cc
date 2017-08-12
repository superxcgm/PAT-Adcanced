#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const double EPS = 1e-6;

struct Station{
	double price;
	double dis;
}stations[505];
struct Gas
{
	double price;
	double num;
};
bool sort_by_dis(const Station &a, const Station &b)
{
	return a.dis < b.dis;
}
bool sort_by_price(const Gas &a, const Gas &b)
{
	return a.price < b.price;
}
bool sort_by_num(const Gas &a, const Gas &b)
{
	return a.num < b.num;
}
int main(void)
{
	/* capacity, distance of destination, distance per unit */
	int nstation;
	double des, price, max_dis, per_unit, cost, nunit, cap;
	int i, j;
	int cnt = 0;
	double dis;
	vector<Gas> have;
	double have_unit;
	int flag;
	Gas tmp_gas;

	// freopen("1033.in", "r", stdin);
	scanf("%lf%lf%lf%d", &cap, &des, &per_unit, &nstation);

	for(i = 0; i < nstation; ++i){
		scanf("%lf %lf", &price, &dis);
		if(dis >= des) continue;
		stations[cnt].price = price;
		stations[cnt++].dis = dis;
	}
	stations[cnt].price = 0;
	stations[cnt++].dis = des;
	nstation = cnt;
	sort(stations, stations + nstation, sort_by_dis);
	if(stations[0].dis != 0.0){
		printf("The maximum travel distance = 0.00\n");
		return 0;
	}
	tmp_gas.price = stations[0].price;
	tmp_gas.num = cap;
	have.push_back(tmp_gas);
	cost = 0;
	flag = 0;
	for(i = 1; i < nstation; ++i){
		int len;
		dis = stations[i].dis - stations[i - 1].dis;
		nunit = dis / per_unit; /* cost how much unit */
		len = have.size();
		/* calc cost */
		sort(have.begin(), have.end(), sort_by_price);
		for(j = 0; j < len; ++j){
			if(nunit <= have[j].num){
				cost += nunit * have[j].price;
				have[j].num -= nunit;
				nunit = 0;
				break;
			}else{
				cost += have[j].num * have[j].price;
				nunit -= have[j].num;
				have[j].num = 0;
			}
		}
		if(nunit != 0){
			flag = 1; /* can not arrive */
			max_dis = stations[i - 1].dis + per_unit * (dis * 1.0 / per_unit - nunit) ;
			break;
		}
		if(stations[i].dis == des) break;
		/* remove expensive oil */
		len = have.size();
		for(j = 0; j < len; ++j)
			if(have[j].price > stations[i].price)
				have[j].num = 0;
		sort(have.begin(), have.end(), sort_by_num);
		while(!have.empty() && have.begin()->num == 0)
			have.erase(have.begin());
		have_unit = 0;
		len = have.size();
		for(j = 0; j < len; ++j)
			have_unit += have[j].num;
		/* supplement */
		tmp_gas.price = stations[i].price;
		tmp_gas.num = cap - have_unit;
		have.push_back(tmp_gas);
	}
	if(flag)
		printf("The maximum travel distance = %.2lf\n", max_dis);
	else
		printf("%.2lf\n", cost);
	return 0;
}
/*
从s1处开始，带了50升，每升7.1元
s1->s2:
150公里，用了150/12 = 12.5升，每升7.1元, 还剩下37.5升。补了50升的7.0元，之前的油不要了。
s2->s3:
50公里，用了50/12 = 4.16升，每升7.0元。补了4.16升的7.2元，7.0元还剩下45.84升。
s3->s4:
100公里，用了100/12 = 8.33升，每升7.0元。之前的油不要了，补了50升的6.85元。
s4->s5:
100公里，用了100/12 = 8.33升，每升6.85元，补了8.33升的7.5元，还有41.67升的6.85元。
s5->s6:
200公里，用了200/12 = 16.66升，每升6.85元，补了16.66+8.33升的7.0元，还有25升的6.85元。
s6->s7:
400公里，用了400/12 = 33.33升，其中25升是6.85元，8.33升是7.0元。还有16.67升的7.0元
补了33.33升的7.3元
s7->s8:
250公里，用了20.83升，其中16.67升是7.0元，还有4.16升是7.3元。补了50升的6.0元
s8->des:
50公里，用了50/12=4.16升，每升6.0元


计算:
12.5 * 7.1 + 4.16 * 7.0 + 8.33 * 7.0 + 6.85*8.33 + 16.66 * 6.85 + 25*6.85
+ 8.33 * 7.0 + 16.67*7.0 + 4.16*7.3 + 4.16 * 6.0
 */