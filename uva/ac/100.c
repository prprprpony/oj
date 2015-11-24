#include<stdio.h>
int main()
{
    int i,j,n,c,cl,mcl,s,e;
    while(scanf("%d%d",&i,&j)!=EOF)
    {
        mcl=0;
        s=(i<j)?i:j;
        e=(i<j)?j:i;
        for(n=s;n<=e;n++)
        {
            c=n;
            cl=1;
            while(c!=1)
            {
                c=(c%2==1)?(c*3+1):(c/2);
                cl++;
            }
            mcl=(cl>mcl)?cl:mcl;
        }
        printf("%d %d %d\n",i,j,mcl);
    }
    return 0;
}
