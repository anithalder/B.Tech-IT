#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#define INF 999

void textcolor(int color_name);

void main()
{
    int i,j,k,n,v;
    char ch;
    printf("\n\tEnter the number of vertices: ");
    scanf("%d",&v);
    int dist[v][v];

    // initialize the adjacency matrix with diagonal zeros and others infinity

    /*for (i = 0; i < v; i++) 
        for (j = 0; j < v; j++)
            {
                if (i == j)
                    dist[i][j] = 0;
                else
                    dist[i][j] = INF;
            }*/

    printf("\n\n\t\t! ! Please Enter 'n' For 'No' and 'y' For 'Yes' ! !\n\n");
    for(i = 0; i < v; i++) 
    {
        for(j = 0; j < v; j++) 
        {
            if (i == j)
                    dist[i][j] = 0;
            else
                dist[i][j] = INF;

            if (i!=j)
            {
                printf("\n\tHave any edge between Vertex %d and Vertex %d:  ", i+1, j+1);
                scanf(" %c", &ch);
                if(ch == 'y') 
                {
                    printf("\n\t\tEnter the weight of edge: ");
                    scanf("%d",&dist[i][j]);
                }
            }
        }
    }

    printf("\n\tThe Adjacency matrix is:\n\n");
    textcolor(3);
    printf("\t");
    for(i=0;i<v;i++)
        printf("\t%d",i+1);;
    printf("\n\n");
    textcolor(7);
    for(i = 0; i < v; i++) 
    {
        textcolor(3);
        printf("\t%d",i+1);
        textcolor(7);
        for(j = 0; j < v; j++)
        {
            if (dist[i][j] == INF)
                printf("\t%c",1);
            else
                printf("\t%d",dist[i][j]);
        }
        printf("\n\n");
    }

    // Floyd's algorithm apply

    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
        {
            for (k = 0; k < v; k++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = (dist[i][k] + dist[k][j]);
            }
        }
    }

    printf("\n\tThe shortest path matrix corresponding to the graph's adjacency matrix is:\n\n");
    textcolor(3);
    printf("\t");
    for(i=0;i<v;i++)
        printf("\t%d",i+1);;
    printf("\n\n");
    textcolor(7);
    for(i = 0; i < v; i++) 
    {
        textcolor(3);
        printf("\t%d",i+1);
        textcolor(7);
        for(j = 0; j < v; j++)
        {
            if (dist[i][j] == INF)
                printf("\t%c",1);
            else
                printf("\t%d",dist[i][j]);
        }
        printf("\n\n");
    }
}

void textcolor(int color_name)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color_name);
}