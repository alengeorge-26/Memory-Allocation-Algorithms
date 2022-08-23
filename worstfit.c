#include<stdio.h>

struct memory
{
    int size;
    int status;
    int pro;
    int rem;
}M[10];

int m;

void worstfit(int [],int);

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

    worstfit(P,n);

    printf("\n\nMemory Allocation\n");
    printf("------------------\n");
    printf("\nBlock No    Allocated Memory\n");
    for(i=0;i<m;i++)
    {
        printf("\n%d          %d\n",M[i].size,M[i].pro);
    }
}

void worstfit(int P[],int n)
{
    int i,j,k,max;

    for(i=0;i<n;i++)
    {
        max=0;
        for(j=0;j<m;j++)
        {
            if(M[j].size>=M[max].size && M[j].status==0)
            {
                max=j;
            }

            if(M[max].status==1)
                max++;
        }
        j=max;
        if(M[j].size<P[i])
            continue;
        M[j].status=1;
        M[j].pro=P[i];
        M[j].rem=M[j].size-P[i];
    }
}
