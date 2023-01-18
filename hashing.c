#include<stdio.h>
#include<stdlib.h>

int h_size = 10;

int H(int k)
{
    return k % h_size;
}

void insert(int item,int a[])
{
    int i,index,h_val;
    h_val = H(item);
    for (i = 0;i < h_size ; i++)
    {
        index = (h_val + i) % h_size;
        if(a[index]==0)break;
    }
    if(a[index]==0)
        a[index]=item;
    else
        printf("Hash table full\n");
}

void display(int a[])
{
    int i;
    printf("Elements of hash table are: ");
    for (i = 0;i < h_size ; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void main()
{
    int i,ch,item,a[10]={0};
    for(;;)
    {
        printf("---------- MENU ----------\n");
        printf("\t1: INSERT\n\t2: DISPLAY\n\t3: EXIT\n");
        printf("--------------------------\n");
        printf("ENTER OPERATION TO PERFORM: ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
                printf("Enter item to be inserted: ");
                for (int j = 0; j < 10; j++) {
                    scanf("%d",&item);
                    insert(item,a);
                }
                break;

            case 2:
                display(a);
                break;

            case 3:
                exit(0);

            default:
                printf("\ninvalid input");
        }
    }
}
