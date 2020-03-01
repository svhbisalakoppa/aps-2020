#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50
int a[6][6]={
              0,0,0,0,0,0,
              0,1,0,0,1,0,
              0,1,1,1,1,0,
              0,1,0,1,0,0,
              0,1,0,1,1,0,
              0,0,0,0,0,0
};
char path[6][6]={
              '1','1','1','1','1','1',
              '1','1','1','1','1','1',
              '1','1','1','1','1','1',
              '1','1','1','1','1','1',
              '1','1','1','1','1','1',
              '1','1','1','1','1','1'              
};
struct stack
{
    int row[MAXSIZE];
     int col[MAXSIZE];
    int top;
};
typedef struct stack STACK;
STACK s;
void push (int x,int y)
{

    if (s.top == (MAXSIZE - 1))
    {
        printf ("Stack is Full\n");
        return;
    }
    else
    {

        s.top = s.top + 1;
        s.row[s.top] = x;
        s.col[s.top] = y;

    }
   return ;
}
void pop ()
{
    if (s.top == - 1)
    {
        printf ("Stack is Empty\n");
        return ;
    }
    else
    {
        s.top = s.top - 1;
    }

}
int findpath(int i,int j,int n)
{
    if((i==n-2)&&(j==n-2))
    {
        path[i][j]='.';
          push(i,j);
    return 1;
    }
    if(a[i][j]==1)
    {
        path[i][j]='.';
        push(i,j);
        if(findpath(i,j+1,n)==1)return 1;
        if(findpath(i+1,j,n)==1)return 1;
         path[i][j]='1';
         pop();
    }
    return 0;

}
void display ()
{
    int i;
    if (s.top == -1)
    {
        printf ("Stack is empty\n");
        return;
    }
    else
    {
        printf ("\n The status of the stack is \n");
        for (i =0; i<=s.top ; i++)
        {
            printf ("(%d,%d)\n", s.row[i],s.col[i]);
        }
    }
    printf ("\n");
}

int main()
{int i,j;

   findpath(1,1,6);
   for(i=0;i<6;i++)
   {
    for(j=0;j<6;j++)
    {
    printf("%c\t",path[i][j]);

    }
    printf("\n");
   }
   display ();
}

