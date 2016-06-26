#include<math.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
    unsigned int n,m,j,k,p,c,flag,d;
    char i[8];
    while((scanf("%d%d",&n,&m))!=EOF && n>0 && m>n && m<=1000000)
    {
        flag=0;
        for(j=n;j<=m;j++)
        {

           c=0;
           p=floor(log10(j));
           sprintf(i,"%d",j);
           for(k=0;k<=p;k++)
           {
               c+=pow(i[k]-48,p+1);
           }
           if(c==j&&flag==0)
           {
               printf("%d",c);
               flag=1;
           }
           else if(c==j&&flag==1)
           {
               printf(" %d",c);
           }
           for(d=0;d<=7;d++)
           {
               i[d]=0;
           }

        }
        if(flag==0)
        {
             printf("none\n");
        }
        else
        {
             printf("\n");

        }


    }

   return 0;
}
