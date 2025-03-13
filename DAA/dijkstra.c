#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#define INF 999

void textcolor(int color_name);

void main()
{
    int vertex,dest,i,j,k,v,min,ver,cos,n;
    printf("\n\tEnter the number of vertices: ");
    scanf("%d",&v);
    int cost[v][v],next[v],distance[v];
    char ch;
    char status[v];
    //printf("\n\tEnter the adjacency matrix:\n"); 
    
    // initialize the adjacency matrix with diagonal zeros and others infinity

    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            if(i==j)
                cost[i][j]=0;
            else
                cost[i][j]=INF;
        }    
    }

    for (i = 0; i < v; i++)
    {
        printf("\n\tEnter how many vertex connected to %d vertex: ",i+1);
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            printf("\n\t\t%d) Enter the destination vertex & cost: ",j+1);
            scanf("%d%d",&ver,&cos);
            cost[i][--ver]=cos;
        }
    }

    printf("\n\tThe Adjacency matrix is:\n\n");
    textcolor(2);
    printf("\t");
    for(i=0;i<v;i++)
        printf("\t%d",i+1);;
    printf("\n\n");
    textcolor(7);
    for(i = 0; i < v; i++) 
    {
        textcolor(2);
        printf("\t%d",i+1);
        textcolor(7);
        for(j = 0; j < v; j++)
        {
            if (cost[i][j] == INF)
                {
                    textcolor(4);
                    printf("\tINF");
                    textcolor(7);
                }
            else
                printf("\t%d",cost[i][j]);
        }
        printf("\n\n");
    }

    printf("\n\tEnter the source node: ");
    scanf("%d",&vertex);
    vertex--;
    printf("\n\tEnter the destination node: ");
    scanf("%d",&dest);
    dest--;

    //Initializing the mincost array

    for (i = 0; i < v; i++)
    {
        status[i] = '?';
        next[i] = vertex;
        distance[i] = cost[i][vertex];
    }

    //Dijkstra's Algorithm

    status[vertex] = '!'; // mark the source vertex as visited
    for (i = 0; i < v; i++)
    {
        if (distance[i] > distance[vertex] + cost[vertex][i])
        {
            distance[i] = distance[vertex] + cost[vertex][i]; // update the distance to vertex i
            next[i] = vertex; // update the next vertex in the shortest path to vertex i
            //status[i] = '!'; // mark vertex i as visited
        }
    }

    // check the distance to all other vertices through the minimum cost paths
    for (j = 1; j < v; j++)
    {
        // find the next unvisited vertex with the smallest distance
        min = INF;
        for (i = 0; i < v; i++)
        {
            if (status[i] == '?' && distance[i] < min)
            {
                min = distance[i];
                vertex = i;
            }
        }

        status[vertex] = '!'; // mark the selected vertex as visited

        // update the distance to all adjacent vertices of the selected vertex
        for (i = 0; i < v; i++)
        {
            if (cost[vertex][i] != INF && status[i] == '?')
            {
                if (distance[i] > distance[vertex] + cost[vertex][i])
                {
                    distance[i] = distance[vertex] + cost[vertex][i];
                    next[i] = vertex;
                    //status[i] = '!';
                }
            }
        }
    }
    printf("\n\tThe distances are:");
    for (i = 0; i < v; i++)
    {
        printf(" %d ",distance[i]);
    }
    /*printf("\n\tThe shortest path is:");
    for (i = 0; i < v; i++)
    {
        printf(" %d -> ",next[i]+1);
    }
    printf("%d\n\n",next[i]+1);*/

    // find the shortest path from the source to the destination
    if(distance[dest] == INF) // no path exists
    printf("\n\tNo path exists between %d and %d\n", vertex+1, dest+1);
    else 
    {
        printf("\n\tThe shortest path from %d to %d is: %d", vertex+1, dest+1, vertex+1);
        i = dest;
        while (i != vertex) 
        {
            printf(" <- %d", next[i]+1);
            i = next[i];
        }
        printf("\n\tThe distance of the shortest path is: %d\n", distance[dest]);
    }

}

void textcolor(int color_name)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color_name);
}