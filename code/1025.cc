#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;
struct RankItem{
	string id;
	int score;
	int place;
	int rank_local;
}local[303], total[30003];
bool cmp(struct RankItem &a, struct RankItem &b)
{
	if(a.score != b.score)
		return a.score > b.score;
	else
		return a.id < b.id;
}
int main(void)
{
	int nplace, ntestee;
	int i, j;
	int tp = 0;	/* total pointer */
	char buf[BUFSIZ];
	int pre_score;
	int pre_rank;

	scanf("%d", &nplace);
	for(i = 1; i <= nplace; ++i){
		scanf("%d", &ntestee);
		for(j = 0; j < ntestee; ++j){
			scanf("%s %d", buf, &local[j].score);
			local[j].place = i;
			local[j].id = buf;
			local[j].rank_local = -1;
		}
		sort(local, local + ntestee, cmp);
		// printf("sort result: \n");
		pre_score = -1;
		for(j = 0; j < ntestee; ++j){
			local[j].rank_local = local[j].score == pre_score ?
			local[j - 1].rank_local : j + 1;
			pre_score = local[j].score;
			total[tp++] = local[j];
			// printf("%s %d %d\n", local[j].id.c_str(), local[j].score,
			// 	local[j].rank_local);
		}
	}
	printf("%d\n", tp);
	sort(total, total + tp, cmp);
	pre_score = -1;
	pre_rank = -1;
	for(i = 0; i < tp; ++i){
		printf("%s %d %d %d\n", total[i].id.c_str(),
			pre_rank = total[i].score == pre_score ? pre_rank : i + 1,
			total[i].place, total[i].rank_local);
		pre_score = total[i].score;
	}

	return 0;
}