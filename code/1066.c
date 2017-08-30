#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
	int key;
	int height;
	struct Node *left;
	struct Node *right;
};
int max(int a, int b)
{
	return a > b ? a : b;
}
int get_height(struct Node *cur)
{
	if(cur == NULL)
		return 0;
	return cur->height;
}
struct Node *left_rotate(struct Node *cur)
{
	struct Node *tmp = cur->left;

	cur->left = cur->left->right;
	tmp->right = cur;
	tmp->height = max(get_height(tmp->left), get_height(tmp->right)) + 1;
	cur->height = max(get_height(cur->left), get_height(cur->right)) + 1;
	return tmp;
}
struct Node *right_rotate(struct Node *cur)
{
	struct Node *tmp = cur->right;

	cur->right = cur->right->left;
	tmp->left = cur;
	tmp->height = max(get_height(tmp->left), get_height(tmp->right)) + 1;
	cur->height = max(get_height(cur->left), get_height(cur->right)) + 1;
	return tmp;
}
struct Node *insert_node(struct Node *cur, int key)
{
	if(cur == NULL){
		cur = (struct Node *)malloc(sizeof(struct Node));
		cur->left = cur->right = NULL;
		cur->height = 1;
		cur->key = key;
		return cur;
	}
	if(key >= cur->key){
		cur->right = insert_node(cur->right, key);
		if(get_height(cur->left) - get_height(cur->right) == -2)
			if(key > cur->right->key)
				cur = right_rotate(cur);
			else{
				/* right-left rotate */		
				cur->right = left_rotate(cur->right);
				cur = right_rotate(cur);
			}
		
	}else{
		cur->left = insert_node(cur->left, key);
		if(get_height(cur->left) - get_height(cur->right) == 2)
			if(key < cur->left->key)
				cur = left_rotate(cur);
			else{
				/* left-right rotate */
				cur->left = right_rotate(cur->left);
				cur = left_rotate(cur);
			}
	}
	cur->height = max(get_height(cur->left), get_height(cur->right)) + 1;
	return cur;
}
int main(void)
{
	int nnode;
	int i, j;
	int key;
	struct Node *root = NULL;

	// freopen("1066.in", "r", stdin);
	scanf("%d", &nnode);
	while(nnode--){
		scanf("%d", &key);
		root = insert_node(root, key);
	}
	printf("%d\n", root->key);
	return 0;
}