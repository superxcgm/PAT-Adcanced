#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
struct Node{
    int key;
    struct Node *left;
    struct Node *right;    
};
Node *root = NULL;
int first_print = 0;
Node *construct(Node *cur)
{
    char cmd[7];
    int key;
    Node *tmp;
    
    if(scanf("%s", cmd) == -1)
        return cur;
    //push
    if(cmd[1] == 'u'){
        scanf("%d", &key);
        tmp = (Node *)malloc(sizeof(Node));
        tmp->left = tmp->right = NULL;
        tmp->key = key;
        if(cur == NULL){    
            cur = tmp;
            cur->left = construct(cur->left);
            cur->right = construct(cur->right);
        }
    }
    return cur;
}
void post_traversal(Node *cur)
{
    if(cur == NULL) return ;
    post_traversal(cur->left);
    post_traversal(cur->right);
    if(first_print != 0)
        putchar(' ');
    printf("%d", cur->key);
    first_print = 1;
}
int main()
{
    int nnode;
    
    //freopen("1086.txt", "r", stdin);
    //freopen("1086.out.txt", "w", stdout);
    
    scanf("%d", &nnode);
    root = construct(root);
    post_traversal(root);
    return 0;
}