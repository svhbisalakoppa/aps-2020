#include<stdio.h>
#include<stdlib.h>
typedef struct queue
{
	int a[10];
	int front; 
	int rear; 
}que;
void push(que* q, int element);
int pop(que* q);
void display(que* q); 
main()
{
	int element;
	que q; 
	q.front=-1;
	q.rear=0;
	while(1)
	{
		printf("\n*****MENU*****\n1) Enqueue\n2) Dequeue\n3) Display\n4) Exit\nEnter your choice \n");
		scanf("%d",&element); 
		switch(element)
		{
			case 1 : printf("Enter the element\n");
			scanf("%d",&element);
			push(&q,element);
			break; 
		    case 2 : printf("Poped element is %d\n",pop(&q)); 
		    break; 
		    case 3 : display(&q); 
		                   break; 
		    case 4 : exit(0);
		}
	}
}
void push(que* q, int element) 
{
	if(q->rear!=9)
	{
		q->a[q->rear++]=element; 
		if(q->front==-1)
		q->front++;
	}
	else
	printf("overflow\n");
}

int pop(que* q) 
{
	if(q->front != -1 && q->front!=q->rear)
	return q->a[q->front++];
	else
		printf("underflow\n");
}

void display(que* q) 
{
	if(q->front != -1 && q->front!=q->rear)
	{
		printf("Queue elements are :\n");
		int i; 
		for(i=q->front; i<q->rear; i++)
		printf("%d\t",q->a[i]);
	}
}
