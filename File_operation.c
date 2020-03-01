#include<stdio.h>
#include<stdlib.h>
main()
{
  FILE *p,*q,*r;
  char c;
  int j,a;
  p=fopen("names.txt","r");
  q=fopen("rollno.txt","r");
  r=fopen("name_no.txt","w");
  if(p==NULL || q==NULL)
  {
    printf("File 'names.txt' is not present.\n");
    exit(0);
  }
  else
  {
    fprintf(r,"Names - Roll No. \n");
    while(!feof(p))
    {
     while(1)
     {
       c=fgetc(p);
       if(c=='\n') 
       break; 
       if(feof(p))
       break; 
      
fputc(c,r);
     }
      fscanf(q,"%d",&a);
     fprintf(r," - %d\n",a);
    }
  }
fclose(p);
fclose(q);
fclose(r);
}
