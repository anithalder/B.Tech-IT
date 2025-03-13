#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define maxx 10

void DFS(int visited[],int,int);
int a[maxx][maxx];
void textcolor(int color_name)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color_name);
}

void main() 
{
    int node, i, j, n, v, ver;
    char ch;
    printf("\n\tEnter the number of nodes in the graph: ");
    scanf("%d", &n);
    int  visited[maxx];

    // initialize the adjacency matrix to all zeros
    for (i = 0; i < n; i++) 
        for (j = 0; j < n; j++)
            a[i][j] = 0;

    for (i = 0; i < n; i++)
    {
        printf("\n\tAny vertex connected to %d vertex: ",i+1);
        scanf(" %c",&ch);
        if (ch=='y')
        {
            printf("\n\tEnter how many vertex connected to %d vertex: ",i+1);
            scanf("%d",&v);
            for(j=0;j<v;j++)
            {
            printf("\n\t\t%d) Enter the destination vertex: ",j+1);
                scanf("%d",&ver);
                a[i][--ver]=1;
            }
        }
    }

    printf("\nThe Adjacency matrix is:\n\n");
    textcolor(2);
    printf("\t");
    for(i=0;i<n;i++)
        printf("\t%d",i+1);;
    printf("\n\n");
    textcolor(7);
    for(i = 0; i < n; i++) 
    {
        textcolor(2);
        printf("\t%d",i+1);
        textcolor(7);
        for(j = 0; j < n; j++)
        {
            if (a[i][j] == 1)
                {
                    textcolor(4);
                    printf("\t%d", a[i][j]);
                    textcolor(7);
                }
            else
            printf("\t%d", a[i][j]);
        }
        printf("\n\n");
    }

    for(i = 0; i < n; i++) 
    {
        visited[i] = 0;
    }

    printf("\n\tEnter the source node: ");
    scanf("%d", &node);
    node--;
    printf("\n\tThe traversal of the tree using DFS is: ");
    
    DFS(visited,n,node);
    
    printf("\n");
}


void DFS(int visited[],int n,int node)
{
    visited[node]=1;
	printf(" %d ",node+1);
     								// boolean array to mark visited vertices.
    for(int j = 0; j < n; j++) 		// for each vertex, do following.
    {
        if (visited[j]==0 && a[node][j]==1)
        {
            DFS(visited,n,j);
        }
    }
}