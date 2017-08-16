#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;
struct Pair{
	int from;
	int to;
};
vector<struct Pair>  vt;
const int INF = 0x3f3f3f3f;
int diamonds[100005];

int main(void)
{
	int ndiamond, have_to_pay;
	int diamond;
	int i, from;
	int sum;
	int min_lost = INF;
	struct Pair tmp_pair;

	// freopen("1044.in", "r", stdin);
	scanf("%d%d", &ndiamond, &have_to_pay);
	from = 0;
	sum = 0;
	for(i = 0; i < ndiamond; ++i){
		scanf("%d", &diamond);
		diamonds[i] = diamond;
		sum += diamond;
		while(sum >= have_to_pay){
			if(sum - have_to_pay <= min_lost){
				if(sum - have_to_pay < min_lost){
					min_lost = sum - have_to_pay;
					vt.clear();
				}
				tmp_pair.from = from + 1;
				tmp_pair.to = i + 1;
				vt.push_back(tmp_pair);
			}
			sum -= diamonds[from++];
		}	
	}
	int len = vt.size();
	for(i = 0; i < len; ++i)
		printf("%d-%d\n", vt[i].from, vt[i].to);

	return 0;
}