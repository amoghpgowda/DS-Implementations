#include<stdio.h>
#include<stdlib.h>

struct rbtNode{
    int key;
    char color;
    struct rbtNode *left, *right,*parent;
};

typedef struct rbtNode* NODE;
NODE root = NULL;

void leftRotate(NODE x)
{
    NODE y;
    y = x->right;
    x->right = y->left;
    if( y->left != NULL)
    {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if( x->parent == NULL){
        root = y;
    }
    else if((x->parent->left!=NULL) && (x->key == x->parent->left->key))
    {
        x->parent->left = y;
    }
    else x->parent->right = y;
    y->left = x; x->parent = y;
}

void rightRotate(NODE y)
{
    NODE x;
    x = y->left;
    y->left = x->right;
    if ( x->right != NULL)
    {
        x->right->parent = y;
    }
    x->parent = y->parent;
    if( y->parent == NULL)
    {
        root = x;
    }
    else if((y->parent->left!=NULL)&& (y->key == y->parent->left->key))
    {
        y->parent->left = x;
    }
    else
        y->parent->right = x;
    x->right = y; y->parent = x;

}

void colour_insert(NODE z)
{
    NODE y=NULL;
    while ((z->parent != NULL) && (z->parent->color == 'r'))
    {
        if ((z->parent->parent->left != NULL) && (z->parent->key == z->parent->parent->left->key))
        {
            if(z->parent->parent->right!=NULL)
                y = z->parent->parent->right;
            if ((y!=NULL) && (y->color == 'r'))
            {
                z->parent->color = 'b';
                y->color = 'b';
                z->parent->parent->color = 'r';
                if(z->parent->parent!=NULL)
                    z = z->parent->parent;
            }
            else
            {
                if ((z->parent->right != NULL) && (z->key == z->parent->right->key))
                {
                    z = z->parent;
                    leftRotate(z);
                }
                z->parent->color = 'b';
                z->parent->parent->color = 'r';
                rightRotate(z->parent->parent);
            }
        }
        else
        {
            if(z->parent->parent->left!=NULL)
                y = z->parent->parent->left;
            if ((y!=NULL) && (y->color == 'r'))
            {
                z->parent->color = 'b';
                y->color = 'b';
                z->parent->parent->color = 'r';
                if(z->parent->parent!=NULL)
                    z = z->parent->parent;
            }
            else
            {
                if ((z->parent->left != NULL) && (z->key == z->parent->left->key))
                {
                    z = z->parent;
                    rightRotate(z);
                }
                z->parent->color = 'b';
                z->parent->parent->color = 'r';
                leftRotate(z->parent->parent);
            }
        }
    }
    root->color = 'b';
}

void inorderTree(NODE rt)
{
    NODE temp = rt;
    if (temp != NULL)
    {
        inorderTree(temp->left);
        printf(" %d(%c) ",temp->key,temp->color);
        inorderTree(temp->right);
    }
}

void postorderTree(NODE rt)
{
    NODE temp = rt;
    if (temp != NULL)
    {
        postorderTree(temp->left);
        postorderTree(temp->right);
        printf(" %d(%c) ",temp->key,temp->color);
    }
}

void printTree(NODE rt, int space)
{
    if (rt == NULL)
    {
        return;
    }
    else
    {
        space += 8;
        printTree(rt->right, space);
        printf("\n");
        for (int i = 8; i < space; i++)
            printf(" ");
        printf("%d(%c)", rt->key,rt->color);
        printTree(rt->left, space);
    }
}

void traversal(NODE  rt)
{
    if (rt != NULL)
    {
        printf("root is %d- %c",rt->key,rt->color);
        printf("\nInorder tree traversal\n");
        inorderTree(rt);
        printf("\npostorder tree traversal\n");
        postorderTree(rt);
        printTree(rt,0);
    }
}

int search(int val)
{
    NODE temp = root;
    int diff;
    while (temp != NULL)
    {
        diff = val - temp->key;
        if (diff > 0)
        {
            temp = temp->right;
        }
        else if (diff < 0)
        {
            temp = temp->left;
        }
        else
        {
            printf("Search Element Found!!\n");
            return 1;
        }
    }
    return 0;
}

void insert(int val)
{
    NODE x, y;
    NODE z = (NODE)malloc(sizeof(struct rbtNode));
    z->key = val;
    z->left = NULL;
    z->right = NULL;
    z->color = 'r';
    x=root;
    if(search(val)==1)
    {
        printf("\nEntered element already exists in the tree\n");
        return;
    }
    if ( root == NULL )
    {
        root = z;
        root->color = 'b';
        return;
    }
    while ( x != NULL)
    {
        y = x;
        if ( z->key < x->key)
        {
            x = x->left;
        }
        else
            x = x->right;
    }
    z->parent = y;
    if ( y == NULL)
    {
        root = z;
    }
    else if( z->key < y->key )
    {
        y->left = z;
    }
    else
    {
        y->right = z;
    }
    colour_insert(z);
}


int main(){
    int choice,val,n,fl=0;
    while(1)
    {
        printf("\nRed Black Tree Menu\n1:Insert\n2:Search\n3:Traversal \n4:Exit\n\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter no of elements to add: ");
                scanf("%d",&n);
                printf("Enter the elements: ");
                for (int i = 0; i < n; i++)
                {
                    scanf("%d",&val);
                    insert(val);
                }
                break;
            case 2:
                printf("Enter search element: ");
                scanf("%d",&val);
                search(val);
                break;
            case 3:
                traversal(root);
                break;
            case 4:
                fl=1;
                break;
            default:
                printf("\nInvalid Choice\n");
        }
        if(fl==1){
            break;}
    }
    return 0;
}
