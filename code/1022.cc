#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <set>

using namespace std;

map<string, set<string> > athr;
map<string, set<string> > ttl;
map<string, set<string> > kywrds;
map<string, set<string> > pbshr;
map<int, set<string> > yr;

int main(void)
{
	int nbook;
	int i;
	char buf[BUFSIZ];
	char id[BUFSIZ];
	char title[BUFSIZ];
	char author[BUFSIZ];
	char keywords[BUFSIZ];
	char publisher[BUFSIZ];
	int query_type;
	char *query;
	int year;
	char *token;
	int nquery;

	// freopen("1022.in", "r", stdin);
	/* \n are necessary here */
	scanf("%d\n", &nbook);
	for(i = 0; i < nbook; ++i){
		gets(id);
		gets(title);
		ttl[title].insert(id);
		gets(author);
		athr[author].insert(id);
		gets(keywords);
		token = strtok(keywords, " ");
		while(token){
			kywrds[token].insert(id);
			token = strtok(NULL, " ");
		}
		gets(publisher);
		pbshr[publisher].insert(id);
		scanf("%d\n", &year);
		yr[year].insert(id);
	}
	scanf("%d\n", &nquery);
	for(i = 0; i < nquery; ++i){
		gets(buf);
		sscanf(buf, "%d:", &query_type);
		query = buf + 3;
		// printf("query_type: %d\n", query_type);
		// printf("query_for: %s\n", query);
		set<string> ans;
		switch(query_type){
			case 1:
				ans = ttl[query];
				break;
			case 2:
				ans = athr[query];
				break;
			case 3:
				ans = kywrds[query];
				break;
			case 4:
				ans = pbshr[query];
				break;
			case 5:
				sscanf(query, "%d", &year);
				ans = yr[year];
				break;
		}
		printf("%s\n", buf);
		for(set<string>::iterator it = ans.begin(); it != ans.end(); ++it)
			printf("%s\n", it->c_str());
		if(ans.empty())
			printf("%s\n", "Not Found");
	}

	return 0;
}
