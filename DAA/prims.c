#include<stdio.h>
#include<stdlib.h>
#define max 999

void main()
{
    int vertex, i, j, v,u,result=0;
    char ch;
    printf("\n\tEnter the number of vertex in the graph: ");
    scanf("%d", &v);
    int cost[v][v],visited[v],key[v];

    // initialize the adjacency matrix to all zeros
    for (i = 0; i < v; i++) 
        for (j = 0; j < v; j++)
            cost[i][j] = 0;

    printf("\n\n\t\t! ! Please Enter 'n' For 'No' and 'y' For 'Yes' ! !\n\n");
    for(i = 0; i < v; i++) 
    {
        for(j = 0; j < v; j++) 
        {
            printf("\n\tHave any edge between Vertex %d and Vertex %d: ", i+1, j+1);
            scanf(" %c", &ch);
            if(ch == 'y') 
            {
                printf("\n\t\tEnter the cost of edge: ");
                scanf("%d",&cost[i][j]);
            }
        }
    }

    printf("\n\tThe Adjacency matrix is:\n\n");
    for(i = 0; i < v; i++) 
    {
        for(j = 0; j < v; j++)
        {
            printf("\t%d",cost[i][j]);
        }
        printf("\n\n");
    }

    for(i = 0; i < v; i++) 
    {
        visited[i] = 0;
        key[i] = max;
    }

    printf("\n\tEnter the source vertex: ");
    scanf("%d", &vertex);
    printf("\n\tThe minumum spanning tree path is: ");
    vertex--;
    key[vertex]=0;
    for (int k = 0; k < v; k++)
    {
        int u=-1;
        for (i = 0; i < v; i++)
        {
            if(visited[i]==0 && (u==-1 || key[i]<key[u]))
            {
                u=i;
            }
        }
        printf(" %d ",u+1);
        visited[u]=1;
        result += key[u];
        for (int j = 0; j < v; j++)
        {
            if(cost[u][j]!=0 && visited[j]==0)
            {
                if(key[j]>cost[u][j])
                    key[j]=cost[u][j];
            }
        }
    }
    printf("\n\tMinimum cost = %d\n\n",result);
    printf("\n");
}