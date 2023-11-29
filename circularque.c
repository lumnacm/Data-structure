#include<stdio.h>
#include<stdlib.h>
#define size 10


int que[size];
int front =0,rear=0;
void main()
{
void enque(int);
int deque();
int search(int),ans;
int option,item;
do
{
printf("\n\n1.insert\n");
printf("2.delete\n");
printf("3.search\n");
printf("4.exit\n");
printf("option:");
scanf("%d",&option);
switch(option)
{
     case 1:printf("item:");
            scanf("%d",& item);
            enque(item);
            break;
            
            
     case 2:item=deque();
           printf("item=%d",item);
          
           break;
           
           
    case 3:printf("item to search:");
          scanf("%d", & item);
          ans=search(item);
          if(ans!=0)
          {
          	printf("%d found at %d position\n",item,ans);
          	break;
          }
          else
          {	printf("%d not found\n",item);
         	break;
          } 
          
   case 4:exit(0);
   }
   }
 
while(1);
}

//fn to insert an item in circular queue

void enque(int item)
{
int t;
t=(rear+1)%size;
if(t==front)
{
printf ("que is full:");
exit(1);
}
else
{
rear=t;
que[rear]=item;
}
}
 
//fn to delete an item

int deque()
{

if (front==rear)
{
printf("que is empty");
exit(2);
}
front=(front+1)%size;
return que[front];
}

// fn to search an item

int search(int item)
{

int t1,t2;
t1=front,t2=rear;
t1=(t1+1)%size;
while (t1!=t2 && que[t1]!=item)
t1=(t1+1)%size;
if(que[t1]==item)
return t1;
else
return 0;
}



