#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	char snum[5];
	int num;
	int num1, num2;

	scanf("%d", &num);
	sprintf(snum, "%.4d", num);
	if(snum[0] == snum[1] && snum[0] == snum[2] &&
		snum[0] == snum[3]){
		printf("%s - %s = 0000\n", snum, snum);
		return 0;
	}
	do{
		sort(snum, snum + 4, greater<int>());
		printf("%s - ", snum);
		sscanf(snum, "%d", &num1);
		sort(snum, snum + 4);
		printf("%s = ", snum);
		sscanf(snum, "%d", &num2);
		sprintf(snum,"%.4d", num = num1 - num2);
		printf("%s\n", snum);
	}while(num != 6174);
	return 0;
}