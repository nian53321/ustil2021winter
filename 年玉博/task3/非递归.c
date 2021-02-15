#include<stdio.h>
#include<stdlib.h>
#define N 20
typedef struct tree
{
	char data;
	struct tree *left;
	struct tree *right;

}Tree, *Treezz;

void creat(Treezz *T)//创建二叉树，按照先序方式建立
{
	char n;
	scanf("%c", &n);
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
	Treezz p;
	Treezz *s;
	int top = -1;
	s = (Treezz *)malloc((N + 1) * sizeof(Treezz));
	s[++top] = T;
	while (top != -1)
	{
		p = s[top--];
		printf("%c ", p->data);
		if (p->right)
			s[++top] = p->right;
		if (p->left)
			s[++top] = p->left;
	}
	free(s);
}

void zhongxu(Treezz T)//中序遍历
{
	Treezz p,q;
	Treezz *s;
	int top = -1;
	s = (Treezz *)malloc((N + 1) * sizeof(Treezz));
	if (T)
	{
		while (T)
		{
			s[++top] = T;
			T = T->left;
		}
		while (top != -1) //栈空结束
		{
			p = s[top--];//最开始指向左下角
			printf("%c ", p->data);
			while (p->right)//检测右节点
			{
				s[++top] = p->right;
				q = p->right;
				while (q->left)//判断q有无左子树
				{
					s[++top] = q->left;//左子树全入栈
					q = q->left;
				}
				break;
			}
		}
	}
}

void houxu(Treezz T)//后序遍历
{
	Treezz p;
	Treezz *s;
	int top = -1;
	s = (Treezz *)malloc((N + 1) * sizeof(Treezz));
	do
	{
		while (T)
		{
			s[++top] = T;//所有左面的入栈
			T = T->left;//指向下一个左子树
		}
		p = NULL;
		while (top != -1)
		{
			T = s[top];
			if (T->right == p)
			{
				printf("%c ", T->data);
				top--;
				p = T;//记录访问节点
			}
			else
			{
				T = T->right;//访问右子树
				break;
			}
		}
	} while (top != -1);
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
