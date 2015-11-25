#include<stdio.h>
int main()
{
    int t,a,m,n,k,i,j;
    while((scanf("%d",&t))!=EOF)
    {
    for(a=0;a<t;a++)
     {
        scanf("%d%d%d",&m,&n,&k);
        int food[m][n];
        int ar=0;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++){scanf("%d",&food[i][j]);}
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
                {
                    if(food[i][j]==1)
                    {
                        ar++;
                        if(i!=m-1&&food[i+1][j]==0){food[i+1][j]=2;ar++;}
                        if(i!=0&&food[i-1][j]==0){food[i-1][j]=2;ar++;}
                        if(j!=n-1&&food[i][j+1]==0){food[i][j+1]=2;ar++;}
                        if(j!=0&&food[i][j-1]==0){food[i][j-1]=2;ar++;}
                    }
                }
         }
        printf("%d\n",m*n*k-ar*3);
     }
    }
    return 0;
}
