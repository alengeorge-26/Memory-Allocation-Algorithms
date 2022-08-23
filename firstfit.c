#include<stdio.h>

struct memory
{
    int size;
    int status;
    int pro;
    int rem;
}M[10];

int m;

void firstfit(int [],int);
int main()
{
    int n,i,j,k,P[10];

    printf("\nEnter the size of memory blocks : ");
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        printf("\nEnter the %d memory block size : ",i+1);
        scanf("%d",&M[i].size);
    }

    printf("\nEnter the size of process blocks : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter the %d process block size : ",i+1);
        scanf("%d",&P[i]);
    }

    firstfit(P,n);

    printf("\n\nMemory Allocation\n");
    printf("------------------\n");
    printf("\nBlock No    Allocated Memory\n");
    for(i=0;i<m;i++)
    {
        printf("\n%d          %d\n",M[i].size,M[i].pro);
    }
}

void firstfit(int P[],int n)
{
    int i,j,k;

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(M[j].size>= P[i] && M[j].status==0)
            {
                M[j].status=1;
                M[j].pro=P[i];
                M[j].rem=M[j].size-P[i];
                break;
            }
        }
    }
}
