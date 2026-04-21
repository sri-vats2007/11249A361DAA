#include<stdio.h>

void firstfit(int items[],int n,int c)
{
    int bin[n];
    int bincount=0;
    for (int i=0;i<n;i++)
        bin[i]=0;
    for (int i=0;i<=n;i++)
    {
        int placed = 0;
        for (int j=0;j<bincount;j++)
        {
            if (bin[j]>=items[i])
            {
                bin[j] -= items[i];
                printf("Item %d Placed in Bin %d\n",items[n],j+1);
                placed = 1;
                break;
            }
        }
        if (!placed)
        {
            bin[bincount]=c - items[i];
            printf("Item %d placed in Bin %d\n",items[i],bincount+1);
            bincount++;
        }
    }
    printf("Total bins used = %d \n",bincount);
}

void bestfit(int items[],int n, int c)
{
    int bin[n];
    int bincount=0;
    for (int i=0;i<n;i++)
        bin[i]=c;
    for (int i=0;i<n;i++)
    {
        int bestindex=-1;
        int minspace=c+1;
        for (int j=0;j<bincount;j++)
        {
            if(bin[j]>=items[i]&&bin[j] - items[i]<minspace)
            {
                bestindex = j;
                minspace = bin[j]-items[i];
            }
        }
        if (bestindex != -1)
        {
            bin[bestindex]-=items[i];
            printf("Items %d placed in Bin %d\n",items[i],bestindex+1);
        }
        else
        {
            bin[bincount] = c - items[i];
            printf("Item %d placed in Bin %d\n",items[i],bincount+1);
            bincount++;
        }
    }
    printf("Total bins used = %d\n",bincount);
}

int main()
{
    int n,c;
    printf("Enter the no of items:");
    scanf("%d",&n);
    int items[n];
    printf("Enter the Values of the items\n");
    for(int i=1;i<=n;i++)
    {
        printf("Enter the item %d value : ",i);
        scanf("%d",&items[i]);
    }
    printf("Enter the Bin Capacity");
    scanf("%d",&c);
    printf("\nFirst Fit Algorithm:\n");
    firstfit(items, n, c);
    printf("\nBest Fit Algorithm:\n");
    bestfit(items, n, c);
    return 0;
}
