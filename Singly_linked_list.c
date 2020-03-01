#include<stdio.h>
#include<stdlib.h>
struct node
{
	int x;
	struct node *p;
};
int main()
{
	int h;
	struct node *e, *q;
	struct node *a = NULL;
	while (1)
	{
		printf
			("\n*****MENU*****\n1) Push from the beginning \n2) Push from the end\n3) Delete from the beginning\n4) Delete from the end\n5) Display\n6) Exit\n Enter the no. given in the menu to perform it's function\n");
		scanf("%d", &h);
		switch (h)
		{
		case 1:
			printf("Enter an integer to add in the linked list\n");
			scanf("%d", &h);
			e = (struct node *)malloc(sizeof(struct node));
			e->x = h;
			if (a == NULL)
			{
				a = e;
				a->p=NULL;
			}
			else
			{
				e->p=a;
				a=e;
			}
			break;
		case 2:
			printf("Enter an integer to add in the linked list\n");
			scanf("%d", &h);
			e = (struct node *)malloc(sizeof(struct node));
			e->x = h;
			if (a == NULL)
			{
				a = e;
				a->p = NULL; 
			}
			else
			{
				q = a;
				while (q->p != NULL)
					q = q->p;
				q->p = e;
				e->p = NULL;
			}
			break;
		case 3:
			if (a == NULL)
				printf("No elements to delete\n");
			else if (a->p == NULL)
			{
				printf("Deleted element is %d\n", a->x);
				a = NULL;
				free(a);
			}
			else
			{
				e=a;
				printf("Deleted element is %d\n", a->x);
				a=a->p; 
				free(e);
			}
			break;
		case 4:
			if (a == NULL)
				printf("No elements to delete \n");
			else if (a->p == NULL)
			{
				printf("Deleted element is %d\n", a->x);
				a = NULL;
				free(a);
			}
			else
			{
				q = a;
				while (q->p->p != NULL)
					q = q->p;
				printf("Deleted element is %d\n", q->p->x);
				e = q->p;
				q->p =NULL;
				free(e);
			}
			break;
		case 5:
			if (a == NULL)
				printf("No elements to display \n");
			else
			{
				q = a;
				while (q!=NULL)
				{
					printf("%d->",q->x);
					q = q->p;
				}
			}
			break;
		case 6:
			exit(0);
		}
	}
	return 0;
}
