#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left, *right;
};
struct node *insert(struct node *, struct node *);
void inorder(struct node *cur);
void preorder(struct node *cur);
void postorder(struct node *cur);
int max(struct node *cur);
int min(struct node *cur);
int height(struct node *cur);
struct node *deletenode(struct node *root, int key);
struct node *minValueNode(struct node *tree);
void freenode(struct node *p)
{
	freenode(p);
}

int main()
{
	int ch, data, d, item;
	struct node *root = NULL, *nw;
	while (1)
	{
		printf
			(" 1-insert\n 2-inorder\n 3-preorder\n 4-postorder\n 5-minimum\n 6-maximum\n 7-height\n 8-delete\n 9-exit\n");
		printf("enter choice\n");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			nw = (struct node *)malloc(sizeof(struct node));
			nw->left = nw->right = NULL;
			printf("enter number to be inserted\n");
			scanf("%d", &nw->data);
			root = insert(root, nw);
			break;
		case 2:
			inorder(root);
			break;
		case 3:
			preorder(root);
			break;
		case 4:
			postorder(root);
			break;
		case 5:
			min(root);
			printf("min %d\n", min(root));
			break;
		case 6:
			max(root);
			printf("max %d\n", max(root));
			break;
		case 7:
			height(root);
			printf("height %d\n", height(root));
			break;
		case 8:
			printf("enter the number to be deleted\n");
			scanf("%d", &data);
			root = deletenode(root, data);
			break;
		case 9:
			return 0;
		}
	}
}

struct node *insert(struct node *root, struct node *nw)
{
	char ch;
	struct node *cur;
	if (root == NULL)
		return (nw);
	cur = root;
	while (1)
	{
		if (nw->data < cur->data)
		{
			if (cur->left == NULL)
			{
				cur->left = nw;
				break;
			}
			else
				cur = cur->left;
		}
		else if (nw->data > cur->data)
		{
			if (cur->right == NULL)
			{
				cur->right = nw;
				break;
			}
			else
				cur = cur->right;
		}
		else
		{
			printf("node exist");
			free(nw);
			break;
		}
	}
	return (root);
}

void inorder(struct node *cur)
{
	if (cur == NULL)
	{
		return;
	}
	inorder(cur->left);
	printf("%d\t", cur->data);
	inorder(cur->right);
}

void preorder(struct node *cur)
{
	if (cur == NULL)
	{
		return;
	}
	printf("%d\t", cur->data);
	inorder(cur->left);
	inorder(cur->right);
}

void postorder(struct node *cur)
{
	if (cur == NULL)
	{
		return;
	}
	inorder(cur->left);
	inorder(cur->right);
	printf("%d\t", cur->data);
}

int min(struct node *cur)
{
	if (cur->left == NULL)
		return (cur->data);
	else
		min(cur->left);
}

int max(struct node *cur)
{
	if (cur->right == NULL)
		 return (cur->data);
	else
		max(cur->right);
}

int height(struct node *cur)
{
	int leftheight, rightheight;
	if (cur == NULL)
		return (0);
	else
	{
		leftheight = height(cur->left);
		rightheight = height(cur->right);
		if (leftheight > rightheight)
			return (leftheight + 1);
		else
			return (rightheight + 1);
	}
}

struct node *deletenode(struct node *root, int key)
{
	if (root == NULL)
		return root;
	if (key < root->data)
		root->left = deletenode(root->left, key);
	else if (key > root->data)
		root->right = deletenode(root->right, key);
	else
	{
		if (root->left == NULL)
		{
			struct node *temp = root->right;
			free(root);
			return temp;
		}
		if (root->right == NULL)
		{
			struct node *temp = root->left;
			free(root);
			return (temp);
		}
		struct node *temp = minValueNode(root->right);
		root->data = temp->data;

		root = deletenode(root->right, temp->data);
		return root;
	}
}

struct node *minValueNode(struct node *tree)
{
	struct node *current = tree;
	while (current->left != NULL)
		current = current->left;
	return current;
}
