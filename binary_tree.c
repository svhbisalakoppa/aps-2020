#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node *left, *right; 
}node; 
node* create_tree(node* root, int num) 
{
	if(root==NULL) 
	{
		root=(node*)malloc(sizeof(node));
	    root->data=num;
	    printf("Element successfully added to tree\n");
	    root->left=root->right=NULL;
	    return root; 
	}
	else
	if(num<root->data)  
	root->left=create_tree(root->left,num);
	else
	if(num>root->data) 
  root->right=create_tree(root->right,num);
    else
	{
		printf("Duplicate elements are not allowed \n");
		return root; 
	}
}
void postorder(node* root) 
{
	if(root==NULL)
	printf("No elements to show \n");
	else
	{
			if(root->left != NULL) 
			postorder(root->left); 
			if(root->right != NULL) 
			postorder(root->right); 
			printf("%d\t",root->data);
	}
}
void search(node* root, int element )
{
	if(root==NULL) 
	printf("Element not found in tree\n");
	else
	if(element<root->data)
	search(root->left, element); 
	else
	if(element>root->data)
	search(root->right,element); 
	else
	printf("Element found\n");
}
	
main()
{
	int element; 
	node* root=NULL;
	while(1)
	{
		printf("\n*****MENU*****\n1) Store element in tree\n2) display postorder\n3) Search\n4) Exit\n Enter your choice \n");
		scanf("%d",&element);
		switch(element)
		{
		case 1 : printf("Enter the data\n");
	              	scanf("%d",&element); 
		              root=create_tree(root,element);
		              break; 
	   case 2 : postorder(root);
	                  break; 
	   case 3 : printf("Enter the element you want to search\n");
	                  scanf("%d",&element); 
	                  search(root,element);
	                  break; 
	   case 4 : exit(0);
		}
	}
}
