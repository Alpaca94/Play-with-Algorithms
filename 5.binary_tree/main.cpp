#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct node {
	int val;
	struct node *left;
	struct node *right;
}node;

typedef struct tree {
	node *root;
	int n;
}tree;

node *get_new_node(int val) {
	node * n = (node *)malloc(sizeof(node));
	n->val = val;
	n->left = NULL;
	n->right = NULL;
	return n;
}

tree *get_new_tree() {
	tree *t = (tree *)malloc(sizeof(tree));
	t->root = NULL;
	t->n = 0;
	return t;
}

void clear_node(node *n) {
	if( n == NULL) return;
	clear_node(n->left);
	clear_node(n->right);
	free(n);
}

void clear_tree(tree *t) {
	if(t == NULL) return;
	clear_node(t->root);
	free(t);
}

void show_node(node *n) {
	if(n == NULL) return;
	printf(" %d ", n->val);
	if(n->left == NULL && n->right == NULL) return;
	printf("(");
	show_node(n->left);
	printf(",");
	show_node(n->right);
	printf(")");
}
void show_tree(tree *t) {
	printf("tree(%d) = ", t->n);
	show_node(t->root);
	printf("\n");
}

node* insert_node(node *root, int val, int *ret) {
	if(root == NULL) {
		*ret = 1;
		return get_new_node(val);
	}

	if(root->val == val) return root;
	if(root->val > val) {
		root->left = insert_node(root->left, val, ret);
	} else {
		root->right = insert_node(root->right, val, ret);
	}
	return root;
}

void insert(tree *t, int val) {
	int flag = 0;
	t->root = insert_node(t->root, val, &flag);
	t->n += flag;
}

void pre_order_node(node *n) {
	if(n == NULL) return;
	printf(" %d", n->val);
	pre_order_node(n->left);
	pre_order_node(n->right);
}
void pre_order(tree *t) {
	printf("pre_order : ");
	pre_order_node(t->root);
	printf("\n");
}

void in_order_node(node *n) {
	if(n == NULL) return;
	in_order_node(n->left);
	printf(" %d", n->val);
	in_order_node(n->right);
}
void in_order(tree *t) {
	printf("in_order : ");
	in_order_node(t->root);
	printf("\n");
}

void post_order_node(node *n) {
	if(n == NULL) return;
	post_order_node(n->left);
	post_order_node(n->right);
	printf(" %d", n->val);
}
void post_order(tree *t) {
	printf("post_order : ");
	post_order_node(t->root);
	printf("\n");
}

int main(int argc, char** argv) {
	srand(time(0));
	tree *t = get_new_tree();
	for(int i = 0; i < 10; i++) {
		int val = rand() % 100;
		insert(t, val);
		show_tree(t);
	}
	pre_order(t);
	in_order(t);
	post_order(t);
	return 0;
}