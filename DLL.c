// Design, Develop and Implement a menu driven program in C for the following operations on
// Doubly Linked List (DLL) of Professor Data with the fields: ID, Name, Branch, Area of specialization
// a. Create a DLL stack of N professor's data
// Display the status of DLL and count the number of nodes in it.

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int MAX=4, count;

struct prof
{
int id;
char name[20];
char branch[15];
char aos[20];
struct prof *left;
struct prof *right;
};
typedef struct prof NODE;

int countnodes(NODE *start)
{
NODE *p;
count=0;
p=start;
while(p!=NULL)
 {
     p=p->right;
     count++;
 }
     return count;
}

NODE* getnode(NODE *start)
{
NODE *newnode;
newnode=(NODE*)malloc(sizeof(NODE));
newnode->right=newnode->left=NULL;
printf("\nEnter ID, Name, Branch, AoS\n");
scanf("%d",&newnode->id);
scanf("%s",(newnode->name));
scanf("%s",(newnode->branch));
scanf("%s",(newnode->aos));
start=newnode;
return start;
}

NODE* display(NODE *start)
{
NODE *p;
if(start==NULL)
printf("\nNo Professor data\n");
else
{
p=start;
printf("\n----PROFESSOR DATA----\n");
printf("\nID\tNAME\tBRANCH\tAoS");
while(p!=NULL)
{
printf("\n%d\t%s\t%s\t%s", p->id, p->name, p->branch, p->aos);
p = p->right; 
}
printf("\nThe no. of nodes in list is: %d",countnodes(start));
}
return start;
}
NODE* insert_front(NODE *start)
{
NODE *p, *newnode;
if(countnodes(start)==MAX)
printf("\nList is Full");
else
{
if(start==NULL)
{
     newnode=getnode(start);
     start=newnode; 
}
else
{
 newnode=getnode(start);
 newnode->right=start;
 start->left=newnode;
 start=newnode;
}
}
return start;
}
NODE* delete_front(NODE *start)
{
NODE *p;
if(start==NULL)
printf("\nList is Empty");
else
{
p=start;
start=start->right;
free(p);
printf("\nFront node is deleted");
}
return start;
 }



void main()
{
int ch, i, n, status;
NODE *start;
start=NULL;
printf("\n----------Professor Database-----------");
do
{
printf("\n1.PUSH\t2.POP\t3.DISPLAY\t4.STATUS\t5.EXIT");
 printf("\nEnter your choice: ");

 scanf("%d",&ch);
switch(ch)
{
 case 1: printf("\nHow many professors data you want to create: ");
         scanf("%d", &n);
for(i=0;i<n;i++) 
 start=insert_front(start); 
break;
case 2: start=delete_front(start); 
 break;
 case 3: start=display(start); 
break;
case 4: status=countnodes(start); 
printf("\n Number of nodes in the list is %d",status);
break;
 case 5: exit(0); 
break;
}

}while(ch!=5);
}
