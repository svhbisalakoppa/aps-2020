#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int stack[30],top=-1,to=-1; 
char postfix[30];
void push(int ); 
int pop(void );
int empty(void );
int full(void );
 		
int empty (void) 
{
	if(top==-1)
	return 1;
	else
	return 0; 
}
int full(void)
{
	if(top==29)
	return 1;
	else 
	return 0; 
}
int pop(void)
{
	if(!empty())
	return stack[top--];
	else
    {
	   printf("Invalid expression \n");
	   exit(0);
    }
}
void push (int a) 
{ 
	if(!full())
	stack[++top]=a;
	else
	{
		printf("Stack overflow \n");
		exit(0);
	}
}
main()
{
	char e[30];
	int i,x,y,r; 
	printf("Enter the expression :\n");
	scanf("%s",e);
	for (i=0;e[i]!='\0';i++)
	{
		if(e[i]=='('){
		printf("hi");
		exit(0);
	}if(e[i]>='0'&&e[i]<='9')
		       push(e[i]-48);
		else
		{
			x=pop();
			y=pop();
	        switch(e[i])
	        {
	        	case '+' : push(y+x);
	        	break; 
	        	case '-' : push(y-x); 
	        	break; 
	        	case '*' : push(y*x);
	        	break;
	        	case '/': push(y/x);
	        	break; 
	        	case '$' : push(pow(y,x));
	        	break; 
	        	default : printf("Invalid Expression \n");
	        	exit(0);
	        }
		}
	}
	printf("Result=%d\n",stack[top]);
}
