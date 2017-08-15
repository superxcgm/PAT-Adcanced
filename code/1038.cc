#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

struct Num{
	string data;
	int valid;
}nums[10005];

bool cmp(const Num &a, const Num &b)
{
	return a.data < b.data;
}

int main(void)
{
	int nnum;
	int i, j;
	char tmp[10];

	scanf("%d", &nnum);
	for(i = 0; i < nnum; ++i){
		scanf("%s", tmp);
		nums[i].valid = strlen(tmp);
		nums[i].data = "01234567";
		for(j = 0; j < 8; ++j)
			nums[i].data[j] = tmp[j % nums[i].valid];
	}
	sort(nums, nums + nnum, cmp);
	int flag = 0;
	for(i = 0; i < nnum; ++i)
		for(j = 0; j < nums[i].valid; ++j)
			if(flag){
				putchar(nums[i].data[j]);
			}else if(nums[i].data[j] != '0'){
				putchar(nums[i].data[j]);
				flag = 1;
			}
	if(!flag)
		putchar('0');
	return 0;
}