#include<stdio.h>
int main()
{
    int array[50],position,c,n,value,a;
    printf("Enter the number of elements in the array\n");
    scanf("%d",&n);
    printf("Enter %d elements\n",n);
    for(c=0;c<n;c++)
        scanf("%d",&array[c]);
    printf("Enter\n1.Insertion of element\n2.Deletion of element\n");
    scanf("%d",&a);
    switch(a)
    {
        case 1:{
            printf("Insertion of element in an array\n");
            printf("Enter location where you want to insert\n");
            scanf("%d",&position);
            printf("Please enter the value\n");
            scanf("%d",&value);
            for(c=n-1;c>=position-1;c--)
                array[c+1]=array[c];
            array[position-1]=value;
            printf("Resultant array is\n");
            for(c=0;c<=n;c++)
                printf("%d\n",array[c]);
        }
        break;
        case 2:{
            printf("Deletion of element in an array\n");
            printf("Enter location where you want to delete\n");
            scanf("%d",&position);
            if(position>=n+1)
                printf("Deletion not possible\n");
            else{
                for(c=position-1;c<n-1;c++)
                    array[c]=array[c+1];
                printf("Resultant array is\n");
                for(c=0;c<n-1;c++)
                    printf("%d\n",array[c]);
            }
        }
        break;
        return 0;
    }
}