#include<stdio.h>
int main()
{
    int n;
    while((scanf("%d",&n))!=EOF&&n>0)
    {
        if(n<=2)
        {
            printf("%d\n",2*n);
        }
        else
            {
                printf("%d\n",n*n-n+2);
            }
    }
    return 0;
}
