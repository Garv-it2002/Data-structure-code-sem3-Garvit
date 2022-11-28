#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node*link;
};
typedef struct node Node;
int flag=0,pos=0;
Node *insert_rear(Node*head)
{
    int val;
    Node *newnode;
    Node *p;
    newnode=(Node*)malloc(sizeof(Node));
    printf("Enter the value: ");
    scanf("%d",&val);
    newnode->info=val;
    newnode->link=NULL;
    if(head==NULL)
        head=newnode;
    else
    {
        p=head;
        while(p->link!=NULL)
        p=p->link;
        p->link=newnode;
    }
    return head;
}
void display(Node *head)
{
    Node *p;
    p=head;
    if(head==NULL)
        printf("List empty\n");
    else
    {
        printf("The elements are\n");
        while(p!=NULL)
        {
            printf("%d\n",p->info);
            p=p->link;
        }
    }
}
int linear_search(int key,Node *head)
{
    Node *p;
    p=head;
    while(p!=NULL)
    {
        pos++;
        if(key==p->info)
        {
            flag=1;
            break;
        }
        p=p->link;
    }
    return pos;
}
void main()
{
    int ch,count,i,n,key;
    Node *head;
    head=NULL;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        head=insert_rear(head);
    }
    display(head);
    printf("Enter the key element\n");
    scanf("%d",&key);
    pos=linear_search(key,head);
    if(flag!=0)
        printf("The element %d is found in %d\n",key,pos);
    else
    printf("Element not found\n");
}