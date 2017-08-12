#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account{
	char name[12];
	char pwd[12];
}account[1010];

int correct(char *str)
{
	int ismodified = 0;
	while(*str){
		switch(*str){
			case '1':
				*str = '@';
				ismodified = 1;
				break;
			case '0':
				*str = '%';
				ismodified = 1;
				break;
			case 'l':
				*str = 'L';
				ismodified = 1;
				break;
			case 'O':
				*str = 'o';
				ismodified = 1;
				break;
		}
		str++;
	}
	return ismodified;
}

int main(void)
{
	int naccount;
	int nmodified = 0;
	int i;
	char name[12], pwd[12];
	struct Account tmp_account;

	scanf("%d", &naccount);
	for(i = 0; i < naccount; ++i){
		scanf("%s%s", name, pwd);
		if(correct(pwd)){
			strcpy(tmp_account.name, name);
			strcpy(tmp_account.pwd, pwd);
			account[nmodified++] = tmp_account;
		}
	}
	if(nmodified){
		printf("%d\n", nmodified);
		for(i = 0; i < nmodified; ++i)
			printf("%s %s\n", account[i].name, account[i].pwd);
	}else{
		if(naccount == 1)
			printf("There is 1 account and no account is modified\n");
		else
			printf("There are %d accounts and no account is modified\n",
			    naccount);
	}

	return 0;
}