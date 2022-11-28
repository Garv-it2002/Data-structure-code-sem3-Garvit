#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct node
{
int info;
struct node *link;
};
typedef struct node Node;
Node*head;
Node*insertFront(Node*head)
{
    int val;
    Node*newnode;
    newnode=(Node*)malloc(sizeof(Node));
    printf("\nEnter the value: ");
    scanf("%d",&val);
    newnode -> info=val;
    newnode -> link=head;
    head=newnode;
    return head;
}
Node*deleteFront(Node*head)
{
    Node*p;
    p=head;
    if(p=NULL)
        printf("\nList Empty\n");
    else
    {
        p=head;
        head=head->link;
        printf("\nPopped node value: %d\n",p->info);
        free(p);
    }return head;
}
int countnode(Node*head)
{
    Node*p;
    int c=0;
    p=head;
    while(p!=NULL)
    {
        p=p->link;
        c++;
    }
    return c;
}
void display(Node*head)
{
    Node*p;
    p=head;
    if(p==NULL)
        printf("\nList empty\n");
    else
    {
        printf("\nList:\n");
        while(p!=NULL)
        {
            printf("%d\n",p->info);
            p=p->link;
        }
    }
}
void main()
{
    int ch,count;
    head=NULL;
    do
    {
        printf("Menu:");
        printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:count=countnode(head);
                if(count==MAX)
                    printf("\nSTACK OVERFLOW\n");
                else
                    head=insertFront(head);
                break;
            case 2:head=deleteFront(head);
                break;
            case 3:display(head);
                    break;
            case 4:exit(0);
            default:printf("\nINVALID CHOICE\n");
        }
    }while(ch!=4);
}