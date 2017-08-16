#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
	int key;
	struct Node *left;
	struct Node *right;
};
int pre[1010];
int pre_result[1010];
int pre_result_cnt;
struct Node *root;
int first;

struct Node *insert(struct Node *cur, int key)
{

	if(cur == NULL){
		cur = (struct Node *)malloc(sizeof(struct Node));
		cur->left = cur->right = NULL;
		cur->key = key;
		return cur;
	}
	if(key >= cur->key)
		cur->right = insert(cur->right, key);
	else
		cur->left = insert(cur->left, key);
	return cur;
}

struct Node *insert_mirror(struct Node *cur, int key)
{

	if(cur == NULL){
		cur = (struct Node *)malloc(sizeof(struct Node));
		cur->left = cur->right = NULL;
		cur->key = key;
		return cur;
	}
	if(key >= cur->key)
		cur->left = insert_mirror(cur->left, key);
	else
		cur->right = insert_mirror(cur->right, key);
	return cur;
}
int cmp()
{
	int i;

	for(i = 0; i < pre_result_cnt; ++i)
		if(pre_result[i] != pre[i])
			return 0;
	return 1;
}
void pre_traversal(struct Node *cur)
{
	if(cur == NULL) return;
	pre_result[pre_result_cnt++] = cur->key;
	pre_traversal(cur->left);
	pre_traversal(cur->right);
}
void post_traversal(struct Node *cur)
{
	if(cur == NULL) return;
	post_traversal(cur->left);
	post_traversal(cur->right);
	if(!first)
		putchar(' ');
	first = 0;
	printf("%d", cur->key);
}
int main(void)
{
	int nnode;
	int i;
	int key;
	int flag = 0;

	// freopen("1043_1.in", "r", stdin);
	root = NULL;
	scanf("%d", &nnode);
	for(i = 0; i < nnode; ++i){
		scanf("%d", &key);
		pre[i] = key;
		root = insert(root, key);
	}
	pre_result_cnt = 0;
	pre_traversal(root);
	if(!cmp()){
		root = NULL;
		for(i = 0; i < nnode; ++i)
			root = insert_mirror(root, pre[i]);
		pre_result_cnt = 0;
		pre_traversal(root);
		if(cmp()) flag = 1;
	}else
		flag = 1;
	
	if(flag){
		printf("YES\n");
		first = 1;
		post_traversal(root);	
	}else{
		printf("NO\n");
	}

	return 0;
}