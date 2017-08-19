#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int coin[100003];

bool fin(int x, int l, int r)
{
	if(l <= r){
		int mid = (l + r) / 2;
		if(coin[mid] > x)
			return fin(x, l, mid - 1);
		else if(coin[mid] < x)
			return fin(x, mid + 1, r);
		else
			return true;
	}
	return false;
}

bool cmp(const int &a, const int &b)
{
	return a < b;
}
int main(void)
{
	int ncoin, has_to_pay;
	int left; /* left money need to pay */
	int i;

	scanf("%d%d", &ncoin, &has_to_pay);

	for(i = 0; i <= ncoin; ++i)
		scanf("%d", &coin[i]);
	sort(coin, coin + ncoin, cmp);

	for(i = 0; i < ncoin; ++i){
		if(i > 0 && coin[i] == coin[i - 1])
			continue;
		left = has_to_pay - coin[i];
		if(fin(left, i + 1, ncoin - 1)){
			printf("%d %d\n", coin[i], left);
			return 0;
		}
	}
	printf("No Solution\n");
	return 0;
}