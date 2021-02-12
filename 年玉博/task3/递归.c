#include<stdio.h>
#include<stdlib.h>

typedef struct tree
{
	char data;
	struct tree *left;
	struct tree *right;
}Tree,*Treezz;

void creat(Treezz *T)//创建二叉树，按照先序方式建立
{
	char n;
	scanf("%c",&n);
	if (n == '#')
	{
		*T = NULL;
	}
	else
	{
		*T = (Treezz)malloc(sizeof(Tree));
		(*T)->data = n;
		creat(&(*T)->left);
		creat(&(*T)->right);
	}
}

void xianxu(Treezz T)//先序遍历
{
	if (T == NULL)
		return;
	printf("%c ", T->data);
	xianxu(T->left);
	xianxu(T->right);
}

void zhongxu(Treezz T)//中序遍历
{
	if (T == NULL)
		return;
	zhongxu(T->left);
	printf("%c ", T->data);
	zhongxu(T->right);
}

void houxu(Treezz T)//后序遍历
{
	if (T == NULL)
		return;
	houxu(T->left);
	houxu(T->right);
	printf("%c ", T->data);
}

void main()
{
	printf("请按照先序方式输入二叉树：\n");
	Treezz T;
	T = (Treezz)malloc(sizeof(Tree));
	creat(&T);

	printf("先序遍历\n");
	xianxu(T);
	printf("\n");

	printf("中序遍历\n");
	zhongxu(T);
	printf("\n");

	printf("后序遍历\n");
	houxu(T);
	printf("\n");
}
