#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

using namespace std;

struct Node{
	struct Node *left;
	struct Node *right;
	int data;
};

int post_order[32], in_order[32];

struct Node *new_node(int value)
{
	struct Node *ans;

	ans = (struct Node *)malloc(sizeof(struct Node));
	ans->left = NULL;
	ans->right = NULL;
	ans->data = value;
	return ans;
}
int in_array(int value, int from, int to)
{
	int i;

	for(i = from; i <= to; ++i)
		if(in_order[i] == value)
			return true;
	return false;
}

struct Node *generate_tree(int p_from, int p_to, int i_from, int i_to)
{
	struct Node *ans;
	int i, idx;
	int idx_last; /* index of last element of left subtree in
				the post_order */
	if(p_from > p_to) return NULL;
	if(p_from == p_to)
		return new_node(post_order[p_to]);
	for(i = i_from; i <= i_to; ++i)
		if(in_order[i] == post_order[p_to])
			break;
	idx = i; /* mid in in_order */
	idx_last = p_from + (idx - 1 - i_from);
	ans = new_node(post_order[p_to]);
	ans->left = generate_tree(p_from, idx_last, i_from, idx - 1);
	ans->right = generate_tree(idx_last + 1, p_to - 1, idx + 1, i_to);
	return ans;
}
void level_order_traversal(struct Node *root)
{
	struct Node *tmp;

	queue<struct Node *> qu;
	qu.push(root);
	while(!qu.empty()){
		tmp = qu.front();
		qu.pop();
		
		printf(tmp == root ? "%d" : " %d", tmp->data);
		
		if(tmp->left != NULL)
			qu.push(tmp->left);
		if(tmp->right != NULL)
			qu.push(tmp->right);
	}

}
int main(void)
{
	struct Node *tree;
	int i, nnode;

	// freopen("1020.in", "r", stdin);
	scanf("%d", &nnode);
	for(i = 0; i < nnode; ++i)
		scanf("%d", &post_order[i]);
	for(i = 0; i < nnode; ++i)
		scanf("%d", &in_order[i]);
	tree = generate_tree(0, nnode - 1, 0, nnode - 1);
	level_order_traversal(tree);

	return 0;
}