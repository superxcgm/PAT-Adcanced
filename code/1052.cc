#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

struct Node {
	int addr;
	int key;
	int next;
};

map<int, Node> mp;
vector<Node> vt;

bool cmp(const Node &a, const Node &b)
{
	return a.key < b.key;
}

int main(void)
{
	int nnode, first_node;
	int i, j;
	int addr;
	int addr_next;
	int len;
	Node tmp_node;

	scanf("%d %d", &nnode, &first_node);

	for(i = 0; i < nnode; ++i){
		scanf("%d%d%d", &addr, &tmp_node.key, &tmp_node.next);
		tmp_node.addr = addr;
		mp[addr] = tmp_node;
	}
	addr_next = first_node;
	if(addr_next == -1){
		printf("0 -1\n");
		return 0;
	}
	while(addr_next != -1){
		vt.push_back(mp[addr_next]);
		addr_next = mp[addr_next].next;
	}
	sort(vt.begin(), vt.end(), cmp);
	printf("%d %.5d\n", len = vt.size(), vt[0].addr);
	for(i = 0; i < len - 1; ++i)
		printf("%.5d %d %.5d\n", vt[i].addr, vt[i].key, vt[i + 1].addr);
	printf("%.5d %d -1\n", vt[len - 1].addr, vt[len - 1].key);
	
	return 0;
}