#include <stdio.h>
#include <windows.h>

#define maxx 10

int mColor(int);
int nextvalue(int);
void textcolor(int color_name);

int v,m;
int x[maxx],adj[maxx][maxx];

void textcolor(int color_name) 
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_name);
}

int main() 
{
    int dest, i, n,j;
    printf("\n\tEnter the number of vertices: ");
    scanf("%d", &v);
    //int adj[v][v], x[v];

    for (i = 0; i < v; i++) 
    {
        for (j = 0; j < v; j++) 
        {
            adj[i][j] = 0;
        }
    }

    printf("\n\n\t\t! ! Please Enter Only Destination vertex number ! !\n\n");
    for (i = 0; i < v; i++) 
    {
        printf("\n\tEnter how many vertices are connected to vertex %d: ", i + 1);
        scanf("%d", &n);
        for (j = 0; j < n; j++) 
        {
            printf("\n\t\t%d) Enter the destination vertex: ", j + 1);
            scanf("%d", &dest);
            adj[i][--dest] = 1;
        }
    }

    printf("\n\tThe Adjacency matrix is:\n\n");
    textcolor(2);
    printf("\t");
    for (i = 0; i < v; i++) 
    {
        printf("\t%d", i + 1);
    }
    printf("\n\n");
    textcolor(7);
    for (i = 0; i < v; i++) 
    {
        textcolor(2);
        printf("\t%d", i + 1);
        textcolor(7);
        for (j = 0; j < v; j++) 
        {
            if (adj[i][j] == 1) 
            {
                textcolor(4);
                printf("\t%d", adj[i][j]);
                textcolor(7);
            } 
            else 
            {
                printf("\t%d", adj[i][j]);
            }
        }
        printf("\n\n");
    }

    printf("\n\n\tEnter how many color values you want: ");
    scanf("%d", &m);

    if (mColor(0)==1) 
    {
        printf("\n\n\t* * * Coloring is possible with %d colors. * * *\n", m);
        printf("\n\t\tThe order of coloring is:\n\n");
        for (i = 0; i < v; i++) 
        {
            printf("\t\tVertex %d : Color %d\n",i,x[i]);
        }
    } 
    else 
    {
        printf("\n\n\t ! ! ! Coloring is not possible with %d colors. ! ! !\n", m);
    }

    return 0;
}

int nextvalue(int k) 
{
    int j;
    while (1) {
        x[k] = (x[k] + 1) % (m + 1); // Next highest color

        if (x[k] == 0) {
            return 0;
        }

        for (j = 0; j < v; j++) {
            if (x[k] == x[j] && adj[k][j] != 0) {
                break; // adjacency vertex has the same color
            }
        }

        if (j == v) {
            return 1;
        }
    }
}

int mColor(int k) 
{
    int i;
    while (1) {
        nextvalue(k); // assigning a legal color

        if (x[k] == 0) // No color is possible
        {
            return 0;
        }

        if (k == v)     // All colors are used, so color found.  Return 'true' to end recursion.
        {
            return 1;
        }

        if (mColor(k + 1)) 
        {
            return 1;
        }
        
    }
}