#include<stdio.h>
 
int main()    //main function starts 
{
    int i,j,k,n;            //defined integer variables for operations
    float A[20][20],c,x[10]; 
    printf("\nEnter the number of unknowns: "); 
    scanf("%d",&n);         //With scanf code gets input from user
    printf("\nEnter the elements of augmented matrix row-wise:\n");
    for(i=1; i<=n; i++)      //user gives row-wise elements of matrix.
    {
        for(j=1; j<=(n+1); j++)
        {
            printf(" A[%d][%d]:", i,j);
            scanf("%f",&A[i][j]);
        }
    }
 
    for(j=1; j<=n; j++)     //Now finding the elements of diagonal matrix
    {
        for(i=1; i<=n; i++)
        {
            if(i!=j)
            {
                c=A[i][j]/A[j][j];
                for(k=1; k<=n+1; k++)
                {
                    A[i][k]=A[i][k]-c*A[j][k];
                }
            }
        }
    }
    printf("\nThe solution is:\n"); //This line gives the text part of the solution
    for(i=1; i<=n; i++)
    {
        x[i]=A[i][n+1]/A[i][i];
        printf("\n x%d=%f\n",i,x[i]);  // solution
    }
    return(0);
}
 
