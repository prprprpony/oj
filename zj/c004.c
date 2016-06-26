#include<stdio.h>
int main()
{
    int n,i,s,d,w,l;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&s,&d);
            if(s<0||d<0||(s+d)%2==1||d>s)printf("impossible\n");
            else
            {
                w=(s+d)/2;
                l=(s-d)/2;
                printf("%d %d\n",w,l);
            }
        }
    }
    return 0;
}
