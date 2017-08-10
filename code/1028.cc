#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

struct Record{
	char id[8];
	int id_num;
	char name[10];
	int grade;
}records[100003];
bool sort_by_id(const Record &a, const Record &b)
{
	return a.id_num < b.id_num;
}
bool sort_by_name(const Record &a, const Record &b)
{
	return strcmp(a.name, b.name) <= 0 ;
}
bool sort_by_grade(const Record &a, const Record &b)
{
	return a.grade <= b.grade;
}
int main(void)
{
	int nrecord, sort_column;
	int i;

	// freopen("1028.in", "r", stdin);
	scanf("%d %d", &nrecord, &sort_column);
	for(i = 0; i < nrecord; ++i){
		scanf("%s %s %d", records[i].id, records[i].name,
			&records[i].grade);
		
		sscanf(records[i].id, "%d", &records[i].id_num);
	}
	switch(sort_column){
		case 1:
			sort(records, records + nrecord, sort_by_id);
			break;
		case 2:
			sort(records, records + nrecord, sort_by_name);
			break;
		case 3:
			sort(records, records + nrecord, sort_by_grade);
			break;
	}
	for(i = 0; i < nrecord; ++i)
		printf("%s %s %d\n", records[i].id, records[i].name,
			records[i].grade);
	
	return 0;
}