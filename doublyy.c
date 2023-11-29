#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left,*right;
};
int main()
{
	struct node*insert(struct node*,int);
	struct node*delete(struct node*,int);
	struct node*search(struct node*,int);
	int option,data;
	struct node*dl=(struct node*)0,*ans;
	do
	{
	printf("\n 1.insert \n");
	printf("\n 2.delete \n");
	printf("\n 3.Search \n");
	printf("\n 4.Exit \n");
	printf("\n Option : ");
	scanf("%d",&option);
	switch(option)
	{
	case 1:printf(" Data : ");
		scanf("%d",&data);
		dl=insert(dl,data);
		break;
	case 2:printf(" item: ");
		scanf("%d",&data);
		dl=delete(dl,data);
		break;
	case 3:printf(" item : ");
		scanf("%d",&data);
		ans=search(dl,data);
		if(ans==(struct node*)0)
		printf(" Item not found \n");
		else
		printf(" Item found \n");
		break;
	case 4:exit(0);
}
}
while(1);
}
//function to insert an item in doubly linked list
struct node* insert(struct node *dl,int item)
{
	struct node *t;
	t=(struct node *)malloc(sizeof(struct node));
	t->data=item;
	t->left=(struct node *)0;
	t->right=dl;
	if(dl!=(struct node *)0)
	dl->left=t;
	return t;
}
//function to search an item
struct node*search(struct node *dl,int item)
{
	while(dl!=(struct node*)0 && dl->data!=item)
	dl=dl->right;
	return dl;
}
//function to delete an item
struct node *delete(struct node *dl,int item)
{
struct node*t;
t=search(dl,item);
if(t==(struct node *)0)//dl=0 item not found
printf(" Not Found\n");
else
{
	if(t->left==(struct node*)0 &&(t->right==(struct node *)0))
	dl=(struct node*)0;
	else if(t->left==(struct node *)0)//first node removal
	{
	t->right->left=t->left;
	dl=dl->right;
	}
	else if(t->right==(struct node *)0)//last node removal
	t->left->right=t->right;
	else//removal of interior node
	{
	t->left->right=t->right;
	t->right->left=t->left;
	}
	free(t);
	printf("%d deleted", item);
}
return dl;
}
