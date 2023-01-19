#include<stdio.h>
#include<stdlib.h>

struct node
{
    int val;
    struct node*link;
};
typedef struct node Node;
Node*head;
Node*add(Node*head,int val)
{
    Node*temp;
    Node*prev;
    Node*cun;
    Node*sample;
    sample=head;
    temp=(Node*)malloc(sizeof(Node));
    temp->val=val;
    temp->link=NULL;
    if(head!=NULL){
    while (sample->link!=NULL)
    {
        sample=sample->link;
    }
    }
    //printf("%d",sample->val);
    if(head==NULL)
        return temp;
    else if(head->val>=temp->val){
        temp->link=head;
        return temp;
    }
    else if(sample->val<=temp->val){
        sample->link=temp;
        return head;
    }
    else{
        prev=NULL;
        cun=head;
        while(cun->val<=temp->val)
        {
            prev=cun;
            cun=cun->link;
        }
        prev->link=temp;
        temp->link=cun;
        return head;
    }
}

void display(Node*head)
{
    Node*temp;
    temp=head;
    printf("\n--------------------------------\n");
    if(head==NULL)
        printf("List empty\n");
    else{
        temp=head;
        while(temp!=NULL){
            printf("%d\n",temp->val);
            temp=temp->link;
        }
    }
    printf("\n--------------------------------\n");
}   
void main(){
    int ch,n;
    
    do{
    printf("1.Insert\n2.Display\n3.Exit\n");
    printf("Enter the option\n");
    scanf("%d",&ch);
    switch(ch){
        case 1:printf("Enter value\n");
                scanf("%d",&n);
                head=add(head,n);
                break;
        case 2:display(head);
                break;
        case 3:exit(0);
                break;
    }
    }while(ch!=4);
}
