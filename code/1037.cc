#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

long long coupon[100005];
long long product[100005];
bool cmp(const int &a, const int &b)
{
	return a > b;
}
int main(void)
{
	int ncoupon, nproduct;
	int i;
	int p, q;
	long long ans = 0;

	// freopen("1037.in", "r", stdin);
	scanf("%d", &ncoupon);
	for(i = 0; i < ncoupon; ++i)
		scanf("%lld", &coupon[i]);

	scanf("%d", &nproduct);
	for(i = 0; i < nproduct; ++i)
		scanf("%lld", &product[i]);
	
	sort(coupon, coupon + ncoupon, cmp);
	sort(product, product + nproduct, cmp);
	p = q = 0;

	while(p < ncoupon && q < nproduct && coupon[p] > 0 && product[q] > 0)
		ans += coupon[p++] * product[q++];
	p = ncoupon - 1;
	q = nproduct -1;
	while(p >= 0 && q >= 0 && coupon[p] < 0 && product[q] < 0)
		ans += coupon[p--] * product[q--];

	printf("%lld\n", ans);

	return 0;
}


