#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;
struct Student{
	int c;
	int m;
	int e;
	int a;
};
int *scoreC, *scoreM, *scoreE, *scoreA;
int rankC[103], rankM[103], rankE[103], rankA[103];
map<int, struct Student> mp;

const int INF = 0x3f3f3f3f;

bool cmp(int a, int b)
{
	return a > b;
}

int main(void)
{
	int nstu, nquery;
	int i;
	int id, c, m, e, a;
	int rc, rm, re, ra;
	int bestRank;
	char subject;

	// freopen("1012.in", "r", stdin);
	scanf("%d%d", &nstu, &nquery);
	scoreC = (int *)malloc(sizeof(int) * (nstu + 3));
	scoreM = (int *)malloc(sizeof(int) * (nstu + 3));
	scoreE = (int *)malloc(sizeof(int) * (nstu + 3));
	scoreA = (int *)malloc(sizeof(int) * (nstu + 3));
	memset(scoreC, 0, sizeof(*scoreC));
	memset(scoreM, 0, sizeof(*scoreM));
	memset(scoreE, 0, sizeof(*scoreE));
	memset(scoreA, 0, sizeof(*scoreA));

	for(i = 0; i < nstu; ++i){
		scanf("%d%d%d%d", &id, &c, &m, &e);
		a = (c + m + e) / 3;
		scoreC[i] = mp[id].c = c;
		scoreM[i] = mp[id].m = m;
		scoreE[i] = mp[id].e = e;
		scoreA[i] = mp[id].a = a;
	}
	sort(scoreC, scoreC + nstu, cmp);
	sort(scoreM, scoreM + nstu, cmp);
	sort(scoreE, scoreE + nstu, cmp);
	sort(scoreA, scoreA + nstu, cmp);
	
	memset(rankC, 0x3f, sizeof(rankC));
	memset(rankM, 0x3f, sizeof(rankM));
	memset(rankE, 0x3f, sizeof(rankE));
	memset(rankA, 0x3f, sizeof(rankA));

	for(i = 0; i < nstu; ++i){
		c = scoreC[i];
		m = scoreM[i];
		e = scoreE[i];
		a = scoreA[i];
		if(rankC[c] == INF) rankC[c] = i + 1;
		if(rankM[m] == INF) rankM[m] = i + 1;
		if(rankE[e] == INF) rankE[e] = i + 1;
		if(rankA[a] == INF) rankA[a] = i + 1;
	}

	for(i = 0; i < nquery; ++i){
		scanf("%d", &id);
		if(mp.find(id) == mp.end()){
			printf("N/A\n");
			continue;
		}
		bestRank = INF;
		rc = rankC[mp[id].c];
		rm = rankM[mp[id].m];
		re = rankE[mp[id].e];
		ra = rankA[mp[id].a];

		if(ra < bestRank){
			bestRank = ra;
			subject = 'A';
		}
		if(rc < bestRank){
			bestRank = rc;
			subject = 'C';
		}
		if(rm < bestRank){
			bestRank = rm;
			subject = 'M';
		}
		if(re < bestRank){
			bestRank = re;
			subject = 'E';
		}
		printf("%d %c\n", bestRank, subject);
	}

	return 0;
}