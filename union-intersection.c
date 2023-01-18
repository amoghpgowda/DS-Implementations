#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};

typedef struct node *NODE;

int search(int key, NODE first)
{
    NODE cur;
    if(first==NULL)
        return 0;
    cur=first;
    while(cur!=NULL)
    {
        if(key==cur->info)
            return 1;
        cur=cur->link;
    }
    return 0;
}

void display(NODE first)
{
    NODE cur;
    if(first==NULL)
    {
        printf("List is empty\n");
        return;
    }
    cur=first;
    while(cur!=NULL)
    {
        printf("%d ",cur->info);
        cur=cur->link;
    }
    printf("\n");
}

NODE getnode()
{
    NODE x;
    x=(NODE) malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("Out of memory\n");
        exit(0);
    }
    return x;
}

NODE insert_rear(int item,NODE first)
{
    NODE temp;
    NODE cur;
    temp=getnode();
    temp->info=item;
    temp->link=NULL;
    if(first==NULL)
        return temp;
    cur=first;
    while(cur->link!=NULL)
    {
        cur=cur->link;
    }
    cur->link=temp;
    return first;
}

NODE union_of_list(NODE first, NODE second)
{
    NODE a, third;
    int flag;
    a=first;
    third=NULL;
    while(a!=NULL)
    {
        third=insert_rear(a->info,third);
        a=a->link;
    }
    a=second;
    while(a!=NULL)
    {
        flag=search(a->info,third);
        if(flag==0)
            third=insert_rear(a->info,third);
        a=a->link;
    }
    return third;
}

NODE intersection_of_list(NODE first, NODE second)
{
    NODE a,b,third;
    int flag;
    a=first;
    b=second;
    third=NULL;
    while(a!=NULL)
    {
        flag=search(a->info,b);
        if(flag==1)
            third=insert_rear(a->info,third);
        a=a->link;
    }
    return third;
}

void main()
{
    NODE first,second,third;
    int choice,item,i,n;
    printf("\n---------- MENU ----------\n");
    printf("1:Create first list\n");
    printf("2:Create second list\n");
    printf("3:Union of two lists\n");
    printf("4:Intersection of two lists\n");
    printf("5:Exit\n");
    printf("--------------------------\n");
    for(;;)
    {
        printf("\nEnter the choice: ");
        scanf("%d",& choice);
        switch(choice)
        {
            case 1:
                printf("\nenter the no of nodes in list one: ");
                scanf("%d",&n);
                first=NULL;
                printf("enter the items: ");
                for(i=1;i<=n;i++)
                {
                    scanf("%d",&item);
                    first=insert_rear(item,first);
                }
                break;
            case 2:
                printf("\nenter the number of nodes in list two: ");
                scanf("%d",&n);
                second=NULL;
                printf("enter the items: ");
                for(i=1;i<=n;i++)
                {
                    scanf("%d",&item);
                    second=insert_rear(item,second);
                }
                break;
            case 3:
                printf("\nFirst list is: ");
                display(first);
                printf("\nSecond list is: ");
                display(second);
                third=union_of_list(first,second);
                printf("\nunion of two lists: ");
                display(third);
                break;
            case 4:
                printf("\nFirst list is: ");
                display(first);
                printf("\nSecond list is: ");
                display(second);
                third=intersection_of_list(first,second);
                printf("\nintersection of two lists: ");
                display(third);
                break;
            case 5: exit(0);
            default:
                printf("\nInvalid choice");
        }
    }
}
