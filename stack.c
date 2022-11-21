#include<stdio.h>
#include<stdlib.h>
#define MAX 4
int S[MAX],item;
int ch,top=-1,status=0;
void push(int S[],int item)
{
    if(top==(MAX-1))
        printf("\n\nStack is overflow");
    else
    {
        S[++top]=item;
        status++;
    }
}
int pop(int S[])
{
    int itemdel;
    if(top==-1)
        printf("\n\nStack is underflow");
    else{
        itemdel=S[top--];
        status--;
        printf("Popped element is %d",itemdel);
    }
    return itemdel;
}
void display(int S[])
{
    int i;
    if(top==-1)
        printf("Stack is empty\n");
    else{
        printf("Stack contents are\n");
        for(i=top;i>=0;i--)
            printf("\n-------------------------------\n|%d|",S[i]);
    }
}
void main()
{
    do
    {
        printf("\n\n---------------MAIN MENU------------------\n");
        printf("\n1.PUSH(Insert) in the stack");
        printf("\n2.Pop(Delete) from the stack");
        printf("\n3.DISPLAY the contents of stack");
        printf("\n4.Exit(End the execution)");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\nEnter the element to be pushed: ");
            scanf("%d",&item);
            push(S,item);
            display(S);
            break;

            case 2:item=pop(S);
            break;

            case 3:display(S);
            break;

            case 4:exit(0);

            default:printf("\nInvalid choice");
            break;
        }
    } while (ch!=5);   
}