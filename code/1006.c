#include <stdio.h>
#include <stdlib.h>
#define SIGN_IN 0
#define SIGN_OUT 1
int sort_by;
struct record{
	char name[18];
	int sign_in;
	int sign_out;
} records[BUFSIZ];

int cmp(const void *a, const void *b)
{
	if(sort_by == SIGN_IN)
		return ((struct record *)a)->sign_in - ((struct record *)b)->sign_in;
	return ((struct record *)b)->sign_out - ((struct record *)a)->sign_out;
}

int time_to_second(const char *tm)
{
	int h, m, s;
	sscanf(tm, "%d:%d:%d", &h, &m, &s);
	return h * 3600 + m * 60 + s;
}
int main(void)
{
	int m;
	int i;
	char sign_in_t[20];
	char sign_out_t[20];

	// freopen("1006.in", "r", stdin);
	scanf("%d", &m);
	for(i = 0; i < m; ++i){
		scanf("%s %s %s", records[i].name, sign_in_t, sign_out_t);
		records[i].sign_in = time_to_second(sign_in_t);
		records[i].sign_out = time_to_second(sign_out_t);
	}

	sort_by = SIGN_IN;
	qsort(records, m, sizeof(struct record), cmp);
	// for(i = 0; i < m; ++i)
	// 	printf("%s\n", records[i].name);
	printf("%s ", records[0].name);

	sort_by = SIGN_OUT;
	qsort(records, m, sizeof(struct record), cmp);
	// for(i = 0; i < m; ++i)
	// 	printf("%s\n", records[i].name);
	printf("%s", records[0].name);

	return 0;
}