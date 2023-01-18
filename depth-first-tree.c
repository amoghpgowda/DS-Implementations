#include<stdio.h>

int a[10][10], n, sd[10];

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

void dfs(int u)
{
    int v;
    sd[u]=1;
    printf("%d ",u);
    for(v=0; v<n; v++)
    {
        if(a[u][v]==1 && sd[v]==0)
            dfs(v);
    }
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

    dfs(src);

    printf("\nDEPTH FIRST SEARCH nodes visited from %d: ",src);
    for(i=0;i<n;i++)
        sd[i]=0;
    dfs(src);
    printf("\n");
}
