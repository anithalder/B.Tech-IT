#include<stdio.h>
#include<stdlib.h>
//#include<windows.h>
#define maxx 10
#define mod 99999

void print_order(int i, int j, int K[maxx][maxx])
{
    if(i == j)
        printf(" M%d ",i);
    else
    {
        printf("(");
        print_order(i,K[i][j],K);
        print_order(K[i][j]+1,j,K);
        printf(")");
    }
}

/*void textcolor(int color_name)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color_name);
}*/

void main()
{
	int n,i,j,k,d,order[maxx],m[maxx][maxx],K[maxx][maxx];
	printf("\n\tEnter how many matrix you have: ");
	scanf("%d",&n);
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
		{
			m[i][j]=mod;
			K[i][j]=0;
		}

	for(i=0;i<=n;i++)
		m[i][i]=0;
		
	for(i=0;i<n;i++)
	{
		printf("\n\tEnter the M of order MxN matrix from M%d: ",i+1);
		scanf("%d",&order[i]);
	}
	printf("\n\tEnter the N of order MxN matrix from M%d: ",i);
	scanf("%d",&order[i]);
    
    // table making for matrix chain
    
    for(d=1;d<=n-1;d++)			
    {
    	for(i=1;i<=n-d;i++)
    	{
    		j=i+d;
    		int min=mod;
    		for(k=i;k<=j-1;k++)
    		{
    			int q=(m[i][k]+m[k+1][j]+(order[i-1]*order[k]*order[j]));
    			if(q<min)
    			{
    				min=q;
    				K[i][j]=k;
				}
			}
			m[i][j]=min;
		}
	}
	
	//The table of matrix chain
	
	printf("\n\n\tThe table of matrix chain:\n\n");
	printf("\n\n");
	//textcolor(2);
    printf("\t");
    for(i=1;i<=n;i++)
        printf("\t%d",i);;
    printf("\n\n");
   // textcolor(7);
    for(i = 1; i <= n; i++) 
    {
     //   textcolor(2);
        printf("\t%d",i);
       // textcolor(7);
        for(j = 1; j <= n; j++)
        {
            if (m[i][j] == mod)
                {
         //           textcolor(4);
                    printf("\tX");
           //         textcolor(7);
                }
            
			else if(m[i][j]!=mod && m[i][j]!=0)
            {
            	//textcolor(3);
            	printf("\t%d",m[i][j]);
            	//textcolor(7);
			}
			    
            else
            {

            	printf("\t%d",m[i][j]);
			}
			
        }
        printf("\n\n");
    }
    
    //The table of matrix mutiplication order
    
    printf("\n\n\tThe table of matrix mutiplication order:\n\n");
//	textcolor(2);
    printf("\t");
    for(i=1;i<=n;i++)
        printf("\t%d",i);
    printf("\n\n");
  //  textcolor(7);
    for(i = 1; i <= n; i++) 
    {
    //    textcolor(2);
        printf("\t%d",i);
      //  textcolor(7);
        for(j = 1; j <= n; j++)
        {
            if (m[i][j] == mod)
                {
        //            textcolor(4);
                    printf("\tX");
          //          textcolor(7);
                }
            
                 
            else if(m[i][j]!=mod && m[i][j]!=0)
            {
            //	textcolor(3);
            	printf("\t%d",K[i][j]);
            //	textcolor(7);
			}
            
             else
            {
            	printf("\t%d",m[i][j]);
			}
           
        }
        printf("\n\n");
    }
    
    printf("\n\tThe last order of matrix multiplication: ");
	print_order(1, n, K);
}
