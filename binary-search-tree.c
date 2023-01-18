#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
};

typedef struct node *NODE;

NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("Insufficient memory");
        exit(0);
    }
    return x;
}

void preorder(NODE root)
{
    if(root==NULL) return;
    printf("%d\t",root->info);
    preorder(root->llink);
    preorder(root->rlink);
}

void postorder(NODE root)
{
    if(root==NULL) return;
    postorder(root->llink);
    postorder(root->rlink);
    printf("%d\t",root->info);
}

void inorder(NODE root)
{
    if(root==NULL) return;
    inorder(root->llink);
    printf("%d\t",root->info);
    inorder(root->rlink);
}

NODE insert(int item,NODE root)
{
    NODE temp,cur,prev;
    temp=getnode();

    temp->info=item;
    temp->llink=NULL;
    temp->rlink=NULL;

    if(root==NULL)
    return temp;

    prev=NULL;
    cur=root;

    while(cur!=NULL)
    {
        prev=cur;
        if(item<cur->info)
            cur=cur->llink;
        else
            cur=cur->rlink;
    }

    if(item<prev->info)
        prev->llink=temp;
    else
        prev->rlink=temp;

    return root;
}

NODE search(int item, NODE root)
{
    NODE cur;

    if(root==NULL) return NULL;

    cur=root;

    while(cur!=NULL)
    {
        if(item==cur->info)
            return cur;
        if(item<cur->info)
            cur=cur->llink;
        else
            cur=cur->rlink;
    }

    return NULL;
}

void main() {
    int item, ch, n, i;
    NODE root, cur;

    root = NULL;
    printf("---------- MENU ----------\n");
    printf("\t1: INSERT\n\t2: PREORDER\n\t3: INORDER\n\t4: POSTORDER\n\t5: SEARCH\n\t6: EXIT\n");
    printf("--------------------------\n");

    for (;;) {
        printf("\nENTER OPERATION TO PERFORM: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the number of items: ");
                scanf("%d", &n);

                printf("Enter the items: ");
                for (i = 0; i < n; i++) {
                    scanf("%d", &item);
                    root = insert(item, root);
                }
                break;

            case 2:
                if (root == NULL) {
                    printf("Tree is empty\n");
                    break;
                }

                printf("Preorder traversal is: ");
                preorder(root);

                printf("\n");
                break;

            case 3:
                if (root == NULL) {
                    printf("Tree is empty\n");
                    break;
                }
                printf("Inorder traversal is: ");
                inorder(root);

                printf("\n");
                break;

            case 4:
                if (root == NULL) {
                    printf("Tree is empty\n");
                    break;
                }
                printf("Postorder traversal is: ");
                postorder(root);

                printf("\n");
                break;

            case 5:
                printf("Enter the item to be searched: ");
                scanf("%d", &item);
                cur = search(item, root);

                if (cur == NULL)
                    printf("Item not found\n");
                else
                    printf("Item found\n");
                break;

            case 6:
                exit(0);
            default:
                printf("Enter valid choice\n");
        }
    }
}
