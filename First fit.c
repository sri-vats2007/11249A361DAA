#include<stdio.h>

void firstfit(int items[],int n,int capacity)
{
    int bin[n];
    int bincount=0;
    for (int i=0;i<n;i++)
        bin[i]= capacity;
    for(int i =0;i<n;i++)
    {
        int placed =0;
        for(int j=0;j<bincount;j++)
        {
            if(bin[j]>=items[i])
            {
                bin[j]-=items[i];
                printf("items %d placed in bin %d\n",items[i],j+1);
                placed =1;
                break;
            }
        }
        if(!placed)
        {
            bin[bincount]-=items[i];
            printf("items%d placed in bin %d\n",items[i],bincount+1);
            bincount++;
        }
    }
    printf("totalbin =%d\n",bincount);
}
void bestfit(int items[],int n,int capacity)
{
    
}
int main()
{
    int n,capacity;
    printf("enter the no of items:");
    scanf("%d",&n);
       int items[n];
       printf("enter item sizes");
       for(int i=0;i
       <n;i++)
       {
           printf("item %d:",i+1);
           scanf("%d",&items[i]);
       }
    printf("enter capacity:");
    scanf("%d",&capacity);
    firstfit(items,n,capacity);
    bestfit(items,n,capacity);
    return 0;
}
