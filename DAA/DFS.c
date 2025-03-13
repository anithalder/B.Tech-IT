#include <stdio.h>
#include <stdlib.h>
#define max 999

int top = -1;

void push(int stack[], int);
void pop(int stack[]);

void main() 
{
    int node, i, j, n;
    char ch;
    printf("\n\tEnter the number of nodes in the graph: ");
    scanf("%d", &n);
    int a[n][n], visited[n], stack[n];

    // initialize the adjacency matrix to all zeros
    for (i = 0; i < n; i++) 
        for (j = 0; j < n; j++)
            a[i][j] = 0;

    printf("\n\n\t\t! ! Please Enter 'n' For 'No' and 'y' For 'Yes' ! !\n\n");
    for(i = 0; i < n; i++) 
    {
        for(j = 0; j < n; j++) 
        {
            printf("\n\tHave any edge between Node %d and Node %d: ", i+1, j+1);
            scanf(" %c", &ch);
            if(ch == 'y') 
            {
                a[i][j] = 1;
            }
        }
    }

    printf("\nThe Adjacency matrix is:\n\n");
    for(i = 0; i < n; i++) 
    {
        for(j = 0; j < n; j++)
        {
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
    push(stack, node);
    visited[node] = 1;
    printf("%d ", node+1);

    while (top >= 0) 
    {
        int current_node = stack[top];
        int next_node = -1;
        for (i = 0; i < n; i++) 
        {
            if (a[current_node][i]==1 && visited[i]==0) 
            {
                next_node = i;
                break;
            }
        }
        if (next_node != -1) 
        {
            push(stack, next_node);
            visited[next_node] = 1;
            printf("%d ", next_node+1);
        } 
        else 
        {
            pop(stack);
        }
    }

    printf("\n");
}

void push(int stack[], int node) 
{
    if(top == max - 1) 
    {
        printf("\n\n\t\t! ! ! Stack Overflow ! ! !\n\n");
    } 
    else 
    {
        top++;
        stack[top] = node;
    }
}

void pop(int stack[]) 
{
    if(top == -1) 
    {
        printf("\n\n\t\t! ! ! Stack Underflow ! ! !\n\n");
    } 
    else 
    {
        top--;
    }
}

