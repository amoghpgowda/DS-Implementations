#include<stdio.h>

int a[10][10], n, sb[10];

void read_adjMatrix()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void bfs(int u)
{
    int f,r,q[10],v,i;
    for(i=0;i<n;i++)
        sb[i]=0;
    printf("\nBREADTH FIRST SEARCH nodes visited from %d: ",u);
    f=0, r=-1;
    q[++r]=u;
    sb[u]=1;
    printf("%d ",u);
    while(f<=r)
    {
        u=q[f++];
        for(v=0; v<n; v++)
        {
            if(a[u][v]==1)
            {
                if(sb[v]==0)
                {
                    printf("%d ",v);
                    sb[v]=1;
                    q[++r]=v;
                }
            }
        }
    }
    printf("\n");
}

void main()
{
    int i,src;

    printf("Enter the number of nodes in the graph: ");
    scanf("%d",&n);

    printf("Enter the adjacency matrix:\n");
    read_adjMatrix();

    printf("Enter the source: ");
    scanf("%d",&src);

    bfs(src);

    printf("\nBREADTH FIRST SEARCH nodes visited from %d: ",src);
    for(i=0;i<n;i++)
        sb[i]=0;
    bfs(src);
    printf("\n");
}
