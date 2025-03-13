#include<stdio.h>
#include<stdlib.h>
#define max 10

int front=-1,rear=-1;
void enqueue(int queue[],int);
int dequeue(int queue[]);
void main()
{
    int node,i,temp,j,n;
    char ch;
    int a[max][max],visited[max],queue[max];
    printf("\n\tEnter the number of nodes in the graph: ");
    scanf("%d",&n);
    a[n][n],visited[n],queue[n];
    
    // initialize the adjacency matrix to all zeros
    
    for (i = 0; i <= n; i++) 
        for (j = 0; j <= n; j++)
            a[i][j] = 0;
	   
    printf("\n\n\t\t! ! Please Enter 'n' For 'No' and 'y' For 'Yes' ! !\n\n");
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
    	{
    		printf("\n\tHave any edge between Node %d and Node %d : ",i+1,j+1);
    		scanf(" %c",&ch);
    		if(ch == 'y')
    			a[i][j]=1;
		}
	}

    printf("\nThe Adjacency matrix is:\n\n");
    for(i=0;i<n;i++)
		{
		    for (j=0;j<n;j++)
			    {
			        printf("\t%d",a[i][j]);
			    }
        	printf("\n\n");
        }

	for (i = 0; i < n; i++)
	    visited[i] = 0;

    printf("\n\tEnter the source node: ");
    scanf("%d",&node);
    node--;
    printf("\n\tThe traversal of the tree using BFS is: %d ",node+1);
    visited[node]=1;
    enqueue(queue,node);

    while(front!=rear)
    {
        temp=dequeue(queue);
        for(i=0;i<n;i++)
        {
            if(a[temp][i]==1 && visited[i]==0)
            {
                printf(" %d ",i+1);
                visited[i]=1;
                enqueue(queue,i);
            }
        }
    }
    printf("\n");
}

void enqueue(int queue[],int node)
{
    if(rear==max-1)
        printf("\n\n\t\t! ! ! Queue is full ! ! !\n");
    else
    {
        if(front==-1 && rear==-1)
        {
            front=0;
            rear=0;
        }
        queue[rear]=node;
        rear++;
    }
}

int dequeue(int queue[])
{
    int item;
    if (front==-1 && rear==-1)
    {
        printf("\n\n\t\t! ! ! Queue is empty ! ! !\n");
    }
    else
    {
        item=queue[front];
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else    
            front++;
    }
    return item;
}