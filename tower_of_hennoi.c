#include <stdio.h>
#include<math.h>
int count=0;
void tower(int n, int src,int temp,int dest)
{
	if (n == 0)
		return;
	tower(n-1, src,dest,temp);
	printf("\nMove disk %d from rod %c to rod %c", n, src, dest);
    count++;
	tower(n-1, temp, src, dest);
}

void main()
{
	int n;
	printf("Enter the number of disk\n");
    scanf("%d",&n);
    tower(n,'A','B','C');
    printf("\nTotal moves=%d",count);
}
