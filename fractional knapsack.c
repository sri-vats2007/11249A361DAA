#include <stdio.h>
struct item 
{
    int pi;
    float wi;
    float ratio;
};

void sort(struct item items[],int n)
{
    struct item temp;
    for (int i=0;i<n-1;i++)
    {
        for (int j=0;j<n-i-1;j++)
        {
            if (items[j].ratio<items[j+1].ratio)
            {
                temp=items[j];
                items [j]=items[j+1];
                items [j+1]= temp;
            }
        }
    }
    printf("items sorted by Value/Weight ratio :\n");
    for (int i=0;i<n;i++)
    {
        printf("item %d: weight = %f, value = %d, ratio =%.2f\n", i+1, items[i].wi, items[i].pi, items[i].ratio);
    }
}

int main()
{
    int n,capacity;
    float total_pi=0;
    printf("Enter the no.of items :");
    scanf("%d",&n);
    struct item items[n];
    printf("Enter the weight and profit of the items");
    for (int i=0;i<n;i++)
    {
        scanf("%f",&items[i].wi);
        scanf("%d",&items[i].pi);
        items[i].ratio = items[i].pi/items[i].wi;
    }
    printf("Enter the Capacity of the Knapsack:");
    scanf("%d",&capacity);
    sort(items, n);
    for (int i=0;i<n;i++)
    {
        if (items[i].wi<capacity)
        {
            total_pi += items[i].pi;
            capacity -= items[i].wi;
        }
        else
        {
            total_pi += items[i].ratio * capacity;
            break;
        }
    }
    printf("maximum profit : %f",total_pi);
    return 0;
}
