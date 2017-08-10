#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

long long arr_result[2000003];



int main()
{
	int na, nb;
	int i;
	int idx = 0;

	scanf("%d", &na);
	for(i = 0; i < na; ++i)
		scanf("%lld", &arr_result[idx++]);

	scanf("%d", &nb);
	for(i = 0; i < nb; ++i)
		scanf("%lld", &arr_result[idx++]);

	sort(arr_result, arr_result + idx);
	
	printf("%lld\n", arr_result[(na + nb - 1) / 2]);
	return 0;
}