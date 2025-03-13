

#include <stdio.h>
#define INFINITY 999

int find(int,int selected[]);
int uni(int,int,int selected[]);

int main ()
{
	int v,i,j,n,node,weight,edge=0,row,column,p,q;
	
	printf("Enter the number of vertices: ");
	scanf("%d",&v);
	
	int graph[v][v],selected[v];
	
	for(i=0;i<v;i++)
	{
		selected[i]=0;
		
		for(j=0;j<v;j++)
		{
			graph[i][j]=INFINITY;
		}
	}
	
	for(i=0;i<v;i++)
	{
		printf("\nEnter the number of vertices connected to node no %d: ",i+1);
		scanf("%d",&n);
		
		for(j=0;j<n;j++)
		{
			scanf("%d %d",&node,&weight);
			graph[i][node-1]=weight;
		}
		
		printf("\n");
	}
	
	printf("\n  EDGE  :  WEIGHT \n");
	printf(" ------  ------- \n");
	
	while(edge<v-1)
	{
		int min=INFINITY;
		
		for(i=0;i<v;i++)
		{
			for(j=0;j<v;j++)
			{
				if(min>graph[i][j])
				{
					min=graph[i][j];
					row=p=i;
					column=q=j;
				}
			}
		}
		
		p=find(p,selected);
		q=find(q,selected);
		
		if(uni(p,q,selected))
		{
			printf(" %d - %d  :    %d \n",row+1,column+1,graph[row][column]);
			edge++;
		}
		
		graph[row][column]=graph[column][row]=INFINITY;
	}
	
	return 0;
}

int find(int x,int selected[])
{
	while(selected[x])
	x=selected[x];
	return x;
}

int uni(int x,int y,int selected[])
{
	if(x!=y)
	{
		selected[y]=x;
		return 1;
	}
	
	return 0;
}