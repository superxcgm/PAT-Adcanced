#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int is_pal(const char *str)
{
	const char *p = str;
	const char *q = str + strlen(str) - 1;

	while(p < q)
		if(*p++ != *q--)
			return 0;
	return 1;
}
/* add num2 to num1 */
void add(char *num1, char *num2)
{
	int carry = 0;
	int len = strlen(num1);
	int i;
	int tmp;

	for(i = len - 1; i >= 0; --i){
		tmp = num1[i] - '0' + num2[i] - '0' + carry;
		carry = tmp / 10;
		tmp %= 10;
		num1[i] = tmp + '0';
	}
	if(carry){
		num1[len + 1] = '\0';
		for(i = len - 1; i >= 0; --i)
			num1[i + 1] = num1[i];
		num1[0] = carry + '0';
	}
}
int main(void)
{
	char num[BUFSIZ];
	char tmp[BUFSIZ];
	int max_time, i;

	// freopen("1024.in", "r", stdin);
	scanf("%s%d", num, &max_time);

	if(is_pal(num)){
		printf("%s\n", num);
		printf("0\n");
		return 0;
	}
	for(i = 1; i <= max_time; ++i){
		strcpy(tmp, num);
		reverse(tmp, tmp + strlen(tmp));
		add(num, tmp);
		if(is_pal(num)) break;
	}
	if(i > max_time) i = max_time;
	printf("%s\n", num);
	printf("%d\n", i);

	return 0;
}